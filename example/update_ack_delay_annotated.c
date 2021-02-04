#include "picoquic.h"
#include "picoquic_internal.h"
#include "../helpers.h"
#include "bpf.h"

#include "verifier/verifier.h"

protoop_arg_t update_ack_delay (picoquic_cnx_t *cnx) {
    picoquic_packet_context_t* pkt_ctx = (picoquic_packet_context_t *) get_cnx(cnx, AK_CNX_INPUT, 0);
    picoquic_path_t* old_path = (picoquic_path_t *) get_cnx(cnx, AK_CNX_INPUT, 1);
    int64_t rtt_estimate = (int64_t) get_cnx(cnx, AK_CNX_INPUT, 2);
    bool first_estimate = (bool) get_cnx(cnx, AK_CNX_INPUT, 3);
    
    uint64_t rtt_min = get_path(old_path, AK_PATH_RTT_MIN, 0);
    uint64_t ack_delay_local = (rtt_min * ACK_DELAY_MULT) / ACK_DELAY_DIV;
    PROTOOP_PRINTF(cnx, "old_path->rtt_min / 4 = %" PRIu64 "\n", ack_delay_local);
    if (ack_delay_local < 1000) {
        ack_delay_local = 1000;
    } else if (!first_estimate && ack_delay_local > rtt_min) {
        ack_delay_local = rtt_min;
    }
    set_pkt_ctx(pkt_ctx, AK_PKTCTX_ACK_DELAY_LOCAL, ack_delay_local); // should trigger unsat
    PROTOOP_PRINTF(cnx, "pkt_ctx->ack_delay_local = %" PRIu64 "\n", ack_delay_local);
	/* --- end of pluglet code (except the return statement */
    
	// modify cnx
	//cnx->local_parameters.max_packet_size++; // should trigger sat
	
	// modify input0
	//pkt_ctx->nb_retransmit++;
	
	// modify input1
	//old_path->peer_addr_len++;
	//old_path->local_addr_len++;
	
	// modify input2
	//cnx->protoop_inputv[2]++;
	
	// modify input3
	//cnx->protoop_inputv[3] = !cnx->protoop_inputv[3];

    return 0;
}

/* dummy call returning a picoquic_cnx_t, required for seahorn assumptions */
extern picoquic_cnx_t nd();
extern int64_t sh_dummy_int();
extern bool sh_dummy_bool();

/* required to allow assumptions on the pluglet's input cnx 
 * and to build an executable counter-example if needed for debugging
 */
int main(void) {
	// generate cnx
    picoquic_cnx_t cnx = nd(), cnx0;

	// ghosts for pluglet's inputs
	picoquic_packet_context_t pkt_ctx;
	picoquic_path_t path;
	int64_t rtt_estimate;
	bool first_estimate;

	// pluglet return value
	int ret;

	// assume pluglet's @pre
    assume(cnx.protoop_inputc == 4);
	cnx.protoop_inputv[2] = sh_dummy_int();
	cnx.protoop_inputv[3] = sh_dummy_bool();

	// capture cnx before pluglet's call
	assume_cnx_cp(&cnx, &cnx0);

	// capture cnx inputv
	assume_pkt_ctx_cp((picoquic_packet_context_t*) cnx.protoop_inputv[0], &pkt_ctx);
	assume_path_cp((picoquic_path_t*) cnx.protoop_inputv[1], &path);
	rtt_estimate = (int64_t) cnx.protoop_inputv[2];
	first_estimate = (bool) cnx.protoop_inputv[3];

	// pluglet's call
    ret = update_ack_delay(&cnx);
	
	// assert pluglet's @post after call
	assert_pkt_ctx_cmp((picoquic_packet_context_t*) cnx.protoop_inputv[0], &pkt_ctx, ASSERT__PKTCTX__ACK_DELAY_LOCAL); // cnx's inputv[0], should trigger unsat
	//assert_pkt_ctx_cmp((picoquic_packet_context_t*) cnx.protoop_inputv[0], &pkt_ctx, ASSERT__PKTCTX__NONE); // cnx's inputv[0]  // should trigger sat
	assert_path_cmp(&path, (picoquic_path_t*) cnx.protoop_inputv[1]);
	sassert(rtt_estimate == (int64_t) cnx.protoop_inputv[2]);
	sassert(first_estimate == (bool) cnx.protoop_inputv[3]);

	// check all cnx
	assert_cnx_cmp(&cnx, &cnx0); // cnx unchanged
	

    return 0;
}
