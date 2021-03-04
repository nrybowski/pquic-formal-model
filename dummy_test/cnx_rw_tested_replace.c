#include "picoquic.h"
#include "picoquic_internal.h"
#include "../helpers.h"
#include "bpf.h"

protoop_arg_t update_ack_delay(picoquic_cnx_t *cnx) {
    PROTOOP_PRINTF(cnx, "Entering pluglet\t");

    PROTOOP_PRINTF(cnx, "Before %u\t", (uint64_t) get_cnx(cnx, AK_CNX_INPUT, 0));
    
    my_memset(&cnx->protoop_inputv[0], 0, sizeof(void*));
    
    PROTOOP_PRINTF(cnx, "After %u\t", (uint64_t) get_cnx(cnx, AK_CNX_INPUT, 0));
    
    PROTOOP_PRINTF(cnx, "Exiting pluglet\n");

    return (protoop_arg_t) 1;
}
