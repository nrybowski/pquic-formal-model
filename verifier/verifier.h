#include "picoquic_internal.h"
#include "seahorn/seahorn.h"

extern void dummy_cp__picoquic_cnx_t(picoquic_cnx_t *src, picoquic_cnx_t *dst);
extern void dummy_cp__picoquic_tp_t(picoquic_tp_t *src, picoquic_tp_t *dst);
extern void dummy_cp__picoquic_connection_id_t(picoquic_connection_id_t *src, picoquic_connection_id_t *dst);
extern void dummy_cp__picoquic_tp_preferred_address_t(picoquic_tp_preferred_address_t *src, picoquic_tp_preferred_address_t *dst);
extern void dummy_cp__picoquic_packet_context_t(picoquic_packet_context_t *src, picoquic_packet_context_t *dst);
extern void dummy_cp__picoquic_sack_item_t(picoquic_sack_item_t *src, picoquic_sack_item_t *dst);
extern void dummy_cp__picoquic_path_t(picoquic_path_t *src, picoquic_path_t *dst);
extern uint8_t dummy__uint8_t();
extern uint16_t dummy__uint16_t();
extern uint64_t dummy__uint64_t();
extern unsigned int dummy__unsigned_int();
extern uint32_t dummy__uint32_t();
extern int dummy__int();
extern size_t dummy__size_t();
extern unsigned long dummy__unsigned_long();
inline void init__picoquic_connection_id_t(picoquic_connection_id_t *param1);
inline void init__picoquic_tp_preferred_address_t(picoquic_tp_preferred_address_t *param1);
inline void init__picoquic_tp_t(picoquic_tp_t *param1);
inline void init__picoquic_cnx_t(picoquic_cnx_t *param1);
inline void init__picoquic_sack_item_t(picoquic_sack_item_t *param1);
inline void init__picoquic_packet_context_t(picoquic_packet_context_t *param1);
inline void init__picoquic_path_t(picoquic_path_t *param1);
inline void assume_cp__picoquic_connection_id_t(picoquic_connection_id_t *src, picoquic_connection_id_t *dst);
inline void assume_cp__picoquic_tp_preferred_address_t(picoquic_tp_preferred_address_t *src, picoquic_tp_preferred_address_t *dst);
inline void assume_cp__picoquic_tp_t(picoquic_tp_t *src, picoquic_tp_t *dst);
inline void assume_cp__picoquic_cnx_t(picoquic_cnx_t *src, picoquic_cnx_t *dst);
inline void assume_cp__picoquic_sack_item_t(picoquic_sack_item_t *src, picoquic_sack_item_t *dst);
inline void assume_cp__picoquic_packet_context_t(picoquic_packet_context_t *src, picoquic_packet_context_t *dst);
inline void assume_cp__picoquic_path_t(picoquic_path_t *src, picoquic_path_t *dst);
inline void assert_cp__picoquic_connection_id_t(picoquic_connection_id_t *param1, picoquic_connection_id_t *param2);
inline void assert_cp__picoquic_tp_preferred_address_t(picoquic_tp_preferred_address_t *param1, picoquic_tp_preferred_address_t *param2);
inline void assert_cp__picoquic_tp_t(picoquic_tp_t *param1, picoquic_tp_t *param2);
inline void assert_cp__picoquic_cnx_t(picoquic_cnx_t *param1, picoquic_cnx_t *param2);
inline void assert_cp__picoquic_sack_item_t(picoquic_sack_item_t *param1, picoquic_sack_item_t *param2);
inline void assert_cp__picoquic_packet_context_t(picoquic_packet_context_t *param1, picoquic_packet_context_t *param2);
inline void assert_cp__picoquic_path_t(picoquic_path_t *param1, picoquic_path_t *param2);
