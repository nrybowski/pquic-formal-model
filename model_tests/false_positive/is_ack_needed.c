#include "picoquic.h"
#include "picoquic_internal.h"
#include "getset.h"

protoop_arg_t is_ack_needed(picoquic_cnx_t *cnx) {
    uint64_t current_time = (uint64_t) get_cnx(cnx, AK_CNX_INPUT, 0);
    picoquic_packet_context_enum pc = (picoquic_packet_context_enum) get_cnx(cnx, AK_CNX_INPUT, 1);
    picoquic_path_t* path_x = (picoquic_path_t*) get_cnx(cnx, AK_CNX_INPUT, 2);

    return (protoop_arg_t) 0;
}
