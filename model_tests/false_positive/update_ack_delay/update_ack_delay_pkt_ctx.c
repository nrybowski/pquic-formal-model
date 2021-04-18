#include "picoquic.h"
#include "picoquic_internal.h"
#include "getset.h"

protoop_arg_t update_ack_delay (picoquic_cnx_t *cnx) {
    picoquic_packet_context_t* pkt_ctx = (picoquic_packet_context_t *) get_cnx(cnx, AK_CNX_INPUT, 0);
    picoquic_path_t* old_path = (picoquic_path_t *) get_cnx(cnx, AK_CNX_INPUT, 1);
    int64_t rtt_estimate = (int64_t) get_cnx(cnx, AK_CNX_INPUT, 2);
    bool first_estimate = (bool) get_cnx(cnx, AK_CNX_INPUT, 3);

    set_pkt_ctx(pkt_ctx, AK_PKTCTX_ACK_DELAY_LOCAL, 1);

    return 0;
}
