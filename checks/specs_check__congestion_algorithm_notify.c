#include "../verifier/verifier.h"

extern picoquic_congestion_notification_t dummy__picoquic_congestion_notification_t();

protoop_arg_t congestion_algorithm_notify(picoquic_cnx_t *cnx);

int main()
{
  picoquic_cnx_t cnx;
  picoquic_cnx_t cnx0;
  init__picoquic_cnx_t(&cnx);
  cnx.protoop_inputc = 6;
  assume_cp__picoquic_cnx_t(&cnx, &cnx0);

  picoquic_path_t path_x;
  picoquic_path_t path_x0;
  init__picoquic_path_t(&path_x);
  assume_cp__picoquic_path_t(&path_x, &path_x0);
  cnx.protoop_inputv[0] = (protoop_arg_t) (&path_x);

  picoquic_congestion_notification_t notification;
  notification = dummy__picoquic_congestion_notification_t();
  cnx.protoop_inputv[1] = notification;

  uint64_t rtt_measurement;
  rtt_measurement = dummy__uint64_t();
  cnx.protoop_inputv[2] = rtt_measurement;

  uint64_t nb_bytes_acknowledged;
  nb_bytes_acknowledged = dummy__uint64_t();
  cnx.protoop_inputv[3] = nb_bytes_acknowledged;

  uint64_t lost_packet_number;
  lost_packet_number = dummy__uint64_t();
  cnx.protoop_inputv[4] = lost_packet_number;

  uint64_t current_time;
  current_time = dummy__uint64_t();
  cnx.protoop_inputv[5] = current_time;

  congestion_algorithm_notify(&cnx);

  sassert((&path_x) == ((picoquic_path_t *) cnx.protoop_inputv[0]));
  assert_cp__picoquic_path_t((picoquic_path_t *) cnx.protoop_inputv[0], &path_x0, ASSERT_PICOQUIC_PATH_T__CWIN | ASSERT_PICOQUIC_PATH_T__BYTES_IN_TRANSIT);
  //assert_cp__picoquic_path_t((picoquic_path_t *) cnx.protoop_inputv[0], &path_x0, ASSERT_NONE); // should sat since cwin and bytes_in_transit are modified
  sassert(notification == ((picoquic_congestion_notification_t) cnx.protoop_inputv[1]));
  sassert(rtt_measurement == ((uint64_t) cnx.protoop_inputv[2]));
  sassert(nb_bytes_acknowledged == ((uint64_t) cnx.protoop_inputv[3]));
  sassert(lost_packet_number == ((uint64_t) cnx.protoop_inputv[4]));
  sassert(current_time == ((uint64_t) cnx.protoop_inputv[5]));
  assert_cp__picoquic_cnx_t(&cnx, &cnx0, ASSERT_NONE);

  return 0;
}

