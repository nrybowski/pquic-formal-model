#include "picoquic.h"
#include "picoquic_internal.h"
#include "../helpers.h"
#include "bpf.h"

#include "verifier/verifier.h"

//#pragma clang poison get_path

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
	//old_path->peer_addr_len++; //1m30 sat
	//old_path->local_addr_len++;
	
	// modify input2
	//cnx->protoop_inputv[2]++;
	
	// modify input3
	//cnx->protoop_inputv[3] = !cnx->protoop_inputv[3];

    return 0;
}

/* dummy call returning a picoquic_cnx_t, required for seahorn assumptions */
extern picoquic_cnx_t nd();
extern int64_t dummy__int64_t();
extern bool dummy__bool();

/* required to allow assumptions on the pluglet's input cnx 
 * and to build an executable counter-example if needed for debugging
 */
int main(void) {
	// generate cnx
 	// assume pluglet's @pre
  	picoquic_cnx_t cnx = nd(), cnx0;

	// initialize cnx
	init__picoquic_cnx_t(&cnx);
	assume_cp__picoquic_cnx_t(&cnx, &cnx0);
	// assume pluglet pre
	assume(cnx.protoop_inputc == 4);

	// initialize inputv0
	picoquic_packet_context_t pkt_ctx, pkt_ctx0;
	init__picoquic_packet_context_t(&pkt_ctx);
	assume_cp__picoquic_packet_context_t(&pkt_ctx, &pkt_ctx0);
	cnx.protoop_inputv[0] = (protoop_arg_t) &pkt_ctx;

	// initialize inputv1
	picoquic_path_t path, path0;
	init__picoquic_path_t(&path);
	assume_cp__picoquic_path_t(&path, &path0);
	cnx.protoop_inputv[1] = (protoop_arg_t) &path;
   	
	// initialize inputv2
	int64_t rtt_estimate  = dummy__int64_t();
	cnx.protoop_inputv[2] = rtt_estimate;

	// initialize inputv3
	bool first_estimate = dummy__bool();
	cnx.protoop_inputv[3] = first_estimate; 

	// pluglet return value
	int ret;
	
	// pluglet's call
    ret = update_ack_delay(&cnx);
	
	// assert pluglet's @post after call
	sassert(&pkt_ctx != &pkt_ctx0);
	sassert(&pkt_ctx == (picoquic_packet_context_t*) cnx.protoop_inputv[0]);
	assert_cp__picoquic_packet_context_t((picoquic_packet_context_t*) cnx.protoop_inputv[0], &pkt_ctx0);
	//assert_pkt_ctx_cmp((picoquic_packet_context_t*) cnx.protoop_inputv[0], &pkt_ctx, ASSERT__PKTCTX__ACK_DELAY_LOCAL); // cnx's inputv[0], should trigger unsat
	//assert_pkt_ctx_cmp((picoquic_packet_context_t*) cnx.protoop_inputv[0], &pkt_ctx, ASSERT__PKTCTX__NONE); // cnx's inputv[0]  // should trigger sat
	
	sassert(&path != &path0);
	sassert(&path == (picoquic_path_t*) cnx.protoop_inputv[1]);
	assert_cp__picoquic_path_t((picoquic_path_t*) cnx.protoop_inputv[1], &path0);

	sassert(rtt_estimate == (int64_t) cnx.protoop_inputv[2]);
	sassert(first_estimate == (bool) cnx.protoop_inputv[3]);

	// check all cnx
	sassert(&cnx != &cnx0);
	assert_cp__picoquic_cnx_t(&cnx, &cnx0); // cnx unchanged
	
    return 0;
}
