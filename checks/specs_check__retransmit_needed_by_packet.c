#include "../verifier/verifier.h"

protoop_arg_t retransmit_needed_by_packet(picoquic_cnx_t *cnx);
int main()
{
  picoquic_cnx_t cnx;
  picoquic_cnx_t cnx0;
  init__picoquic_cnx_t(&cnx);
  cnx.protoop_inputc = 3;
  assume_cp__picoquic_cnx_t(&cnx, &cnx0);
  picoquic_packet_t p;
  picoquic_packet_t p0;
  init__picoquic_packet_t(&p);
  assume_cp__picoquic_packet_t(&p, &p0);
  cnx.protoop_inputv[0] = (protoop_arg_t) (&p);
  uint64_t current_time;
  current_time = dummy__uint64_t();
  cnx.protoop_inputv[1] = current_time;
  int timer_based;
  timer_based = dummy__int();
  cnx.protoop_inputv[2] = timer_based;
  retransmit_needed_by_packet(&cnx);
  sassert((&p) == ((picoquic_packet_t *) cnx.protoop_inputv[0]));
  assert_cp__picoquic_packet_t((picoquic_packet_t *) cnx.protoop_inputv[0], &p0, ASSERT_NONE);
  sassert(current_time == ((uint64_t) cnx.protoop_inputv[1]));
  sassert(timer_based == ((int) cnx.protoop_inputv[2]));
  assert_cp__picoquic_cnx_t(&cnx, &cnx0, ASSERT_NONE);
#ifdef SASSERT_FALSE
  sassert(0);
#endif
  return 0;
}

