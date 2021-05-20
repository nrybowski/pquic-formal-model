#include "../verifier/verifier.h"

extern picoquic_packet_context_enum dummy__picoquic_packet_context_enum();

protoop_arg_t update_rtt(picoquic_cnx_t *cnx);
int main()
{
  picoquic_cnx_t cnx;
  picoquic_cnx_t cnx0;
  init__picoquic_cnx_t(&cnx);
  cnx.protoop_inputc = 5;
  assume_cp__picoquic_cnx_t(&cnx, &cnx0);
  uint64_t largest;
  largest = dummy__uint64_t();
  cnx.protoop_inputv[0] = largest;
  uint64_t current_time;
  current_time = dummy__uint64_t();
  cnx.protoop_inputv[1] = current_time;
  uint64_t ack_delay;
  ack_delay = dummy__uint64_t();
  cnx.protoop_inputv[2] = ack_delay;
  picoquic_packet_context_enum pc;
  pc = dummy__picoquic_packet_context_enum();
  cnx.protoop_inputv[3] = pc;
  picoquic_path_t path_x;
  picoquic_path_t path_x0;
  init__picoquic_path_t(&path_x);
  assume_cp__picoquic_path_t(&path_x, &path_x0);
  cnx.protoop_inputv[4] = (protoop_arg_t) (&path_x);
  update_rtt(&cnx);
  sassert(largest == ((uint64_t) cnx.protoop_inputv[0]));
  sassert(current_time == ((uint64_t) cnx.protoop_inputv[1]));
  sassert(ack_delay == ((uint64_t) cnx.protoop_inputv[2]));
  sassert(pc == ((picoquic_packet_context_enum) cnx.protoop_inputv[3]));
  sassert((&path_x) == ((picoquic_path_t *) cnx.protoop_inputv[4]));
  assert_cp__picoquic_path_t((picoquic_path_t *) cnx.protoop_inputv[4], &path_x0, ASSERT_NONE);
  assert_cp__picoquic_cnx_t(&cnx, &cnx0, ASSERT_PICOQUIC_CNX_T__LATEST_PROGRESS_TIME);
#ifdef SASSERT_FALSE
  sassert(0);
#endif
  return 0;
}

