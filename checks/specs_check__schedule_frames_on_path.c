#include "../verifier/verifier.h"

void *calloc (size_t __nmemb, size_t __size)
{
    char* r = malloc(__nmemb*__size);
    for (int i = 0 ; i < __nmemb*__size ; i++)
        r[i] = 0;
    return r;
}

protoop_arg_t schedule_frames_on_path(picoquic_cnx_t *cnx);
int main()
{
  picoquic_cnx_t cnx;
  picoquic_cnx_t cnx0;
  init__picoquic_cnx_t(&cnx);
  cnx.protoop_inputc = 6;
  assume_cp__picoquic_cnx_t(&cnx, &cnx0);
  picoquic_packet_t packet;
  picoquic_packet_t packet0;
  init__picoquic_packet_t(&packet);
  assume_cp__picoquic_packet_t(&packet, &packet0);
  cnx.protoop_inputv[0] = (protoop_arg_t) (&packet);
  size_t send_buffer_max;
  send_buffer_max = dummy__size_t();
  cnx.protoop_inputv[1] = send_buffer_max;
  uint64_t current_time;
  current_time = dummy__uint64_t();
  cnx.protoop_inputv[2] = current_time;
  picoquic_packet_t retransmit_p;
  picoquic_packet_t retransmit_p0;
  init__picoquic_packet_t(&retransmit_p);
  assume_cp__picoquic_packet_t(&retransmit_p, &retransmit_p0);
  cnx.protoop_inputv[3] = (protoop_arg_t) (&retransmit_p);
  picoquic_path_t from_path;
  picoquic_path_t from_path0;
  init__picoquic_path_t(&from_path);
  assume_cp__picoquic_path_t(&from_path, &from_path0);
  cnx.protoop_inputv[4] = (protoop_arg_t) (&from_path);
  //char reason;
  //char reason0;
  //init__char(&reason);
  //assume_cp__char(&reason, &reason0);
  //cnx.protoop_inputv[5] = (protoop_arg_t) (&reason);
  schedule_frames_on_path(&cnx);
  sassert((&packet) == ((picoquic_packet_t *) cnx.protoop_inputv[0]));
  //assert_cp__picoquic_packet_t((picoquic_packet_t *) cnx.protoop_inputv[0], &packet0, ASSERT_PICOQUIC_PACKET_T__LENGTH | ASSERT_PICOQUIC_PACKET_T__IS_PURE_ACK | ASSERT_PICOQUIC_PACKET_T__SEND_TIME | ASSERT_PICOQUIC_PACKET_T__CHECKSUM_OVERHEAD | ASSERT_PICOQUIC_PACKET_T__TYPE | ASSERT_PICOQUIC_PACKET_T__OFFSET | ASSERT_PICOQUIC_PACKET_T__SEQUENCE_NUMBER | ASSERT_PICOQUIC_PACKET_T__SEND_TIME | ASSERT_PICOQUIC_PACKET_T__IS_MTU_PROBE | ASSERT_PICOQUIC_PACKET_T__IS_CONGESTION_CONTROLLED | ASSERT_PICOQUIC_PACKET_T__CONTAINS_CRYPTO | ASSERT_PICOQUIC_PACKET_T__HAS_HANDSHAKE_DONE);
  assert_cp__picoquic_packet_t((picoquic_packet_t *) cnx.protoop_inputv[0], &packet0, ASSERT_PICOQUIC_PACKET_T__LENGTH | ASSERT_PICOQUIC_PACKET_T__IS_PURE_ACK | ASSERT_PICOQUIC_PACKET_T__SEND_TIME | ASSERT_PICOQUIC_PACKET_T__CHECKSUM_OVERHEAD | ASSERT_PICOQUIC_PACKET_T__OFFSET | ASSERT_PICOQUIC_PACKET_T__SEQUENCE_NUMBER | ASSERT_PICOQUIC_PACKET_T__SEND_TIME | ASSERT_PICOQUIC_PACKET_T__IS_MTU_PROBE | ASSERT_PICOQUIC_PACKET_T__IS_CONGESTION_CONTROLLED | ASSERT_PICOQUIC_PACKET_T__CONTAINS_CRYPTO | ASSERT_PICOQUIC_PACKET_T__HAS_HANDSHAKE_DONE);
  sassert(send_buffer_max == ((size_t) cnx.protoop_inputv[1]));
  sassert(current_time == ((uint64_t) cnx.protoop_inputv[2]));
  sassert((&retransmit_p) == ((picoquic_packet_t *) cnx.protoop_inputv[3]));
  assert_cp__picoquic_packet_t((picoquic_packet_t *) cnx.protoop_inputv[3], &retransmit_p0, ASSERT_NONE);
  sassert((&from_path) == ((picoquic_path_t *) cnx.protoop_inputv[4]));
  assert_cp__picoquic_path_t((picoquic_path_t *) cnx.protoop_inputv[4], &from_path0, ASSERT_NONE);
  //sassert((&reason) == ((char *) cnx.protoop_inputv[5]));
  //assert_cp__char((char *) cnx.protoop_inputv[5], &reason0, ASSERT_NONE);
  assert_cp__picoquic_cnx_t(&cnx, &cnx0, ASSERT_PICOQUIC_CNX_T__PLUGIN_REQUESTED);
  return 0;
}

