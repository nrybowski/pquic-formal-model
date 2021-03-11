## Issues
1. Data structures (Linked List, Double Linked List, Queue, picoquic Hashtable, Hashmap)
2. Function references
3. Unknown buffer size (`void* ctx`, `char *`, ...)
> The size of some buffers like `uint8_t* base` ine `st_ptls_buffer_t` are provided by another field of the structure.
4. Pointers to structures / Structures containing one of more if the above
(5. Void pointers to unknown data, might be buffer or fun ref)

## Structures containing only verifiable fields
- `st_picoquic_connection_id_t`
- `st_picoquic_tp_preferred_address_t`
- `st_ptls_buffer_t` (see `include/picotls.h`)
	- `uint8_t *base` : size of buffer given in `capacity` field.

## Structures containing not yet verifiable fields

### `st_picoquic_tp_t`
- `char* supported_plugins` : size ?
- `char* plugins_to_inject` : size ?

### `st_picoquic_cnx_id_t`
- `picoquic_cnx_t* cnx` : contains a lot of unverifiable pointers.
- `struct st_picoquic_cnx_id_t* next_cnx_id` : LL 

### `st_picoquic_net_id_t`
- `struct sockaddr_storage saddr` : from libc, TODO : check structure
- `picoquic_cnx_t* cnx` : contains a lot of unverifiable pointers.
- `struct st_picoquic_net_id_t* next_net_id` : LL

### `st_picoquic_sack_item_t`
- `struct st_picoquic_sack_item_t* next_sack` : LL

### `_picoquic_stream_data`
- `struct _picoquic_stream_data* next_stream_data` : LL
 
### `_picoquic_stream_head`
- `struct _picoquic_stream_head* next_stream` : LL
- `picoquic_stream_data* stream_data` : LL, see `_picoquic_stream_data`
- `picoquic_stream_data* send_queue` : LL, see `_picoquic_stream_data`
- `void* app_stream_ctx` : size ?
- `picoquic_sack_item_t first_sack_item` : LL, see `st_picoquic_sack_item_t`

### `picoquic_crypto_context_t`
- `void* aead_encrypt` : size ?
- `void* aead_decrypt` : size ?
- `void* hp_enc` : size ?
- `void* hp_dec` : size ?

### `st_picoquic_congestion_algorithm_t`
- `picoquic_congestion_algorithm_init alg_init` : fun ref
- `picoquic_congestion_algorithm_notify alg_notify` : fun ref
- `picoquic_congestion_algorithm_delete alg_delete` : fun ref

### `st_plugin_struct_metadata_t`
- `UT_hash_handle hh` : hashmap struct with DLL, see `picoquic/uthash.h`

### `plugin_memory_manager`
- `void* (*	my_malloc)(protoop_plugin_t *p, unsigned int size)` : fun ref
- `void (* my_free)(protoop_plugin_t *p, void *ptr)` : fun ref 
- `void* (* my_realloc)(protoop_plugin_t *p, void *ptr, unsigned int size)` : fun ref
- `void* ctx` : size ?

### `protoop_plugin_t`
- `UT_hash_handle hh` : hashmap struct with DLL, see `picoquic/uthash.h`
- `char* path` : size ?
- `queue_t* block_queue_cc` : Queue
- `queue_t* block_queue_non_cc` : Queue
- `plugin_memory_manager_t memory_manager` : fun refs, see `plugin_memory_manager`

### `st_picoquic_packet_plugin_frame_t`
- `struct st_picoquic_packet_plugin_frame_t* next` : LL
- `protoop_plugin_t* plugin` : DLL and queues, see `protoop_plugin_t`
- `reserve_frame_slot_t* rfs` :

### `st_picoquic_packet_t`
- `struct st_picoquic_packet_t* previous_packet` and `struct st_picoquic_packet_t* next_packet` : DLL
- `struct st_picoquic_path_t* send_path` : see `st_picoquic_path_t`.
- `picoquic_packet_plugin_frame_t* plugin_frames` : LL, DLL and queues, see `st_picoquic_packet_plugin_frame_t`
- `plugin_struct_metadata_t* metadata` : contains hashmap, see `st_plugin_struct_metadata_t* metadata`

### `st_picoquic_packet_context_t`
- `picoquic_sack_item_t first_sack_item` : LL, see `st_picoquic_sack_item_t`
- `picoquic_packet_t * 	retransmit_newest` : contains DLL, see `st_picoquic_packet_t`
- `picoquic_packet_t * 	retransmit_oldest` : contains DLL, see `st_picoquic_packet_t`
- `picoquic_packet_t * 	retransmitted_newest` : contains DLL, see `st_picoquic_packet_t`
- `picoquic_packet_t * 	retransmitted_oldest` : contains DLL, see `st_picoquic_packet_t`
- `plugin_struct_metadata_t* metadata` : contains hashmap, see `st_plugin_struct_metadata_t* metadata`

### `st_picoquic_path_t`
- `void* congestion_alg_state` : ptr to ?
- `picoquic_packet_context_t pkt_ctx [picoquic_nb_packet_context]` : array of structs containing LL, see `st_picoquic_packet_context_t`
- `plugin_struct_metadata_t* metadata` : contains hashmap, see `st_plugin_struct_metadata_t* metadata`

### `st_plugin_req_pid_t`
- [?] `uint8_t* data` : length in received_length ?

### `st_plugin_request_t`
- `plugin_req_pid_t elems [MAX_PLUGIN]` : see `st_plugin_req_pid_t`

### `protoop_id`
- `char* id` : size ?

### `pluglet` (picoquic/ubpf.h)
- `void* vm` : void ptr
- `protoop_plugin_t* p` : see `protoop_plugin_t`

### `observer_node`
- `pluglet_t* observer` : see `pluglet`
- `struct observer_node* next` : LL

### `protocol_operation_param_struct_t`
- `param_id_t param` : TODO
- `protocol_operation core` : TODO
- `pluglet_t* replace` : see `pluglet`
- `observer_node_t* pre` : see `observer_node`
- `observer_node_t* post` : see `observer_node`
- `UT_hash_handle hh` : hashmap struct with DLL, see `picoquic/uthash.h`

### `st_protocol_operation_struct_t`
- `protoop_id_t` : see `protoo_id`
- `protocol_operation_param_struct_t* params` : see `protocol_operation_param_struct_t`
- `UT_hash_handle hh` : hashmap struct with DLL, see `picoquic/uthash.h`

### `st_picoquic_stored_ticket_t`
- `struct st_picoquic_stored_ticket_t* next_ticket` : LL
- `char* sni` : size ?
- `char* alpn` : size ?
- `uint8_t* ticket` : size ?

### `st_picoquic_stateless_packet_t`
- `struct st_picoquic_stateless_packet_t* next_packet` : LL

### `st_plugin_fname_t`
- `char* plugin_name` : size ?
- `char* plugin_path` : size ?

### `st_plugin_list_t`
- `plugin_fname_t elems [MAX_PLUGIN]` : see `st_plugin_fname_t` 

### `st_picoquic_quic_t`
- `void* F_log` : void ptr
- `void* F_tls_secrets` : void ptr
- `void* tls_master_ctx`: void ptr
- `void* default_callback_ctx` : void ptr
- `char const* default_alpn` : size ?
- `uint64_t* p_simulated_time` : size ?
- `char const* ticket_file_name` : size ?
- `picoquic_stored_ticket_t* p_first_ticket` : see `st_picoquic_stored_ticket_t`
- `picoquic_stateless_packet_t* pending_stateless_packet` : LL
- `picoquic_congestion_algorithm_t const* default_congestion_alg` : fun refs, see `st_picoquic_congestion_algorithm_t`
- `struct st_picoquic_cnx_t* cnx_list` : see `st_picoquic_cnx_t`
- `struct st_picoquic_cnx_t* cnx_last`: see `st_picoquic_cnx_t`
- `struct st_picoquic_cnx_t* cnx_wake_first` : see `st_picoquic_cnx_t`
- `struct st_picoquic_cnx_t* cnx_wake_last` : see `st_picoquic_cnx_t`
- `picohash_table* table_cnx_by_id` : hashtable, see `picoquic/picohash.h`
- `picohash_table* table_cnx_by_net` : hashtable, see `picoquic/picohash.h`
- `void* cnx_id_callback_ctx` : size ?
- `void* aead_encrypt_ticket_ctx` : size ?
- `void* aead_decrypt_ticket_ctx` : size ?
- `void* verify_certificate_ctx` : size ?
- `picoquic_tp_t* default_tp` : see `st_picoquic_tp_t`
- `void* fuzz_ctx` : size ?
- `queue_t* cached_plugins_queue` : Queue
- `char* plugin_store_path` : size ?
- `plugin_list_t supported_plugins` : see `st_plugin_list_t` 
- `plugin_list_t plugins_to_inject` : see `st_plugin_list_t`
- `plugin_list_t local_plugins` : see `st_plugin_list_t`

### `st_picoquic_cnx_t`
- [x] `picoquic_quic_t* quic` : internal QUIC context (is accessible in uBPF VM ?) ?, see `st_picoquic_quic_t`
- [x] `struct st_picoquic_cnx_t* next_in_table` and  `struct st_picoquic_cnx_t* previous_in_table` : double LL of `picoquic_cnx_t`
- [x] `struct st_picoquic_cnx_id_t*	first_cnx_id` : LL + pointer to `picoquic_cnx_t`
- [x] `struct st_picoquic_net_id_t*	first_net_id` : LL + pointer to `picoquic_cnx_t`
- [x] `picoquic_tp_t local_parameters` : see `st_picoquic_tp_t`
- [x] `picoquic_tp_t remote_parameters` : see `st_picoquic_tp_t`
- [x] `void* callback_ctx` : size ?
- [x] `struct st_picoquic_cnx_t* next_by_wake_time` and `struct st_picoquic_cnx_t* previous_by_wake_time` : double LL of `picoquic_cnx_t`
- [x] `void* tls_ctx` : size ?
- [?] `struct st_ptls_buffer_t* tls_sendbuf` : see `st_ptls_buffer_t`
- [x] `picoquic_stream_head tls_stream [PICOQUIC_NUMBER_OF_EPOCHS]` : array of LL, see `_picoquic_stream_head`.
- [x] `picoquic_crypto_context_t crypto_context [PICOQUIC_NUMBER_OF_EPOCHS]` : ptr to funs, see `picoquic_crypto_context_t` 
- [x] `picoquic_congestion_algorithm_t const* congestion_alg` : fun refs
- [x] `picoquic_stream_head* first_stream` : LL, see ` _picoquic_stream_head`.
- [x] `picoquic_path_t** path`: buffer of path pointers, see `st_picoquic_path_t`
- [X] `queue_t* reserved_frames` : Queue
- [X] `queue_t* retry_frames` : Queue
- [X] `queue_t*	rtx_frames [picoquic_nb_packet_context]` : Array of queues
- [x] `protoop_plugin_t* first_drr` : see `protoop_plugin`
- [x] `plugin_request_t pids_to_request` : see `st_plugin_request_t`
- [x] `picoquic_stream_head* first_plugin_stream` : LL, see ` _picoquic_stream_head`.
- [x] `protocol_operation_struct_t* ops` : see `st_protocol_operation_struct_t`
- [x] `protoop_plugin_t* plugins` : see `protoop_plugin`
- [x] `plugin_struct_metadata_t* metadata` : contains, hashmap, see `st_plugin_struct_metadat`
- [x] `protocol_operation_struct_t* current_protoop` : see `st_protocol_operation_struct_t`
- [x] `protoop_plugin_t* current_plugin` : see `protoop_plugin`
- [x] `protoop_plugin_t* previous_plugin_in_replace` : see `protoop_plugin`
