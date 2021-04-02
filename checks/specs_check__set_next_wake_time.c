#include "../verifier/verifier.h"

protoop_arg_t set_next_wake_time(picoquic_cnx_t *cnx);
int main()
{
  picoquic_cnx_t cnx;
  picoquic_cnx_t cnx0;
  init__picoquic_cnx_t(&cnx);
  cnx.protoop_inputc = 1;
  assume_cp__picoquic_cnx_t(&cnx, &cnx0);
  uint64_t current_time;
  current_time = dummy__uint64_t();
  cnx.protoop_inputv[0] = current_time;
  set_next_wake_time(&cnx);
  sassert(current_time == ((uint64_t) cnx.protoop_inputv[0]));
  assert_cp__picoquic_cnx_t(&cnx, &cnx0, ASSERT_PICOQUIC_CNX_T__WAKE_NOW);
  return 0;
}

