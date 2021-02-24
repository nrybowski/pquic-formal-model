#include "verifier/verifier.h"

extern picoquic_packet_context_enum nd();

protoop_arg_t is_ack_needed(picoquic_cnx_t *cnx);
int main()
{
  picoquic_cnx_t cnx;
  picoquic_cnx_t cnx0;
  init__picoquic_cnx_t(&cnx);
  assume_cp__picoquic_cnx_t(&cnx, &cnx0);
  assume(cnx.protoop_inputc == 3);
  uint64_t current_time;
  current_time = dummy__uint64_t();
  cnx.protoop_inputv[0] = current_time;
  picoquic_packet_context_enum pc;
  pc = nd();
  cnx.protoop_inputv[1] = (protoop_arg_t) pc;
  picoquic_path_t path_x;
  picoquic_path_t path_x0;
  init__picoquic_path_t(&path_x);
  assume_cp__picoquic_path_t(&path_x, &path_x0);
  cnx.protoop_inputv[2] = (protoop_arg_t) (&path_x);
  is_ack_needed(&cnx);
  sassert(current_time == ((uint64_t) cnx.protoop_inputv[0]));
  sassert(pc == ((picoquic_packet_context_enum) cnx.protoop_inputv[1]));
  sassert((&path_x) == ((picoquic_path_t *) cnx.protoop_inputv[2]));
  assert_cp__picoquic_path_t((picoquic_path_t *) cnx.protoop_inputv[2], &path_x0, ASSERT_NONE);
  assert_cp__picoquic_cnx_t(&cnx, &cnx0, ASSERT_NONE);
  return 0;
}

