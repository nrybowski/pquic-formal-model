#include "verifier/verifier.h"

inline void init__picoquic_connection_id_t(picoquic_connection_id_t *param1)
{
  param1->id_len = dummy__uint8_t();
}

inline void init__picoquic_tp_preferred_address_t(picoquic_tp_preferred_address_t *param1)
{
  param1->ipv4_port = dummy__uint16_t();
  param1->ipv6_port = dummy__uint16_t();
  init__picoquic_connection_id_t(&param1->connection_id);
}

inline void init__picoquic_tp_t(picoquic_tp_t *param1)
{
  init__picoquic_connection_id_t(&param1->original_destination_connection_id);
  param1->max_idle_timeout = dummy__uint64_t();
  param1->max_packet_size = dummy__uint64_t();
  param1->initial_max_data = dummy__uint64_t();
  param1->initial_max_stream_data_bidi_local = dummy__uint64_t();
  param1->initial_max_stream_data_bidi_remote = dummy__uint64_t();
  param1->initial_max_stream_data_uni = dummy__uint64_t();
  param1->initial_max_streams_bidi = dummy__uint64_t();
  param1->initial_max_streams_uni = dummy__uint64_t();
  param1->ack_delay_exponent = dummy__uint64_t();
  param1->max_ack_delay = dummy__uint64_t();
  param1->disable_active_migration = dummy__unsigned_int();
  init__picoquic_tp_preferred_address_t(&param1->preferred_address);
  param1->active_connection_id_limit = dummy__uint64_t();
  init__picoquic_connection_id_t(&param1->initial_source_connection_id);
  init__picoquic_connection_id_t(&param1->retry_source_connection_id);
}

inline void init__picoquic_cnx_t(picoquic_cnx_t *param1)
{
  param1->proposed_version = dummy__uint32_t();
  param1->version_index = dummy__int();
  param1->is_0RTT_accepted = dummy__unsigned_int();
  param1->remote_parameters_received = dummy__unsigned_int();
  param1->current_spin = dummy__unsigned_int();
  param1->client_mode = dummy__unsigned_int();
  param1->prev_spin = dummy__unsigned_int();
  param1->spin_vec = dummy__unsigned_int();
  param1->spin_edge = dummy__unsigned_int();
  param1->spin_last_trigger = dummy__uint64_t();
  param1->key_phase_enc = dummy__unsigned_int();
  param1->key_phase_dec = dummy__unsigned_int();
  param1->zero_rtt_data_accepted = dummy__unsigned_int();
  param1->one_rtt_data_acknowledged = dummy__unsigned_int();
  param1->processed_transport_parameter = dummy__unsigned_int();
  init__picoquic_tp_t(&param1->local_parameters);
  init__picoquic_tp_t(&param1->remote_parameters);
  param1->max_early_data_size = dummy__size_t();
  init__picoquic_connection_id_t(&param1->initial_cnxid);
  param1->start_time = dummy__uint64_t();
  param1->application_error = dummy__uint64_t();
  param1->local_error = dummy__uint64_t();
  param1->remote_application_error = dummy__uint64_t();
  param1->remote_error = dummy__uint64_t();
  param1->offending_frame_type = dummy__uint64_t();
  param1->retry_token_length = dummy__uint32_t();
  param1->handshake_done = dummy__unsigned_int();
  param1->handshake_done_sent = dummy__unsigned_int();
  param1->handshake_done_acked = dummy__unsigned_int();
  param1->next_wake_time = dummy__uint64_t();
  param1->psk_cipher_suite_id = dummy__uint16_t();
  param1->latest_progress_time = dummy__uint64_t();
  param1->nb_bytes_queued = dummy__uint64_t();
  param1->nb_path_challenge_sent = dummy__uint32_t();
  param1->nb_path_response_received = dummy__uint32_t();
  param1->nb_zero_rtt_sent = dummy__uint32_t();
  param1->nb_zero_rtt_acked = dummy__uint32_t();
  param1->nb_retransmission_total = dummy__uint64_t();
  param1->nb_spurious = dummy__uint64_t();
  param1->data_sent = dummy__uint64_t();
  param1->data_received = dummy__uint64_t();
  param1->maxdata_local = dummy__uint64_t();
  param1->maxdata_remote = dummy__uint64_t();
  param1->max_stream_id_bidir_local = dummy__uint64_t();
  param1->max_stream_id_bidir_local_computed = dummy__uint64_t();
  param1->max_stream_id_unidir_local = dummy__uint64_t();
  param1->max_stream_id_unidir_local_computed = dummy__uint64_t();
  param1->max_stream_id_bidir_remote = dummy__uint64_t();
  param1->max_stream_id_unidir_remote = dummy__uint64_t();
  param1->last_visited_stream_id = dummy__uint64_t();
  param1->last_visited_plugin_stream_id = dummy__uint64_t();
  param1->keep_alive_interval = dummy__uint64_t();
  param1->nb_paths = dummy__int();
  param1->nb_path_alloc = dummy__int();
  param1->core_rate = dummy__uint16_t();
  param1->wake_now = dummy__uint8_t();
  param1->plugin_requested = dummy__uint8_t();
  param1->protoop_inputc = dummy__int();
  param1->protoop_outputc_callee = dummy__int();
}

inline void init__picoquic_sack_item_t(picoquic_sack_item_t *param1)
{
  param1->start_of_sack_range = dummy__uint64_t();
  param1->end_of_sack_range = dummy__uint64_t();
}

inline void init__picoquic_packet_context_t(picoquic_packet_context_t *param1)
{
  param1->send_sequence = dummy__uint64_t();
  init__picoquic_sack_item_t(&param1->first_sack_item);
  param1->time_stamp_largest_received = dummy__uint64_t();
  param1->highest_ack_sent = dummy__uint64_t();
  param1->highest_ack_time = dummy__uint64_t();
  param1->ack_delay_local = dummy__uint64_t();
  param1->latest_progress_time = dummy__uint64_t();
  param1->nb_retransmit = dummy__uint64_t();
  param1->latest_retransmit_time = dummy__uint64_t();
  param1->latest_retransmit_cc_notification_time = dummy__uint64_t();
  param1->highest_acknowledged = dummy__uint64_t();
  param1->latest_time_acknowledged = dummy__uint64_t();
  param1->ack_needed = dummy__unsigned_int();
}

inline void init__picoquic_path_t(picoquic_path_t *param1)
{
  param1->peer_addr_len = dummy__int();
  param1->local_addr_len = dummy__int();
  param1->if_index_local = dummy__unsigned_long();
  param1->challenge = dummy__uint64_t();
  param1->challenge_time = dummy__uint64_t();
  param1->challenge_repeat_count = dummy__uint8_t();
  param1->mtu_probe_sent = dummy__unsigned_int();
  param1->challenge_verified = dummy__unsigned_int();
  param1->challenge_response_to_send = dummy__unsigned_int();
  param1->ping_received = dummy__unsigned_int();
  param1->last_bw_estimate_path_limited = dummy__unsigned_int();
  param1->max_ack_delay = dummy__uint64_t();
  param1->rtt_sample = dummy__uint64_t();
  param1->smoothed_rtt = dummy__uint64_t();
  param1->rtt_variant = dummy__uint64_t();
  param1->retransmit_timer = dummy__uint64_t();
  param1->rtt_min = dummy__uint64_t();
  param1->max_spurious_rtt = dummy__uint64_t();
  param1->max_reorder_delay = dummy__uint64_t();
  param1->max_reorder_gap = dummy__uint64_t();
  param1->send_mtu = dummy__uint32_t();
  param1->send_mtu_max_tried = dummy__uint32_t();
  param1->cwin = dummy__uint64_t();
  param1->bytes_in_transit = dummy__uint64_t();
  param1->pacing_evaluation_time = dummy__uint64_t();
  param1->pacing_bucket_nanosec = dummy__uint64_t();
  param1->pacing_bucket_max = dummy__uint64_t();
  param1->pacing_packet_time_nanosec = dummy__uint64_t();
  param1->pacing_packet_time_microsec = dummy__uint64_t();
  param1->nb_pkt_sent = dummy__uint64_t();
  param1->delivered = dummy__uint64_t();
  param1->delivered_last = dummy__uint64_t();
  param1->delivered_time_last = dummy__uint64_t();
  param1->delivered_sent_last = dummy__uint64_t();
  param1->delivered_limited_index = dummy__uint64_t();
  param1->delivered_last_packet = dummy__uint64_t();
  param1->bandwidth_estimate = dummy__uint64_t();
  param1->received = dummy__uint64_t();
  param1->receive_rate_epoch = dummy__uint64_t();
  param1->received_prior = dummy__uint64_t();
  param1->receive_rate_estimate = dummy__uint64_t();
  param1->receive_rate_max = dummy__uint64_t();
  init__picoquic_connection_id_t(&param1->local_cnxid);
  init__picoquic_connection_id_t(&param1->remote_cnxid);
}

inline void assume_cp__picoquic_connection_id_t(picoquic_connection_id_t *src, picoquic_connection_id_t *dst)
{
  dummy_cp__picoquic_connection_id_t(src, dst);
  assume(src->id_len == dst->id_len);
}

inline void assume_cp__picoquic_tp_preferred_address_t(picoquic_tp_preferred_address_t *src, picoquic_tp_preferred_address_t *dst)
{
  dummy_cp__picoquic_tp_preferred_address_t(src, dst);
  assume(src->ipv4_port == dst->ipv4_port);
  assume(src->ipv6_port == dst->ipv6_port);
  assume_cp__picoquic_connection_id_t(&src->connection_id, &dst->connection_id);
}

inline void assume_cp__picoquic_tp_t(picoquic_tp_t *src, picoquic_tp_t *dst)
{
  dummy_cp__picoquic_tp_t(src, dst);
  assume_cp__picoquic_connection_id_t(&src->original_destination_connection_id, &dst->original_destination_connection_id);
  assume(src->max_idle_timeout == dst->max_idle_timeout);
  assume(src->max_packet_size == dst->max_packet_size);
  assume(src->initial_max_data == dst->initial_max_data);
  assume(src->initial_max_stream_data_bidi_local == dst->initial_max_stream_data_bidi_local);
  assume(src->initial_max_stream_data_bidi_remote == dst->initial_max_stream_data_bidi_remote);
  assume(src->initial_max_stream_data_uni == dst->initial_max_stream_data_uni);
  assume(src->initial_max_streams_bidi == dst->initial_max_streams_bidi);
  assume(src->initial_max_streams_uni == dst->initial_max_streams_uni);
  assume(src->ack_delay_exponent == dst->ack_delay_exponent);
  assume(src->max_ack_delay == dst->max_ack_delay);
  assume(src->disable_active_migration == dst->disable_active_migration);
  assume_cp__picoquic_tp_preferred_address_t(&src->preferred_address, &dst->preferred_address);
  assume(src->active_connection_id_limit == dst->active_connection_id_limit);
  assume_cp__picoquic_connection_id_t(&src->initial_source_connection_id, &dst->initial_source_connection_id);
  assume_cp__picoquic_connection_id_t(&src->retry_source_connection_id, &dst->retry_source_connection_id);
}

inline void assume_cp__picoquic_cnx_t(picoquic_cnx_t *src, picoquic_cnx_t *dst)
{
  dummy_cp__picoquic_cnx_t(src, dst);
  assume(src->proposed_version == dst->proposed_version);
  assume(src->version_index == dst->version_index);
  assume(src->is_0RTT_accepted == dst->is_0RTT_accepted);
  assume(src->remote_parameters_received == dst->remote_parameters_received);
  assume(src->current_spin == dst->current_spin);
  assume(src->client_mode == dst->client_mode);
  assume(src->prev_spin == dst->prev_spin);
  assume(src->spin_vec == dst->spin_vec);
  assume(src->spin_edge == dst->spin_edge);
  assume(src->spin_last_trigger == dst->spin_last_trigger);
  assume(src->key_phase_enc == dst->key_phase_enc);
  assume(src->key_phase_dec == dst->key_phase_dec);
  assume(src->zero_rtt_data_accepted == dst->zero_rtt_data_accepted);
  assume(src->one_rtt_data_acknowledged == dst->one_rtt_data_acknowledged);
  assume(src->processed_transport_parameter == dst->processed_transport_parameter);
  assume_cp__picoquic_tp_t(&src->local_parameters, &dst->local_parameters);
  assume_cp__picoquic_tp_t(&src->remote_parameters, &dst->remote_parameters);
  assume(src->max_early_data_size == dst->max_early_data_size);
  assume_cp__picoquic_connection_id_t(&src->initial_cnxid, &dst->initial_cnxid);
  assume(src->start_time == dst->start_time);
  assume(src->application_error == dst->application_error);
  assume(src->local_error == dst->local_error);
  assume(src->remote_application_error == dst->remote_application_error);
  assume(src->remote_error == dst->remote_error);
  assume(src->offending_frame_type == dst->offending_frame_type);
  assume(src->retry_token_length == dst->retry_token_length);
  assume(src->handshake_done == dst->handshake_done);
  assume(src->handshake_done_sent == dst->handshake_done_sent);
  assume(src->handshake_done_acked == dst->handshake_done_acked);
  assume(src->next_wake_time == dst->next_wake_time);
  assume(src->psk_cipher_suite_id == dst->psk_cipher_suite_id);
  assume(src->latest_progress_time == dst->latest_progress_time);
  assume(src->nb_bytes_queued == dst->nb_bytes_queued);
  assume(src->nb_path_challenge_sent == dst->nb_path_challenge_sent);
  assume(src->nb_path_response_received == dst->nb_path_response_received);
  assume(src->nb_zero_rtt_sent == dst->nb_zero_rtt_sent);
  assume(src->nb_zero_rtt_acked == dst->nb_zero_rtt_acked);
  assume(src->nb_retransmission_total == dst->nb_retransmission_total);
  assume(src->nb_spurious == dst->nb_spurious);
  assume(src->data_sent == dst->data_sent);
  assume(src->data_received == dst->data_received);
  assume(src->maxdata_local == dst->maxdata_local);
  assume(src->maxdata_remote == dst->maxdata_remote);
  assume(src->max_stream_id_bidir_local == dst->max_stream_id_bidir_local);
  assume(src->max_stream_id_bidir_local_computed == dst->max_stream_id_bidir_local_computed);
  assume(src->max_stream_id_unidir_local == dst->max_stream_id_unidir_local);
  assume(src->max_stream_id_unidir_local_computed == dst->max_stream_id_unidir_local_computed);
  assume(src->max_stream_id_bidir_remote == dst->max_stream_id_bidir_remote);
  assume(src->max_stream_id_unidir_remote == dst->max_stream_id_unidir_remote);
  assume(src->last_visited_stream_id == dst->last_visited_stream_id);
  assume(src->last_visited_plugin_stream_id == dst->last_visited_plugin_stream_id);
  assume(src->keep_alive_interval == dst->keep_alive_interval);
  assume(src->nb_paths == dst->nb_paths);
  assume(src->nb_path_alloc == dst->nb_path_alloc);
  assume(src->core_rate == dst->core_rate);
  assume(src->wake_now == dst->wake_now);
  assume(src->plugin_requested == dst->plugin_requested);
  //assume(src->pids_to_request == dst->pids_to_request);
  assume(src->protoop_inputc == dst->protoop_inputc);
  assume(src->protoop_outputc_callee == dst->protoop_outputc_callee);
  assume(src->protoop_output == dst->protoop_output);
  assume(src->current_anchor == dst->current_anchor);
}

inline void assume_cp__picoquic_sack_item_t(picoquic_sack_item_t *src, picoquic_sack_item_t *dst)
{
  dummy_cp__picoquic_sack_item_t(src, dst);
  assume(src->start_of_sack_range == dst->start_of_sack_range);
  assume(src->end_of_sack_range == dst->end_of_sack_range);
}

inline void assume_cp__picoquic_packet_context_t(picoquic_packet_context_t *src, picoquic_packet_context_t *dst)
{
  dummy_cp__picoquic_packet_context_t(src, dst);
  assume(src->send_sequence == dst->send_sequence);
  assume_cp__picoquic_sack_item_t(&src->first_sack_item, &dst->first_sack_item);
  assume(src->time_stamp_largest_received == dst->time_stamp_largest_received);
  assume(src->highest_ack_sent == dst->highest_ack_sent);
  assume(src->highest_ack_time == dst->highest_ack_time);
  assume(src->ack_delay_local == dst->ack_delay_local);
  assume(src->latest_progress_time == dst->latest_progress_time);
  assume(src->nb_retransmit == dst->nb_retransmit);
  assume(src->latest_retransmit_time == dst->latest_retransmit_time);
  assume(src->latest_retransmit_cc_notification_time == dst->latest_retransmit_cc_notification_time);
  assume(src->highest_acknowledged == dst->highest_acknowledged);
  assume(src->latest_time_acknowledged == dst->latest_time_acknowledged);
  assume(src->ack_needed == dst->ack_needed);
}

inline void assume_cp__picoquic_path_t(picoquic_path_t *src, picoquic_path_t *dst)
{
  dummy_cp__picoquic_path_t(src, dst);
  //assume(src->peer_addr == dst->peer_addr);
  assume(src->peer_addr_len == dst->peer_addr_len);
  //assume(src->local_addr == dst->local_addr);
  assume(src->local_addr_len == dst->local_addr_len);
  assume(src->if_index_local == dst->if_index_local);
  assume(src->challenge == dst->challenge);
  assume(src->challenge_time == dst->challenge_time);
  assume(src->challenge_repeat_count == dst->challenge_repeat_count);
  assume(src->mtu_probe_sent == dst->mtu_probe_sent);
  assume(src->challenge_verified == dst->challenge_verified);
  assume(src->challenge_response_to_send == dst->challenge_response_to_send);
  assume(src->ping_received == dst->ping_received);
  assume(src->last_bw_estimate_path_limited == dst->last_bw_estimate_path_limited);
  assume(src->max_ack_delay == dst->max_ack_delay);
  assume(src->rtt_sample == dst->rtt_sample);
  assume(src->smoothed_rtt == dst->smoothed_rtt);
  assume(src->rtt_variant == dst->rtt_variant);
  assume(src->retransmit_timer == dst->retransmit_timer);
  assume(src->rtt_min == dst->rtt_min);
  assume(src->max_spurious_rtt == dst->max_spurious_rtt);
  assume(src->max_reorder_delay == dst->max_reorder_delay);
  assume(src->max_reorder_gap == dst->max_reorder_gap);
  assume(src->send_mtu == dst->send_mtu);
  assume(src->send_mtu_max_tried == dst->send_mtu_max_tried);
  assume(src->cwin == dst->cwin);
  assume(src->bytes_in_transit == dst->bytes_in_transit);
  assume(src->pacing_evaluation_time == dst->pacing_evaluation_time);
  assume(src->pacing_bucket_nanosec == dst->pacing_bucket_nanosec);
  assume(src->pacing_bucket_max == dst->pacing_bucket_max);
  assume(src->pacing_packet_time_nanosec == dst->pacing_packet_time_nanosec);
  assume(src->pacing_packet_time_microsec == dst->pacing_packet_time_microsec);
  assume(src->nb_pkt_sent == dst->nb_pkt_sent);
  assume(src->delivered == dst->delivered);
  assume(src->delivered_last == dst->delivered_last);
  assume(src->delivered_time_last == dst->delivered_time_last);
  assume(src->delivered_sent_last == dst->delivered_sent_last);
  assume(src->delivered_limited_index == dst->delivered_limited_index);
  assume(src->delivered_last_packet == dst->delivered_last_packet);
  assume(src->bandwidth_estimate == dst->bandwidth_estimate);
  assume(src->received == dst->received);
  assume(src->receive_rate_epoch == dst->receive_rate_epoch);
  assume(src->received_prior == dst->received_prior);
  assume(src->receive_rate_estimate == dst->receive_rate_estimate);
  assume(src->receive_rate_max == dst->receive_rate_max);
  assume_cp__picoquic_connection_id_t(&src->local_cnxid, &dst->local_cnxid);
  assume_cp__picoquic_connection_id_t(&src->remote_cnxid, &dst->remote_cnxid);
}

inline void assert_cp__picoquic_connection_id_t(picoquic_connection_id_t *param1, picoquic_connection_id_t *param2)
{
  unsigned int cond = 1;
  cond &= param1->id_len == param2->id_len;
  sassert(cond);
}

inline void assert_cp__picoquic_tp_preferred_address_t(picoquic_tp_preferred_address_t *param1, picoquic_tp_preferred_address_t *param2)
{
  unsigned int cond = 1;
  cond &= param1->ipv4_port == param2->ipv4_port;
  cond &= param1->ipv6_port == param2->ipv6_port;
  assert_cp__picoquic_connection_id_t(&param1->connection_id, &param2->connection_id);
  sassert(cond);
}

inline void assert_cp__picoquic_tp_t(picoquic_tp_t *param1, picoquic_tp_t *param2)
{
  unsigned int cond = 1;
  assert_cp__picoquic_connection_id_t(&param1->original_destination_connection_id, &param2->original_destination_connection_id);
  cond &= param1->max_idle_timeout == param2->max_idle_timeout;
  cond &= param1->max_packet_size == param2->max_packet_size;
  cond &= param1->initial_max_data == param2->initial_max_data;
  cond &= param1->initial_max_stream_data_bidi_local == param2->initial_max_stream_data_bidi_local;
  cond &= param1->initial_max_stream_data_bidi_remote == param2->initial_max_stream_data_bidi_remote;
  cond &= param1->initial_max_stream_data_uni == param2->initial_max_stream_data_uni;
  cond &= param1->initial_max_streams_bidi == param2->initial_max_streams_bidi;
  cond &= param1->initial_max_streams_uni == param2->initial_max_streams_uni;
  cond &= param1->ack_delay_exponent == param2->ack_delay_exponent;
  cond &= param1->max_ack_delay == param2->max_ack_delay;
  cond &= param1->disable_active_migration == param2->disable_active_migration;
  assert_cp__picoquic_tp_preferred_address_t(&param1->preferred_address, &param2->preferred_address);
  cond &= param1->active_connection_id_limit == param2->active_connection_id_limit;
  assert_cp__picoquic_connection_id_t(&param1->initial_source_connection_id, &param2->initial_source_connection_id);
  assert_cp__picoquic_connection_id_t(&param1->retry_source_connection_id, &param2->retry_source_connection_id);
  sassert(cond);
}

inline void assert_cp__picoquic_cnx_t(picoquic_cnx_t *param1, picoquic_cnx_t *param2)
{
  unsigned int cond = 1;
  cond &= param1->proposed_version == param2->proposed_version;
  cond &= param1->version_index == param2->version_index;
  cond &= param1->is_0RTT_accepted == param2->is_0RTT_accepted;
  cond &= param1->remote_parameters_received == param2->remote_parameters_received;
  cond &= param1->current_spin == param2->current_spin;
  cond &= param1->client_mode == param2->client_mode;
  cond &= param1->prev_spin == param2->prev_spin;
  cond &= param1->spin_vec == param2->spin_vec;
  cond &= param1->spin_edge == param2->spin_edge;
  cond &= param1->spin_last_trigger == param2->spin_last_trigger;
  cond &= param1->key_phase_enc == param2->key_phase_enc;
  cond &= param1->key_phase_dec == param2->key_phase_dec;
  cond &= param1->zero_rtt_data_accepted == param2->zero_rtt_data_accepted;
  cond &= param1->one_rtt_data_acknowledged == param2->one_rtt_data_acknowledged;
  cond &= param1->processed_transport_parameter == param2->processed_transport_parameter;
  assert_cp__picoquic_tp_t(&param1->local_parameters, &param2->local_parameters);
  assert_cp__picoquic_tp_t(&param1->remote_parameters, &param2->remote_parameters);
  cond &= param1->max_early_data_size == param2->max_early_data_size;
  assert_cp__picoquic_connection_id_t(&param1->initial_cnxid, &param2->initial_cnxid);
  cond &= param1->start_time == param2->start_time;
  cond &= param1->application_error == param2->application_error;
  cond &= param1->local_error == param2->local_error;
  cond &= param1->remote_application_error == param2->remote_application_error;
  cond &= param1->remote_error == param2->remote_error;
  cond &= param1->offending_frame_type == param2->offending_frame_type;
  cond &= param1->retry_token_length == param2->retry_token_length;
  cond &= param1->handshake_done == param2->handshake_done;
  cond &= param1->handshake_done_sent == param2->handshake_done_sent;
  cond &= param1->handshake_done_acked == param2->handshake_done_acked;
  cond &= param1->next_wake_time == param2->next_wake_time;
  cond &= param1->psk_cipher_suite_id == param2->psk_cipher_suite_id;
  cond &= param1->latest_progress_time == param2->latest_progress_time;
  cond &= param1->nb_bytes_queued == param2->nb_bytes_queued;
  cond &= param1->nb_path_challenge_sent == param2->nb_path_challenge_sent;
  cond &= param1->nb_path_response_received == param2->nb_path_response_received;
  cond &= param1->nb_zero_rtt_sent == param2->nb_zero_rtt_sent;
  cond &= param1->nb_zero_rtt_acked == param2->nb_zero_rtt_acked;
  cond &= param1->nb_retransmission_total == param2->nb_retransmission_total;
  cond &= param1->nb_spurious == param2->nb_spurious;
  cond &= param1->data_sent == param2->data_sent;
  cond &= param1->data_received == param2->data_received;
  cond &= param1->maxdata_local == param2->maxdata_local;
  cond &= param1->maxdata_remote == param2->maxdata_remote;
  cond &= param1->max_stream_id_bidir_local == param2->max_stream_id_bidir_local;
  cond &= param1->max_stream_id_bidir_local_computed == param2->max_stream_id_bidir_local_computed;
  cond &= param1->max_stream_id_unidir_local == param2->max_stream_id_unidir_local;
  cond &= param1->max_stream_id_unidir_local_computed == param2->max_stream_id_unidir_local_computed;
  cond &= param1->max_stream_id_bidir_remote == param2->max_stream_id_bidir_remote;
  cond &= param1->max_stream_id_unidir_remote == param2->max_stream_id_unidir_remote;
  cond &= param1->last_visited_stream_id == param2->last_visited_stream_id;
  cond &= param1->last_visited_plugin_stream_id == param2->last_visited_plugin_stream_id;
  cond &= param1->keep_alive_interval == param2->keep_alive_interval;
  cond &= param1->nb_paths == param2->nb_paths;
  cond &= param1->nb_path_alloc == param2->nb_path_alloc;
  cond &= param1->core_rate == param2->core_rate;
  cond &= param1->wake_now == param2->wake_now;
  cond &= param1->plugin_requested == param2->plugin_requested;
  //cond &= param1->pids_to_request == param2->pids_to_request;
  cond &= param1->protoop_inputc == param2->protoop_inputc;
  cond &= param1->protoop_outputc_callee == param2->protoop_outputc_callee;
  cond &= param1->protoop_output == param2->protoop_output;
  cond &= param1->current_anchor == param2->current_anchor;
  sassert(cond);
}

inline void assert_cp__picoquic_sack_item_t(picoquic_sack_item_t *param1, picoquic_sack_item_t *param2)
{
  unsigned int cond = 1;
  cond &= param1->start_of_sack_range == param2->start_of_sack_range;
  cond &= param1->end_of_sack_range == param2->end_of_sack_range;
  sassert(cond);
}

inline void assert_cp__picoquic_packet_context_t(picoquic_packet_context_t *param1, picoquic_packet_context_t *param2)
{
  unsigned int cond = 1;
  cond &= param1->send_sequence == param2->send_sequence;
  assert_cp__picoquic_sack_item_t(&param1->first_sack_item, &param2->first_sack_item);
  cond &= param1->time_stamp_largest_received == param2->time_stamp_largest_received;
  cond &= param1->highest_ack_sent == param2->highest_ack_sent;
  cond &= param1->highest_ack_time == param2->highest_ack_time;
  //cond &= param1->ack_delay_local == param2->ack_delay_local;
  cond &= param1->latest_progress_time == param2->latest_progress_time;
  cond &= param1->nb_retransmit == param2->nb_retransmit;
  cond &= param1->latest_retransmit_time == param2->latest_retransmit_time;
  cond &= param1->latest_retransmit_cc_notification_time == param2->latest_retransmit_cc_notification_time;
  cond &= param1->highest_acknowledged == param2->highest_acknowledged;
  cond &= param1->latest_time_acknowledged == param2->latest_time_acknowledged;
  cond &= param1->ack_needed == param2->ack_needed;
  sassert(cond);
}

inline void assert_cp__picoquic_path_t(picoquic_path_t *param1, picoquic_path_t *param2)
{
  unsigned int cond = 1;
  //cond &= param1->peer_addr == param2->peer_addr;
  cond &= param1->peer_addr_len == param2->peer_addr_len;
  //cond &= param1->local_addr == param2->local_addr;
  cond &= param1->local_addr_len == param2->local_addr_len;
  cond &= param1->if_index_local == param2->if_index_local;
  cond &= param1->challenge == param2->challenge;
  cond &= param1->challenge_time == param2->challenge_time;
  cond &= param1->challenge_repeat_count == param2->challenge_repeat_count;
  cond &= param1->mtu_probe_sent == param2->mtu_probe_sent;
  cond &= param1->challenge_verified == param2->challenge_verified;
  cond &= param1->challenge_response_to_send == param2->challenge_response_to_send;
  cond &= param1->ping_received == param2->ping_received;
  cond &= param1->last_bw_estimate_path_limited == param2->last_bw_estimate_path_limited;
  cond &= param1->max_ack_delay == param2->max_ack_delay;
  cond &= param1->rtt_sample == param2->rtt_sample;
  cond &= param1->smoothed_rtt == param2->smoothed_rtt;
  cond &= param1->rtt_variant == param2->rtt_variant;
  cond &= param1->retransmit_timer == param2->retransmit_timer;
  cond &= param1->rtt_min == param2->rtt_min;
  cond &= param1->max_spurious_rtt == param2->max_spurious_rtt;
  cond &= param1->max_reorder_delay == param2->max_reorder_delay;
  cond &= param1->max_reorder_gap == param2->max_reorder_gap;
  cond &= param1->send_mtu == param2->send_mtu;
  cond &= param1->send_mtu_max_tried == param2->send_mtu_max_tried;
  cond &= param1->cwin == param2->cwin;
  cond &= param1->bytes_in_transit == param2->bytes_in_transit;
  cond &= param1->pacing_evaluation_time == param2->pacing_evaluation_time;
  cond &= param1->pacing_bucket_nanosec == param2->pacing_bucket_nanosec;
  cond &= param1->pacing_bucket_max == param2->pacing_bucket_max;
  cond &= param1->pacing_packet_time_nanosec == param2->pacing_packet_time_nanosec;
  cond &= param1->pacing_packet_time_microsec == param2->pacing_packet_time_microsec;
  cond &= param1->nb_pkt_sent == param2->nb_pkt_sent;
  cond &= param1->delivered == param2->delivered;
  cond &= param1->delivered_last == param2->delivered_last;
  cond &= param1->delivered_time_last == param2->delivered_time_last;
  cond &= param1->delivered_sent_last == param2->delivered_sent_last;
  cond &= param1->delivered_limited_index == param2->delivered_limited_index;
  cond &= param1->delivered_last_packet == param2->delivered_last_packet;
  cond &= param1->bandwidth_estimate == param2->bandwidth_estimate;
  cond &= param1->received == param2->received;
  cond &= param1->receive_rate_epoch == param2->receive_rate_epoch;
  cond &= param1->received_prior == param2->received_prior;
  cond &= param1->receive_rate_estimate == param2->receive_rate_estimate;
  cond &= param1->receive_rate_max == param2->receive_rate_max;
  assert_cp__picoquic_connection_id_t(&param1->local_cnxid, &param2->local_cnxid);
  assert_cp__picoquic_connection_id_t(&param1->remote_cnxid, &param2->remote_cnxid);
  sassert(cond);
}

