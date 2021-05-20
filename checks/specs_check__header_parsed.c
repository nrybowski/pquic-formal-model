#include "../verifier/verifier.h"

protoop_arg_t header_parsed(picoquic_cnx_t *cnx);
int main()
{
  picoquic_cnx_t cnx;
  picoquic_cnx_t cnx0;
  init__picoquic_cnx_t(&cnx);
  cnx.protoop_inputc = 3;
  assume_cp__picoquic_cnx_t(&cnx, &cnx0);
  picoquic_packet_header ph;
  picoquic_packet_header ph0;
  init__picoquic_packet_header(&ph);
  assume_cp__picoquic_packet_header(&ph, &ph0);
  cnx.protoop_inputv[0] = (protoop_arg_t) (&ph);
  picoquic_path_t path;
  picoquic_path_t path0;
  init__picoquic_path_t(&path);
  assume_cp__picoquic_path_t(&path, &path0);
  cnx.protoop_inputv[1] = (protoop_arg_t) (&path);
  size_t length;
  length = dummy__size_t();
  cnx.protoop_inputv[2] = length;
  header_parsed(&cnx);

  sassert((&ph) == ((picoquic_packet_header *) cnx.protoop_inputv[0]));
  assert_cp__picoquic_packet_header((picoquic_packet_header *) cnx.protoop_inputv[0], &ph0, ASSERT_NONE);
  sassert((&path) == ((picoquic_path_t *) cnx.protoop_inputv[1]));
  assert_cp__picoquic_path_t((picoquic_path_t *) cnx.protoop_inputv[1], &path0, ASSERT_NONE);
  sassert(length == ((size_t) cnx.protoop_inputv[2]));
  assert_cp__picoquic_cnx_t(&cnx, &cnx0, ASSERT_NONE);

#ifdef SASSERT_FALSE
  sassert(0);
#endif
  return 0;
}

