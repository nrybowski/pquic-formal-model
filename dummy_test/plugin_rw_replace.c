#include "picoquic.h"
#include "picoquic_internal.h"
#include "../helpers.h"
#include "bpf.h"

protoop_arg_t update_ack_delay (picoquic_cnx_t *cnx) {
    PROTOOP_PRINTF(cnx, "Entering pluglet\t");

    // allocate a ptr on the host's heap
    protoop_plugin_t **tmp = (protoop_plugin_t**) my_malloc(cnx, sizeof(void*));

    // copy address of ptr to plugin structure in the context
    tmp = my_memcpy(tmp, &cnx->current_plugin, sizeof(void *));

    // print plugin's name
    PROTOOP_PRINTF(cnx, "Plugin name:<%s>\t", (protoop_arg_t) (*tmp)->name);

    // allocate a ptr on the host's heap
    char **tmp2 = (char**) my_malloc(cnx, sizeof(void*));

    // copy the address of the ptr of the path's string
    tmp2 = my_memcpy(tmp2, &((*tmp)->path), sizeof(void*));

    // print manifest's path of the plugin
    PROTOOP_PRINTF(cnx, "Path:<%s>\t", (protoop_arg_t) *tmp2);

    //PROTOOP_PRINTF(cnx, "Path:<%s>\t", (protoop_arg_t) (*tmp)->path);
    //PROTOOP_PRINTF(cnx, "Path:<%s>\t", (protoop_arg_t) *(&((*tmp)->path)));

    PROTOOP_PRINTF(cnx, "Before return\n");
 
    return 0;
}
