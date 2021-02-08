#include "picoquic.h"
#include "picoquic_internal.h"
#include "../helpers.h"
#include "bpf.h"

#include "verifier/verifier.h"

protoop_arg_t is_ack_needed(picoquic_cnx_t *cnx) {
    uint64_t current_time = (uint64_t) get_cnx(cnx, AK_CNX_INPUT, 0);
    picoquic_packet_context_enum pc = (picoquic_packet_context_enum) get_cnx(cnx, AK_CNX_INPUT, 1);
    picoquic_path_t* path_x = (picoquic_path_t*) get_cnx(cnx, AK_CNX_INPUT, 2);

    int ret = 0;
    picoquic_packet_context_t * pkt_ctx = (picoquic_packet_context_t *) get_path(path_x, AK_PATH_PKT_CTX, pc);
    PROTOOP_PRINTF(cnx, "pkt_ctx = %p, pc = %d\n", (protoop_arg_t) pkt_ctx, pc);

    int ack_threshold = get_pkt_ctx(pkt_ctx, AK_PKTCTX_HIGHEST_ACK_SENT) + ACK_THRESHOLD <= get_sack_item(((picoquic_sack_item_t*) get_pkt_ctx(pkt_ctx, AK_PKTCTX_FIRST_SACK_ITEM)), AK_SACKITEM_END_RANGE);
    int ack_time = get_pkt_ctx(pkt_ctx, AK_PKTCTX_HIGHEST_ACK_TIME) + get_pkt_ctx(pkt_ctx, AK_PKTCTX_ACK_DELAY_LOCAL) <= current_time;
    if (ack_threshold) {
        PROTOOP_PRINTF(cnx, "ack_threshold %d <= %d\n", get_pkt_ctx(pkt_ctx, AK_PKTCTX_HIGHEST_ACK_SENT) + ACK_THRESHOLD, get_sack_item(((picoquic_sack_item_t*) get_pkt_ctx(pkt_ctx, AK_PKTCTX_FIRST_SACK_ITEM)), AK_SACKITEM_END_RANGE));
    }
    if (ack_time) {
        PROTOOP_PRINTF(cnx, "ack_time %" PRIx64 " <= %" PRIx64 "\n", get_pkt_ctx(pkt_ctx, AK_PKTCTX_HIGHEST_ACK_TIME) + get_pkt_ctx(pkt_ctx, AK_PKTCTX_ACK_DELAY_LOCAL), current_time);
    }
    if (ack_threshold || ack_time) {
        ret = (int) get_pkt_ctx(pkt_ctx, AK_PKTCTX_ACK_NEEDED);
    }
    if (ret) {
        PROTOOP_PRINTF(cnx, "ack_needed\n");
    }

    // modify cnx
	//cnx->local_parameters.max_packet_size++; // should trigger sat
	//pkt_ctx->nb_retransmit++; // should sat but currenlty unsat since pointers in structures are not yet checked
    
    // modify inputv0
    //cnx->protoop_inputv[0]++;
    
    // modify inputv1
    
    // modify input2
	//path_x->peer_addr_len++; //4m7 sat
	//path_x->local_addr_len++;


    return (protoop_arg_t) ret;
}


int main(void) {
    picoquic_cnx_t cnx, cnx0;

	init__picoquic_cnx_t(&cnx);
	assume_cp__picoquic_cnx_t(&cnx, &cnx0);
	// assume pluglet pre
    assume(cnx.protoop_inputc == 3);

    uint64_t current_time = dummy__uint64_t();
    cnx.protoop_inputv[0] = current_time;

    // TODO
    picoquic_packet_context_enum pc;

    picoquic_path_t path, path0;
    init__picoquic_path_t(&path);
	assume_cp__picoquic_path_t(&path, &path0);
	cnx.protoop_inputv[2] = (protoop_arg_t) &path;

    int ret;

    ret = is_ack_needed(&cnx);

    // TODO : check ret

    sassert(current_time == (uint64_t) cnx.protoop_inputv[0]);
    // TODO : check inputv1 : pc

    // assert the structure copy do not point on the same memory address
    sassert(&path != &path0);
    // assert the pointer in the context is unchanged
    sassert(&path == (picoquic_path_t*) cnx.protoop_inputv[2]);
    // assert the structure pointed by the cnx is left unchanged
    assert_cp__picoquic_path_t((picoquic_path_t*) cnx.protoop_inputv[2], &path0);
    
    sassert(&cnx != &cnx0);
    assert_cp__picoquic_cnx_t(&cnx, &cnx0);

    return 0;
}
