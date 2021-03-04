#include "picoquic.h"
#include "picoquic_internal.h"
#include "../helpers.h"
#include "bpf.h"

protoop_arg_t is_ack_needed(picoquic_cnx_t *cnx) {
    PROTOOP_PRINTF(cnx, "Entering pluglet\t");

    // creates a ptr on the host heap ?
    char **tmp  = (char **) my_malloc(cnx, sizeof(void*));

    // copy the address of the sni field from the cnx
    my_memcpy(tmp, &cnx->sni, sizeof(void*));

    // replace the second char of the sni by 'b'
    my_memset(*tmp+1, 'b', sizeof(char));

    // read the content of the sni field from the cnx, which is supposed to be
    // unreachable since there is no getter to access this field
    PROTOOP_PRINTF(cnx, "SNI : %s\t", (protoop_arg_t) *tmp);

    PROTOOP_PRINTF(cnx, "Exiting pluglet\n");

    return (protoop_arg_t) 1;
}
