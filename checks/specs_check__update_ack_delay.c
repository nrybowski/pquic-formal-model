#include "../verifier/verifier.h"

protoop_arg_t update_ack_delay(picoquic_cnx_t *cnx);
int main()
{
  picoquic_cnx_t cnx;
  picoquic_cnx_t cnx0;
  init__picoquic_cnx_t(&cnx);
  cnx.protoop_inputc = 4;
  assume_cp__picoquic_cnx_t(&cnx, &cnx0);

  picoquic_packet_context_t pkt_ctx;
  picoquic_packet_context_t pkt_ctx0;
  init__picoquic_packet_context_t(&pkt_ctx);
  assume_cp__picoquic_packet_context_t(&pkt_ctx, &pkt_ctx0);
  cnx.protoop_inputv[0] = (protoop_arg_t) (&pkt_ctx);

  picoquic_path_t old_path;
  picoquic_path_t old_path0;
  init__picoquic_path_t(&old_path);
  assume_cp__picoquic_path_t(&old_path, &old_path0);
  cnx.protoop_inputv[1] = (protoop_arg_t) (&old_path);

  int64_t rtt_estimate;
  rtt_estimate = dummy__int64_t();
  cnx.protoop_inputv[2] = rtt_estimate;

  bool first_estimate;
  first_estimate = dummy__bool();
  cnx.protoop_inputv[3] = first_estimate;

  update_ack_delay(&cnx);

  sassert((&pkt_ctx) == ((picoquic_packet_context_t *) cnx.protoop_inputv[0]));
  assert_cp__picoquic_packet_context_t((picoquic_packet_context_t *) cnx.protoop_inputv[0], &pkt_ctx0, ASSERT_PICOQUIC_PACKET_CONTEXT_T__ACK_DELAY_LOCAL);

  sassert((&old_path) == ((picoquic_path_t *) cnx.protoop_inputv[1]));
  assert_cp__picoquic_path_t((picoquic_path_t *) cnx.protoop_inputv[1], &old_path0, ASSERT_NONE);

  sassert(rtt_estimate == ((int64_t) cnx.protoop_inputv[2]));
  sassert(first_estimate == ((bool) cnx.protoop_inputv[3]));

  assert_cp__picoquic_cnx_t(&cnx, &cnx0, ASSERT_NONE);
  
  //search_unsat_bug();
#ifdef SASSERT_FALSE
  sassert(0);
#endif

  return 0;
}

