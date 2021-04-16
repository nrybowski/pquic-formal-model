
#include <picoquic.h>
#include <getset.h>

/**
 * See PROTOOP_NOPARAM_CONGESTION_ALGORITHM_NOTIFY
 */
protoop_arg_t congestion_algorithm_notify(picoquic_cnx_t *cnx)
{
    picoquic_path_t* path_x = (picoquic_path_t *) get_cnx(cnx, AK_CNX_INPUT, 0); //(picoquic_path_t*) cnx->protoop_inputv[0];
    picoquic_congestion_notification_t notification = (picoquic_congestion_notification_t) get_cnx(cnx, AK_CNX_INPUT, 1);
    uint64_t rtt_measurement = (uint64_t) get_cnx(cnx, AK_CNX_INPUT, 2);
    uint64_t nb_bytes_acknowledged = (uint64_t) get_cnx(cnx, AK_CNX_INPUT, 3);
    uint64_t lost_packet_number = (uint64_t) get_cnx(cnx, AK_CNX_INPUT, 4);
    uint64_t current_time = (uint64_t) get_cnx(cnx, AK_CNX_INPUT, 5);

    set_cnx(cnx, AK_CNX_IS_0RTT_ACCEPTED, 0, 1);

    return 0;
}
