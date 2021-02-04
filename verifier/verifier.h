#include "picoquic_internal.h"
#include "seahorn/seahorn.h"

extern void cp_cnx(picoquic_cnx_t* cnx1, picoquic_cnx_t* cnx2);
extern void cp_pkt_ctx(picoquic_packet_context_t* pc1, picoquic_packet_context_t* pc2);
extern void cp_tp(picoquic_tp_t* tp1, picoquic_tp_t* tp2);
extern void cp_path(picoquic_path_t* p1, picoquic_path_t* p2);


/*	from picoquic/getset.c:set_pkt_ctx, struct and pointers currently not modifiable
*	so currently do not provide switch to skip their check
*/
#define ASSERT__PKTCTX__NONE 0x0
#define ASSERT__PKTCTX__SEND_SEQUENCE 0x1
#define ASSERT__PKTCTX__TIME_STAMP_LARGEST_RECEIVED 0x2
#define ASSERT__PKTCTX__HIGHEST_ACK_SENT 0x4
#define ASSERT__PKTCTX__HIGHEST_ACK_TIME 0x8
#define ASSERT__PKTCTX__ACK_DELAY_LOCAL 0x16
// ...


inline void assume_cp_tp(picoquic_tp_t* tp1, picoquic_tp_t* tp2);
inline void assume_cnx_cp(picoquic_cnx_t* cnx1, picoquic_cnx_t* cnx2);
inline void assume_pkt_ctx_cp(picoquic_packet_context_t* pc1, picoquic_packet_context_t* pc2);
inline void assume_path_cp(picoquic_path_t* p1, picoquic_path_t* p2);

inline void assert_tp_cmp(picoquic_tp_t* tp1, picoquic_tp_t* tp2);
inline void assert_cnx_cmp(picoquic_cnx_t* cnx0, picoquic_cnx_t* cnx);
inline void assert_pkt_ctx_cmp(picoquic_packet_context_t* pc1, picoquic_packet_context_t* pc2, uint64_t flags);
inline void assert_path_cmp(picoquic_path_t* p1, picoquic_path_t* p2);
