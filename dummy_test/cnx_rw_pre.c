#include "picoquic.h"
#include "picoquic_internal.h"
#include "../helpers.h"
#include "bpf.h"

protoop_arg_t test(picoquic_cnx_t *cnx) {
    PROTOOP_PRINTF(cnx, "Entering pre\t");
    
    char **tmp  = (char **) my_malloc(cnx, sizeof(void*));
    my_memcpy(tmp, &cnx->sni, sizeof(void*));
    my_memset(*tmp+1, 'b', sizeof(char));
    PROTOOP_PRINTF(cnx, "SNI : %s\t", (protoop_arg_t) *tmp);

    PROTOOP_PRINTF(cnx, "Exiting pre\n");

    return (protoop_arg_t) 1;
}
