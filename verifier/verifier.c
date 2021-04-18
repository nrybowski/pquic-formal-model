#include "verifier.h"

/* WARNING : this file is automagically generated. */

inline void init__picoquic_connection_id_t(picoquic_connection_id_t *param1)
{
  param1->id[0] = dummy__uint8_t();
  param1->id[1] = dummy__uint8_t();
  param1->id[2] = dummy__uint8_t();
  param1->id[3] = dummy__uint8_t();
  param1->id[4] = dummy__uint8_t();
  param1->id[5] = dummy__uint8_t();
  param1->id[6] = dummy__uint8_t();
  param1->id[7] = dummy__uint8_t();
  param1->id[8] = dummy__uint8_t();
  param1->id[9] = dummy__uint8_t();
  param1->id[10] = dummy__uint8_t();
  param1->id[11] = dummy__uint8_t();
  param1->id[12] = dummy__uint8_t();
  param1->id[13] = dummy__uint8_t();
  param1->id[14] = dummy__uint8_t();
  param1->id[15] = dummy__uint8_t();
  param1->id[16] = dummy__uint8_t();
  param1->id[17] = dummy__uint8_t();
  param1->id[18] = dummy__uint8_t();
  param1->id[19] = dummy__uint8_t();
  param1->id_len = dummy__uint8_t();
}

inline void init__picoquic_tp_preferred_address_t(picoquic_tp_preferred_address_t *param1)
{
  param1->ipv4_address[0] = dummy__uint8_t();
  param1->ipv4_address[1] = dummy__uint8_t();
  param1->ipv4_address[2] = dummy__uint8_t();
  param1->ipv4_address[3] = dummy__uint8_t();
  param1->ipv4_port = dummy__uint16_t();
  param1->ipv6_address[0] = dummy__uint8_t();
  param1->ipv6_address[1] = dummy__uint8_t();
  param1->ipv6_address[2] = dummy__uint8_t();
  param1->ipv6_address[3] = dummy__uint8_t();
  param1->ipv6_address[4] = dummy__uint8_t();
  param1->ipv6_address[5] = dummy__uint8_t();
  param1->ipv6_address[6] = dummy__uint8_t();
  param1->ipv6_address[7] = dummy__uint8_t();
  param1->ipv6_address[8] = dummy__uint8_t();
  param1->ipv6_address[9] = dummy__uint8_t();
  param1->ipv6_address[10] = dummy__uint8_t();
  param1->ipv6_address[11] = dummy__uint8_t();
  param1->ipv6_address[12] = dummy__uint8_t();
  param1->ipv6_address[13] = dummy__uint8_t();
  param1->ipv6_address[14] = dummy__uint8_t();
  param1->ipv6_address[15] = dummy__uint8_t();
  param1->ipv6_port = dummy__uint16_t();
  init__picoquic_connection_id_t(&param1->connection_id);
  param1->stateless_reset_token[0] = dummy__uint8_t();
  param1->stateless_reset_token[1] = dummy__uint8_t();
  param1->stateless_reset_token[2] = dummy__uint8_t();
  param1->stateless_reset_token[3] = dummy__uint8_t();
  param1->stateless_reset_token[4] = dummy__uint8_t();
  param1->stateless_reset_token[5] = dummy__uint8_t();
  param1->stateless_reset_token[6] = dummy__uint8_t();
  param1->stateless_reset_token[7] = dummy__uint8_t();
  param1->stateless_reset_token[8] = dummy__uint8_t();
  param1->stateless_reset_token[9] = dummy__uint8_t();
  param1->stateless_reset_token[10] = dummy__uint8_t();
  param1->stateless_reset_token[11] = dummy__uint8_t();
  param1->stateless_reset_token[12] = dummy__uint8_t();
  param1->stateless_reset_token[13] = dummy__uint8_t();
  param1->stateless_reset_token[14] = dummy__uint8_t();
  param1->stateless_reset_token[15] = dummy__uint8_t();
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
  param1->quic = NULL;
  param1->next_in_table = NULL;
  param1->previous_in_table = NULL;
  param1->first_cnx_id = NULL;
  param1->first_net_id = NULL;
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
  param1->sni = NULL;
  param1->alpn = NULL;
  param1->max_early_data_size = dummy__size_t();
  param1->callback_fn = NULL;
  param1->callback_ctx = NULL;
  param1->cnx_state = dummy__picoquic_state_enum();
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
  param1->next_by_wake_time = NULL;
  param1->previous_by_wake_time = NULL;
  param1->tls_ctx = NULL;
  param1->tls_sendbuf = NULL;
  param1->psk_cipher_suite_id = dummy__uint16_t();
  //param1->tls_stream;
  //param1->crypto_context
  param1->latest_progress_time = dummy__uint64_t();
  param1->nb_bytes_queued = dummy__uint64_t();
  param1->nb_path_challenge_sent = dummy__uint32_t();
  param1->nb_path_response_received = dummy__uint32_t();
  param1->nb_zero_rtt_sent = dummy__uint32_t();
  param1->nb_zero_rtt_acked = dummy__uint32_t();
  param1->nb_retransmission_total = dummy__uint64_t();
  param1->nb_spurious = dummy__uint64_t();
  param1->congestion_alg = NULL;
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
  param1->first_stream = NULL;
  param1->last_visited_stream_id = dummy__uint64_t();
  param1->last_visited_plugin_stream_id = dummy__uint64_t();
  param1->keep_alive_interval = dummy__uint64_t();
  param1->nb_paths = dummy__int();
  param1->nb_path_alloc = dummy__int();

  //assume(param1->nb_paths < 2 && param1->nb_paths > 0); // timeout
  // timeout without assume
  param1->nb_paths = 1;
  // param1->nb_paths = 2; // unsat with sassert(0)
  param1->path = (picoquic_path_t**) malloc(sizeof(picoquic_path_t*)*param1->nb_paths);
  for (int i=0; i<param1->nb_paths; i++) {
    param1->path[i] = (picoquic_path_t*) malloc(sizeof(picoquic_path_t));
    init__picoquic_path_t(param1->path[i]);
  }

  param1->reserved_frames = NULL;
  param1->retry_frames = NULL;
  for (int i=0; i<picoquic_nb_packet_context; i++)
    param1->rtx_frames[i] = NULL;
  param1->first_drr = NULL;
  param1->core_rate = dummy__uint16_t();
  param1->wake_now = dummy__uint8_t();
  param1->plugin_requested = dummy__uint8_t();
  // param1->pids_to_request
  param1->first_plugin_stream = NULL;
  param1->ops = NULL;
  param1->plugins = NULL;
  param1->metadata = NULL;
  param1->protoop_inputc = dummy__int();
  for (int i=0; i<PROTOOPARGS_MAX; i++) {
    param1->protoop_inputv[i] = 0;
    param1->protoop_outputv[i] = 0;
  }
  param1->protoop_outputc_callee = dummy__int();
  param1->protoop_output = 0;
  param1->current_protoop = NULL;
  param1->current_anchor = pluglet_replace;
  param1->current_plugin = NULL;
  param1->previous_plugin_in_replace = NULL;
}

inline void init__picoquic_sack_item_t(picoquic_sack_item_t *param1)
{
  param1->next_sack = NULL;
  param1->start_of_sack_range = dummy__uint64_t();
  param1->end_of_sack_range = dummy__uint64_t();
  assume(param1->end_of_sack_range > param1->start_of_sack_range);
}

inline void init__picoquic_packet_context_t(picoquic_packet_context_t *param1)
{
  param1->send_sequence = dummy__uint64_t();

  picoquic_sack_item_t *si = (picoquic_sack_item_t*) malloc(sizeof(picoquic_sack_item_t)), *runner = NULL, *head = NULL;
  init__picoquic_sack_item_t(si);
  runner = si;
  head = si;

  for(uint64_t i=0; i<dummy__uint64_t(); i++) {
    si = (picoquic_sack_item_t*) malloc(sizeof(picoquic_sack_item_t));
    init__picoquic_sack_item_t(si);
    runner->next_sack = si;
    runner = si;
  }

  param1->first_sack_item.next_sack = head->next_sack;
  param1->first_sack_item.start_of_sack_range = head->start_of_sack_range;
  param1->first_sack_item.end_of_sack_range = head->end_of_sack_range;

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
  picoquic_packet_t *p1, *p2;
  p1 = (picoquic_packet_t*) malloc(sizeof(picoquic_packet_t));
  assume(p1 != NULL);
  init__picoquic_packet_t(p1);
  p2 = (picoquic_packet_t*) malloc(sizeof(picoquic_packet_context_t));
  assume(p2 != NULL);
  init__picoquic_packet_t(p2);
  param1->retransmit_newest = p1;
  param1->retransmit_oldest = p1;
  param1->retransmitted_newest = p2;
  param1->retransmitted_oldest = p2;
  param1->ack_needed = dummy__unsigned_int();
}

inline void init__picoquic_path_t(picoquic_path_t *param1)
{
  param1->peer_addr_len = dummy__int();
  param1->local_addr_len = dummy__int();
  param1->if_index_local = dummy__unsigned_long();
  param1->challenge = dummy__uint64_t();
  param1->challenge_time = dummy__uint64_t();
  param1->challenge_response[0] = dummy__uint8_t();
  param1->challenge_response[1] = dummy__uint8_t();
  param1->challenge_response[2] = dummy__uint8_t();
  param1->challenge_response[3] = dummy__uint8_t();
  param1->challenge_response[4] = dummy__uint8_t();
  param1->challenge_response[5] = dummy__uint8_t();
  param1->challenge_response[6] = dummy__uint8_t();
  param1->challenge_response[7] = dummy__uint8_t();
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
  param1->reset_secret[0] = dummy__uint8_t();
  param1->reset_secret[1] = dummy__uint8_t();
  param1->reset_secret[2] = dummy__uint8_t();
  param1->reset_secret[3] = dummy__uint8_t();
  param1->reset_secret[4] = dummy__uint8_t();
  param1->reset_secret[5] = dummy__uint8_t();
  param1->reset_secret[6] = dummy__uint8_t();
  param1->reset_secret[7] = dummy__uint8_t();
  param1->reset_secret[8] = dummy__uint8_t();
  param1->reset_secret[9] = dummy__uint8_t();
  param1->reset_secret[10] = dummy__uint8_t();
  param1->reset_secret[11] = dummy__uint8_t();
  param1->reset_secret[12] = dummy__uint8_t();
  param1->reset_secret[13] = dummy__uint8_t();
  param1->reset_secret[14] = dummy__uint8_t();
  param1->reset_secret[15] = dummy__uint8_t();
}

inline void init__picoquic_packet_t(picoquic_packet_t *param1)
{
  param1->previous_packet = NULL;
  param1->next_packet = NULL;
  param1->send_path = NULL;
  param1->sequence_number = dummy__uint64_t();
  param1->send_time = dummy__uint64_t();
  param1->delivered_prior = dummy__uint64_t();
  param1->delivered_time_prior = dummy__uint64_t();
  param1->delivered_sent_prior = dummy__uint64_t();
  param1->length = dummy__uint32_t();
  param1->send_length = dummy__uint32_t();
  param1->checksum_overhead = dummy__uint32_t();
  param1->offset = dummy__uint32_t();
  param1->ptype = dummy__picoquic_packet_type_enum();
  param1->pc = dummy__picoquic_packet_context_enum();
  param1->is_pure_ack = dummy__unsigned_int();
  param1->contains_crypto = dummy__unsigned_int();
  param1->is_congestion_controlled = dummy__unsigned_int();
  param1->has_plugin_frames = dummy__unsigned_int();
  param1->is_mtu_probe = dummy__unsigned_int();
  param1->delivered_app_limited = dummy__unsigned_int();
  param1->has_handshake_done = dummy__unsigned_int();
}

inline void init__picoquic_packet_header(picoquic_packet_header *param1)
{
  init__picoquic_connection_id_t(&param1->dest_cnx_id);
  init__picoquic_connection_id_t(&param1->srce_cnx_id);
  param1->pn = dummy__uint32_t();
  param1->vn = dummy__uint32_t();
  param1->offset = dummy__uint32_t();
  param1->pn_offset = dummy__uint32_t();
  param1->pnmask = dummy__uint64_t();
  param1->pn64 = dummy__uint64_t();
  param1->payload_length = dummy__uint16_t();
  param1->version_index = dummy__int();
  param1->epoch = dummy__int();
  param1->spin = dummy__unsigned_int();
  param1->spin_vec = dummy__unsigned_int();
  param1->has_spin_bit = dummy__unsigned_int();
  param1->token_length = dummy__uint32_t();
  param1->token_offset = dummy__uint32_t();
}

inline void assume_cp__picoquic_connection_id_t(picoquic_connection_id_t *src, picoquic_connection_id_t *dst)
{
  dst->id[0] = src->id[0];
  dst->id[1] = src->id[1];
  dst->id[2] = src->id[2];
  dst->id[3] = src->id[3];
  dst->id[4] = src->id[4];
  dst->id[5] = src->id[5];
  dst->id[6] = src->id[6];
  dst->id[7] = src->id[7];
  dst->id[8] = src->id[8];
  dst->id[9] = src->id[9];
  dst->id[10] = src->id[10];
  dst->id[11] = src->id[11];
  dst->id[12] = src->id[12];
  dst->id[13] = src->id[13];
  dst->id[14] = src->id[14];
  dst->id[15] = src->id[15];
  dst->id[16] = src->id[16];
  dst->id[17] = src->id[17];
  dst->id[18] = src->id[18];
  dst->id[19] = src->id[19];
  dst->id_len = src->id_len;
}

inline void assume_cp__picoquic_tp_preferred_address_t(picoquic_tp_preferred_address_t *src, picoquic_tp_preferred_address_t *dst)
{
  dst->ipv4_address[0] = src->ipv4_address[0];
  dst->ipv4_address[1] = src->ipv4_address[1];
  dst->ipv4_address[2] = src->ipv4_address[2];
  dst->ipv4_address[3] = src->ipv4_address[3];
  dst->ipv4_port = src->ipv4_port;
  dst->ipv6_address[0] = src->ipv6_address[0];
  dst->ipv6_address[1] = src->ipv6_address[1];
  dst->ipv6_address[2] = src->ipv6_address[2];
  dst->ipv6_address[3] = src->ipv6_address[3];
  dst->ipv6_address[4] = src->ipv6_address[4];
  dst->ipv6_address[5] = src->ipv6_address[5];
  dst->ipv6_address[6] = src->ipv6_address[6];
  dst->ipv6_address[7] = src->ipv6_address[7];
  dst->ipv6_address[8] = src->ipv6_address[8];
  dst->ipv6_address[9] = src->ipv6_address[9];
  dst->ipv6_address[10] = src->ipv6_address[10];
  dst->ipv6_address[11] = src->ipv6_address[11];
  dst->ipv6_address[12] = src->ipv6_address[12];
  dst->ipv6_address[13] = src->ipv6_address[13];
  dst->ipv6_address[14] = src->ipv6_address[14];
  dst->ipv6_address[15] = src->ipv6_address[15];
  dst->ipv6_port = src->ipv6_port;
  assume_cp__picoquic_connection_id_t(&src->connection_id, &dst->connection_id);
  dst->stateless_reset_token[0] = src->stateless_reset_token[0];
  dst->stateless_reset_token[1] = src->stateless_reset_token[1];
  dst->stateless_reset_token[2] = src->stateless_reset_token[2];
  dst->stateless_reset_token[3] = src->stateless_reset_token[3];
  dst->stateless_reset_token[4] = src->stateless_reset_token[4];
  dst->stateless_reset_token[5] = src->stateless_reset_token[5];
  dst->stateless_reset_token[6] = src->stateless_reset_token[6];
  dst->stateless_reset_token[7] = src->stateless_reset_token[7];
  dst->stateless_reset_token[8] = src->stateless_reset_token[8];
  dst->stateless_reset_token[9] = src->stateless_reset_token[9];
  dst->stateless_reset_token[10] = src->stateless_reset_token[10];
  dst->stateless_reset_token[11] = src->stateless_reset_token[11];
  dst->stateless_reset_token[12] = src->stateless_reset_token[12];
  dst->stateless_reset_token[13] = src->stateless_reset_token[13];
  dst->stateless_reset_token[14] = src->stateless_reset_token[14];
  dst->stateless_reset_token[15] = src->stateless_reset_token[15];
}

inline void assume_cp__picoquic_tp_t(picoquic_tp_t *src, picoquic_tp_t *dst)
{
  assume_cp__picoquic_connection_id_t(&src->original_destination_connection_id, &dst->original_destination_connection_id);
  dst->max_idle_timeout = src->max_idle_timeout;
  dst->max_packet_size = src->max_packet_size;
  dst->initial_max_data = src->initial_max_data;
  dst->initial_max_stream_data_bidi_local = src->initial_max_stream_data_bidi_local;
  dst->initial_max_stream_data_bidi_remote = src->initial_max_stream_data_bidi_remote;
  dst->initial_max_stream_data_uni = src->initial_max_stream_data_uni;
  dst->initial_max_streams_bidi = src->initial_max_streams_bidi;
  dst->initial_max_streams_uni = src->initial_max_streams_uni;
  dst->ack_delay_exponent = src->ack_delay_exponent;
  dst->max_ack_delay = src->max_ack_delay;
  dst->disable_active_migration = src->disable_active_migration;
  assume_cp__picoquic_tp_preferred_address_t(&src->preferred_address, &dst->preferred_address);
  dst->active_connection_id_limit = src->active_connection_id_limit;
  assume_cp__picoquic_connection_id_t(&src->initial_source_connection_id, &dst->initial_source_connection_id);
  assume_cp__picoquic_connection_id_t(&src->retry_source_connection_id, &dst->retry_source_connection_id);
}

inline void assume_cp__picoquic_cnx_t(picoquic_cnx_t *src, picoquic_cnx_t *dst)
{
  dst->quic = NULL;
  dst->next_in_table = NULL;
  dst->previous_in_table = NULL;
  dst->first_cnx_id = NULL;
  dst->first_net_id = NULL;
  dst->proposed_version = src->proposed_version;
  dst->version_index = src->version_index;
  dst->is_0RTT_accepted = src->is_0RTT_accepted;
  dst->remote_parameters_received = src->remote_parameters_received;
  dst->current_spin = src->current_spin;
  dst->client_mode = src->client_mode;
  dst->prev_spin = src->prev_spin;
  dst->spin_vec = src->spin_vec;
  dst->spin_edge = src->spin_edge;
  dst->spin_last_trigger = src->spin_last_trigger;
  dst->key_phase_enc = src->key_phase_enc;
  dst->key_phase_dec = src->key_phase_dec;
  dst->zero_rtt_data_accepted = src->zero_rtt_data_accepted;
  dst->one_rtt_data_acknowledged = src->one_rtt_data_acknowledged;
  dst->processed_transport_parameter = src->processed_transport_parameter;
  assume_cp__picoquic_tp_t(&src->local_parameters, &dst->local_parameters);
  assume_cp__picoquic_tp_t(&src->remote_parameters, &dst->remote_parameters);
  dst->sni = NULL;
  dst->alpn = NULL;
  dst->max_early_data_size = src->max_early_data_size;
  dst->callback_fn = NULL;
  dst->callback_ctx = NULL;
  dst->cnx_state = src->cnx_state;
  assume_cp__picoquic_connection_id_t(&src->initial_cnxid, &dst->initial_cnxid);
  dst->start_time = src->start_time;
  dst->application_error = src->application_error;
  dst->local_error = src->local_error;
  dst->remote_application_error = src->remote_application_error;
  dst->remote_error = src->remote_error;
  dst->offending_frame_type = src->offending_frame_type;
  dst->retry_token_length = src->retry_token_length;
  dst->handshake_done = src->handshake_done;
  dst->handshake_done_sent = src->handshake_done_sent;
  dst->handshake_done_acked = src->handshake_done_acked;
  dst->next_wake_time = src->next_wake_time;
  dst->next_by_wake_time = NULL;
  dst->previous_by_wake_time = NULL;
  dst->tls_ctx = NULL;
  dst->tls_sendbuf = NULL;
  dst->psk_cipher_suite_id = src->psk_cipher_suite_id;
  //dst->tls_stream;
  //dst->crypto_context;
  dst->latest_progress_time = src->latest_progress_time;
  dst->nb_bytes_queued = src->nb_bytes_queued;
  dst->nb_path_challenge_sent = src->nb_path_challenge_sent;
  dst->nb_path_response_received = src->nb_path_response_received;
  dst->nb_zero_rtt_sent = src->nb_zero_rtt_sent;
  dst->nb_zero_rtt_acked = src->nb_zero_rtt_acked;
  dst->nb_retransmission_total = src->nb_retransmission_total;
  dst->nb_spurious = src->nb_spurious;
  dst->congestion_alg = NULL;
  dst->data_sent = src->data_sent;
  dst->data_received = src->data_received;
  dst->maxdata_local = src->maxdata_local;
  dst->maxdata_remote = src->maxdata_remote;
  dst->max_stream_id_bidir_local = src->max_stream_id_bidir_local;
  dst->max_stream_id_bidir_local_computed = src->max_stream_id_bidir_local_computed;
  dst->max_stream_id_unidir_local = src->max_stream_id_unidir_local;
  dst->max_stream_id_unidir_local_computed = src->max_stream_id_unidir_local_computed;
  dst->max_stream_id_bidir_remote = src->max_stream_id_bidir_remote;
  dst->max_stream_id_unidir_remote = src->max_stream_id_unidir_remote;
  dst->first_stream = NULL;
  dst->last_visited_stream_id = src->last_visited_stream_id;
  dst->last_visited_plugin_stream_id = src->last_visited_plugin_stream_id;
  dst->keep_alive_interval = src->keep_alive_interval;
  dst->nb_paths = src->nb_paths;
  dst->nb_path_alloc = src->nb_path_alloc;

  dst->path = (picoquic_path_t**) malloc(sizeof(picoquic_path_t*)*dst->nb_paths);
  for (int i=0; i<dst->nb_paths; i++) {
    dst->path[i] = (picoquic_path_t*) malloc(sizeof(picoquic_path_t));
    assume_cp__picoquic_path_t(src->path[i], dst->path[i]);
  }

  dst->reserved_frames = NULL;
  dst->retry_frames = NULL;
  for (int i=0; i<picoquic_nb_packet_context; i++)
    dst->rtx_frames[i] = NULL;
  dst->first_drr = NULL;
  dst->core_rate = src->core_rate;
  dst->wake_now = src->wake_now;
  dst->plugin_requested = src->plugin_requested;
  // param1->pids_to_request
  dst->first_plugin_stream = NULL;
  dst->ops = NULL;
  dst->plugins = NULL;
  dst->metadata = NULL;
  dst->protoop_inputc = src->protoop_inputc;
  for (int i=0; i<PROTOOPARGS_MAX; i++) {
    dst->protoop_inputv[i] = 0;
    dst->protoop_outputv[i] = 0;
  }
  dst->protoop_outputc_callee = src->protoop_outputc_callee;
  dst->protoop_output = 0;
  dst->current_protoop = NULL;
  dst->current_anchor = pluglet_replace;
  dst->current_plugin = NULL;
  dst->previous_plugin_in_replace = NULL;
}

inline void assume_cp__picoquic_sack_item_t(picoquic_sack_item_t *src, picoquic_sack_item_t *dst)
{
  dst->next_sack = NULL;
  dst->start_of_sack_range = src->start_of_sack_range;
  dst->end_of_sack_range = src->end_of_sack_range;
}

inline void assume_cp__picoquic_packet_context_t(picoquic_packet_context_t *src, picoquic_packet_context_t *dst)
{
  dst->send_sequence = src->send_sequence;

  picoquic_sack_item_t *src_runner = &src->first_sack_item, *si, *runner, *head;
  while(src_runner != NULL) {
    si = (picoquic_sack_item_t*) malloc(sizeof(picoquic_sack_item_t));
    assume_cp__picoquic_sack_item_t(src_runner, si);
    if (src_runner != &src->first_sack_item)
      runner->next_sack = si;
    else
      head = si;
    runner = si;
    src_runner = src_runner->next_sack;
  }

  dst->first_sack_item.next_sack = head->next_sack;
  dst->first_sack_item.start_of_sack_range = head->start_of_sack_range;
  dst->first_sack_item.end_of_sack_range = head->end_of_sack_range;

  dst->time_stamp_largest_received = src->time_stamp_largest_received;
  dst->highest_ack_sent = src->highest_ack_sent;
  dst->highest_ack_time = src->highest_ack_time;
  dst->ack_delay_local = src->ack_delay_local;
  dst->latest_progress_time = src->latest_progress_time;
  dst->nb_retransmit = src->nb_retransmit;
  dst->latest_retransmit_time = src->latest_retransmit_time;
  dst->latest_retransmit_cc_notification_time = src->latest_retransmit_cc_notification_time;
  dst->highest_acknowledged = src->highest_acknowledged;
  dst->latest_time_acknowledged = src->latest_time_acknowledged;
  dst->retransmit_newest = (picoquic_packet_t*) malloc(sizeof(picoquic_packet_t));
  dst->retransmit_oldest = (picoquic_packet_t*) malloc(sizeof(picoquic_packet_t));
  dst->retransmitted_newest = (picoquic_packet_t*) malloc(sizeof(picoquic_packet_t));
  dst->retransmitted_oldest = (picoquic_packet_t*) malloc(sizeof(picoquic_packet_t));
  assume_cp__picoquic_packet_t(src->retransmit_newest, dst->retransmit_newest);
  assume_cp__picoquic_packet_t(src->retransmit_oldest, dst->retransmit_oldest);
  assume_cp__picoquic_packet_t(src->retransmitted_newest, dst->retransmitted_newest);
  assume_cp__picoquic_packet_t(src->retransmitted_oldest, dst->retransmitted_oldest);
  dst->ack_needed = src->ack_needed;
}

inline void assume_cp__picoquic_path_t(picoquic_path_t *src, picoquic_path_t *dst)
{
  dst->peer_addr_len = src->peer_addr_len;
  dst->local_addr_len = src->local_addr_len;
  dst->if_index_local = src->if_index_local;
  dst->challenge = src->challenge;
  dst->challenge_time = src->challenge_time;
  dst->challenge_response[0] = src->challenge_response[0];
  dst->challenge_response[1] = src->challenge_response[1];
  dst->challenge_response[2] = src->challenge_response[2];
  dst->challenge_response[3] = src->challenge_response[3];
  dst->challenge_response[4] = src->challenge_response[4];
  dst->challenge_response[5] = src->challenge_response[5];
  dst->challenge_response[6] = src->challenge_response[6];
  dst->challenge_response[7] = src->challenge_response[7];
  dst->challenge_repeat_count = src->challenge_repeat_count;
  dst->mtu_probe_sent = src->mtu_probe_sent;
  dst->challenge_verified = src->challenge_verified;
  dst->challenge_response_to_send = src->challenge_response_to_send;
  dst->ping_received = src->ping_received;
  dst->last_bw_estimate_path_limited = src->last_bw_estimate_path_limited;
  dst->max_ack_delay = src->max_ack_delay;
  dst->rtt_sample = src->rtt_sample;
  dst->smoothed_rtt = src->smoothed_rtt;
  dst->rtt_variant = src->rtt_variant;
  dst->retransmit_timer = src->retransmit_timer;
  dst->rtt_min = src->rtt_min;
  dst->max_spurious_rtt = src->max_spurious_rtt;
  dst->max_reorder_delay = src->max_reorder_delay;
  dst->max_reorder_gap = src->max_reorder_gap;
  dst->send_mtu = src->send_mtu;
  dst->send_mtu_max_tried = src->send_mtu_max_tried;
  dst->cwin = src->cwin;
  dst->bytes_in_transit = src->bytes_in_transit;
  dst->pacing_evaluation_time = src->pacing_evaluation_time;
  dst->pacing_bucket_nanosec = src->pacing_bucket_nanosec;
  dst->pacing_bucket_max = src->pacing_bucket_max;
  dst->pacing_packet_time_nanosec = src->pacing_packet_time_nanosec;
  dst->pacing_packet_time_microsec = src->pacing_packet_time_microsec;
  dst->nb_pkt_sent = src->nb_pkt_sent;
  dst->delivered = src->delivered;
  dst->delivered_last = src->delivered_last;
  dst->delivered_time_last = src->delivered_time_last;
  dst->delivered_sent_last = src->delivered_sent_last;
  dst->delivered_limited_index = src->delivered_limited_index;
  dst->delivered_last_packet = src->delivered_last_packet;
  dst->bandwidth_estimate = src->bandwidth_estimate;
  dst->received = src->received;
  dst->receive_rate_epoch = src->receive_rate_epoch;
  dst->received_prior = src->received_prior;
  dst->receive_rate_estimate = src->receive_rate_estimate;
  dst->receive_rate_max = src->receive_rate_max;
  assume_cp__picoquic_connection_id_t(&src->local_cnxid, &dst->local_cnxid);
  assume_cp__picoquic_connection_id_t(&src->remote_cnxid, &dst->remote_cnxid);
  dst->reset_secret[0] = src->reset_secret[0];
  dst->reset_secret[1] = src->reset_secret[1];
  dst->reset_secret[2] = src->reset_secret[2];
  dst->reset_secret[3] = src->reset_secret[3];
  dst->reset_secret[4] = src->reset_secret[4];
  dst->reset_secret[5] = src->reset_secret[5];
  dst->reset_secret[6] = src->reset_secret[6];
  dst->reset_secret[7] = src->reset_secret[7];
  dst->reset_secret[8] = src->reset_secret[8];
  dst->reset_secret[9] = src->reset_secret[9];
  dst->reset_secret[10] = src->reset_secret[10];
  dst->reset_secret[11] = src->reset_secret[11];
  dst->reset_secret[12] = src->reset_secret[12];
  dst->reset_secret[13] = src->reset_secret[13];
  dst->reset_secret[14] = src->reset_secret[14];
  dst->reset_secret[15] = src->reset_secret[15];
}

inline void assume_cp__picoquic_packet_t(picoquic_packet_t *src, picoquic_packet_t *dst)
{
  dst->sequence_number = src->sequence_number;
  dst->send_time = src->send_time;
  dst->delivered_prior = src->delivered_prior;
  dst->delivered_time_prior = src->delivered_time_prior;
  dst->delivered_sent_prior = src->delivered_sent_prior;
  dst->length = src->length;
  dst->send_length = src->send_length;
  dst->checksum_overhead = src->checksum_overhead;
  dst->offset = src->offset;
  dst->ptype = src->ptype;
  dst->pc = src->pc;
  dst->is_pure_ack = src->is_pure_ack;
  dst->contains_crypto = src->contains_crypto;
  dst->is_congestion_controlled = src->is_congestion_controlled;
  dst->has_plugin_frames = src->has_plugin_frames;
  dst->is_mtu_probe = src->is_mtu_probe;
  dst->delivered_app_limited = src->delivered_app_limited;
  dst->has_handshake_done = src->has_handshake_done;
}

inline void assume_cp__picoquic_packet_header(picoquic_packet_header *src, picoquic_packet_header *dst)
{
  assume_cp__picoquic_connection_id_t(&src->dest_cnx_id, &dst->dest_cnx_id);
  assume_cp__picoquic_connection_id_t(&src->srce_cnx_id, &dst->srce_cnx_id);
  dst->pn = src->pn;
  dst->vn = src->vn;
  dst->offset = src->offset;
  dst->pn_offset = src->pn_offset;
  dst->pnmask = src->pnmask;
  dst->pn64 = src->pn64;
  dst->payload_length = src->payload_length;
  dst->version_index = src->version_index;
  dst->epoch = src->epoch;
  dst->spin = src->spin;
  dst->spin_vec = src->spin_vec;
  dst->has_spin_bit = src->has_spin_bit;
  dst->token_length = src->token_length;
  dst->token_offset = src->token_offset;
}

inline void assert_cp__picoquic_connection_id_t(picoquic_connection_id_t *param1, picoquic_connection_id_t *param2, uint64_t flags)
{
  sassert(param1 != param2);
  unsigned int cond = 1;
  cond &= param1->id[0] == param2->id[0];
  cond &= param1->id[1] == param2->id[1];
  cond &= param1->id[2] == param2->id[2];
  cond &= param1->id[3] == param2->id[3];
  cond &= param1->id[4] == param2->id[4];
  cond &= param1->id[5] == param2->id[5];
  cond &= param1->id[6] == param2->id[6];
  cond &= param1->id[7] == param2->id[7];
  cond &= param1->id[8] == param2->id[8];
  cond &= param1->id[9] == param2->id[9];
  cond &= param1->id[10] == param2->id[10];
  cond &= param1->id[11] == param2->id[11];
  cond &= param1->id[12] == param2->id[12];
  cond &= param1->id[13] == param2->id[13];
  cond &= param1->id[14] == param2->id[14];
  cond &= param1->id[15] == param2->id[15];
  cond &= param1->id[16] == param2->id[16];
  cond &= param1->id[17] == param2->id[17];
  cond &= param1->id[18] == param2->id[18];
  cond &= param1->id[19] == param2->id[19];
  cond &= (flags & ASSERT_PICOQUIC_CONNECTION_ID_T__ID_LEN) || (param1->id_len == param2->id_len);
  sassert(cond);
}

inline void assert_cp__picoquic_tp_preferred_address_t(picoquic_tp_preferred_address_t *param1, picoquic_tp_preferred_address_t *param2, uint64_t flags)
{
  sassert(param1 != param2);
  unsigned int cond = 1;
  cond &= param1->ipv4_address[0] == param2->ipv4_address[0];
  cond &= param1->ipv4_address[1] == param2->ipv4_address[1];
  cond &= param1->ipv4_address[2] == param2->ipv4_address[2];
  cond &= param1->ipv4_address[3] == param2->ipv4_address[3];
  cond &= (flags & ASSERT_PICOQUIC_TP_PREFERRED_ADDRESS_T__IPV4_PORT) || (param1->ipv4_port == param2->ipv4_port);
  cond &= param1->ipv6_address[0] == param2->ipv6_address[0];
  cond &= param1->ipv6_address[1] == param2->ipv6_address[1];
  cond &= param1->ipv6_address[2] == param2->ipv6_address[2];
  cond &= param1->ipv6_address[3] == param2->ipv6_address[3];
  cond &= param1->ipv6_address[4] == param2->ipv6_address[4];
  cond &= param1->ipv6_address[5] == param2->ipv6_address[5];
  cond &= param1->ipv6_address[6] == param2->ipv6_address[6];
  cond &= param1->ipv6_address[7] == param2->ipv6_address[7];
  cond &= param1->ipv6_address[8] == param2->ipv6_address[8];
  cond &= param1->ipv6_address[9] == param2->ipv6_address[9];
  cond &= param1->ipv6_address[10] == param2->ipv6_address[10];
  cond &= param1->ipv6_address[11] == param2->ipv6_address[11];
  cond &= param1->ipv6_address[12] == param2->ipv6_address[12];
  cond &= param1->ipv6_address[13] == param2->ipv6_address[13];
  cond &= param1->ipv6_address[14] == param2->ipv6_address[14];
  cond &= param1->ipv6_address[15] == param2->ipv6_address[15];
  cond &= (flags & ASSERT_PICOQUIC_TP_PREFERRED_ADDRESS_T__IPV6_PORT) || (param1->ipv6_port == param2->ipv6_port);
  assert_cp__picoquic_connection_id_t(&param1->connection_id, &param2->connection_id, 0);
  cond &= param1->stateless_reset_token[0] == param2->stateless_reset_token[0];
  cond &= param1->stateless_reset_token[1] == param2->stateless_reset_token[1];
  cond &= param1->stateless_reset_token[2] == param2->stateless_reset_token[2];
  cond &= param1->stateless_reset_token[3] == param2->stateless_reset_token[3];
  cond &= param1->stateless_reset_token[4] == param2->stateless_reset_token[4];
  cond &= param1->stateless_reset_token[5] == param2->stateless_reset_token[5];
  cond &= param1->stateless_reset_token[6] == param2->stateless_reset_token[6];
  cond &= param1->stateless_reset_token[7] == param2->stateless_reset_token[7];
  cond &= param1->stateless_reset_token[8] == param2->stateless_reset_token[8];
  cond &= param1->stateless_reset_token[9] == param2->stateless_reset_token[9];
  cond &= param1->stateless_reset_token[10] == param2->stateless_reset_token[10];
  cond &= param1->stateless_reset_token[11] == param2->stateless_reset_token[11];
  cond &= param1->stateless_reset_token[12] == param2->stateless_reset_token[12];
  cond &= param1->stateless_reset_token[13] == param2->stateless_reset_token[13];
  cond &= param1->stateless_reset_token[14] == param2->stateless_reset_token[14];
  cond &= param1->stateless_reset_token[15] == param2->stateless_reset_token[15];
  sassert(cond);
}

inline void assert_cp__picoquic_tp_t(picoquic_tp_t *param1, picoquic_tp_t *param2, uint64_t flags)
{
  sassert(param1 != param2);
  unsigned int cond = 1;
  assert_cp__picoquic_connection_id_t(&param1->original_destination_connection_id, &param2->original_destination_connection_id, 0);
  cond &= (flags & ASSERT_PICOQUIC_TP_T__MAX_IDLE_TIMEOUT) || (param1->max_idle_timeout == param2->max_idle_timeout);
  cond &= (flags & ASSERT_PICOQUIC_TP_T__MAX_PACKET_SIZE) || (param1->max_packet_size == param2->max_packet_size);
  cond &= (flags & ASSERT_PICOQUIC_TP_T__INITIAL_MAX_DATA) || (param1->initial_max_data == param2->initial_max_data);
  cond &= (flags & ASSERT_PICOQUIC_TP_T__INITIAL_MAX_STREAM_DATA_BIDI_LOCAL) || (param1->initial_max_stream_data_bidi_local == param2->initial_max_stream_data_bidi_local);
  cond &= (flags & ASSERT_PICOQUIC_TP_T__INITIAL_MAX_STREAM_DATA_BIDI_REMOTE) || (param1->initial_max_stream_data_bidi_remote == param2->initial_max_stream_data_bidi_remote);
  cond &= (flags & ASSERT_PICOQUIC_TP_T__INITIAL_MAX_STREAM_DATA_UNI) || (param1->initial_max_stream_data_uni == param2->initial_max_stream_data_uni);
  cond &= (flags & ASSERT_PICOQUIC_TP_T__INITIAL_MAX_STREAMS_BIDI) || (param1->initial_max_streams_bidi == param2->initial_max_streams_bidi);
  cond &= (flags & ASSERT_PICOQUIC_TP_T__INITIAL_MAX_STREAMS_UNI) || (param1->initial_max_streams_uni == param2->initial_max_streams_uni);
  cond &= (flags & ASSERT_PICOQUIC_TP_T__ACK_DELAY_EXPONENT) || (param1->ack_delay_exponent == param2->ack_delay_exponent);
  cond &= (flags & ASSERT_PICOQUIC_TP_T__MAX_ACK_DELAY) || (param1->max_ack_delay == param2->max_ack_delay);
  cond &= (flags & ASSERT_PICOQUIC_TP_T__DISABLE_ACTIVE_MIGRATION) || (param1->disable_active_migration == param2->disable_active_migration);
  assert_cp__picoquic_tp_preferred_address_t(&param1->preferred_address, &param2->preferred_address, 0);
  cond &= (flags & ASSERT_PICOQUIC_TP_T__ACTIVE_CONNECTION_ID_LIMIT) || (param1->active_connection_id_limit == param2->active_connection_id_limit);
  assert_cp__picoquic_connection_id_t(&param1->initial_source_connection_id, &param2->initial_source_connection_id, 0);
  assert_cp__picoquic_connection_id_t(&param1->retry_source_connection_id, &param2->retry_source_connection_id, 0);
  sassert(cond);
}

inline void assert_cp__picoquic_cnx_t(picoquic_cnx_t *param1, picoquic_cnx_t *param2, uint64_t flags)
{
  sassert(param1 != param2);
  unsigned int cond = 1;
  cond &= (flags & ASSERT_PICOQUIC_CNX_T__PROPOSED_VERSION) || (param1->proposed_version == param2->proposed_version);
  cond &= (flags & ASSERT_PICOQUIC_CNX_T__VERSION_INDEX) || (param1->version_index == param2->version_index);
  cond &= (flags & ASSERT_PICOQUIC_CNX_T__IS_0RTT_ACCEPTED) || (param1->is_0RTT_accepted == param2->is_0RTT_accepted);
  cond &= (flags & ASSERT_PICOQUIC_CNX_T__REMOTE_PARAMETERS_RECEIVED) || (param1->remote_parameters_received == param2->remote_parameters_received);
  cond &= (flags & ASSERT_PICOQUIC_CNX_T__CURRENT_SPIN) || (param1->current_spin == param2->current_spin);
  cond &= (flags & ASSERT_PICOQUIC_CNX_T__CLIENT_MODE) || (param1->client_mode == param2->client_mode);
  cond &= (flags & ASSERT_PICOQUIC_CNX_T__PREV_SPIN) || (param1->prev_spin == param2->prev_spin);
  cond &= (flags & ASSERT_PICOQUIC_CNX_T__SPIN_VEC) || (param1->spin_vec == param2->spin_vec);
  cond &= (flags & ASSERT_PICOQUIC_CNX_T__SPIN_EDGE) || (param1->spin_edge == param2->spin_edge);
  cond &= (flags & ASSERT_PICOQUIC_CNX_T__SPIN_LAST_TRIGGER) || (param1->spin_last_trigger == param2->spin_last_trigger);
  cond &= (flags & ASSERT_PICOQUIC_CNX_T__KEY_PHASE_ENC) || (param1->key_phase_enc == param2->key_phase_enc);
  cond &= (flags & ASSERT_PICOQUIC_CNX_T__KEY_PHASE_DEC) || (param1->key_phase_dec == param2->key_phase_dec);
  cond &= (flags & ASSERT_PICOQUIC_CNX_T__ZERO_RTT_DATA_ACCEPTED) || (param1->zero_rtt_data_accepted == param2->zero_rtt_data_accepted);
  cond &= (flags & ASSERT_PICOQUIC_CNX_T__ONE_RTT_DATA_ACKNOWLEDGED) || (param1->one_rtt_data_acknowledged == param2->one_rtt_data_acknowledged);
  cond &= (flags & ASSERT_PICOQUIC_CNX_T__PROCESSED_TRANSPORT_PARAMETER) || (param1->processed_transport_parameter == param2->processed_transport_parameter);
  assert_cp__picoquic_tp_t(&param1->local_parameters, &param2->local_parameters, 0);
  assert_cp__picoquic_tp_t(&param1->remote_parameters, &param2->remote_parameters, 0);
  cond &= (flags & ASSERT_PICOQUIC_CNX_T__MAX_EARLY_DATA_SIZE) || (param1->max_early_data_size == param2->max_early_data_size);
  assert_cp__picoquic_connection_id_t(&param1->initial_cnxid, &param2->initial_cnxid, 0);
  cond &= (flags & ASSERT_PICOQUIC_CNX_T__START_TIME) || (param1->start_time == param2->start_time);
  cond &= (flags & ASSERT_PICOQUIC_CNX_T__APPLICATION_ERROR) || (param1->application_error == param2->application_error);
  cond &= (flags & ASSERT_PICOQUIC_CNX_T__LOCAL_ERROR) || (param1->local_error == param2->local_error);
  cond &= (flags & ASSERT_PICOQUIC_CNX_T__REMOTE_APPLICATION_ERROR) || (param1->remote_application_error == param2->remote_application_error);
  cond &= (flags & ASSERT_PICOQUIC_CNX_T__REMOTE_ERROR) || (param1->remote_error == param2->remote_error);
  cond &= (flags & ASSERT_PICOQUIC_CNX_T__OFFENDING_FRAME_TYPE) || (param1->offending_frame_type == param2->offending_frame_type);
  cond &= (flags & ASSERT_PICOQUIC_CNX_T__RETRY_TOKEN_LENGTH) || (param1->retry_token_length == param2->retry_token_length);
  cond &= (flags & ASSERT_PICOQUIC_CNX_T__HANDSHAKE_DONE) || (param1->handshake_done == param2->handshake_done);
  cond &= (flags & ASSERT_PICOQUIC_CNX_T__HANDSHAKE_DONE_SENT) || (param1->handshake_done_sent == param2->handshake_done_sent);
  cond &= (flags & ASSERT_PICOQUIC_CNX_T__HANDSHAKE_DONE_ACKED) || (param1->handshake_done_acked == param2->handshake_done_acked);
  cond &= (flags & ASSERT_PICOQUIC_CNX_T__NEXT_WAKE_TIME) || (param1->next_wake_time == param2->next_wake_time);
  cond &= (flags & ASSERT_PICOQUIC_CNX_T__PSK_CIPHER_SUITE_ID) || (param1->psk_cipher_suite_id == param2->psk_cipher_suite_id);
  cond &= (flags & ASSERT_PICOQUIC_CNX_T__LATEST_PROGRESS_TIME) || (param1->latest_progress_time == param2->latest_progress_time);
  cond &= (flags & ASSERT_PICOQUIC_CNX_T__NB_BYTES_QUEUED) || (param1->nb_bytes_queued == param2->nb_bytes_queued);
  cond &= (flags & ASSERT_PICOQUIC_CNX_T__NB_PATH_CHALLENGE_SENT) || (param1->nb_path_challenge_sent == param2->nb_path_challenge_sent);
  cond &= (flags & ASSERT_PICOQUIC_CNX_T__NB_PATH_RESPONSE_RECEIVED) || (param1->nb_path_response_received == param2->nb_path_response_received);
  cond &= (flags & ASSERT_PICOQUIC_CNX_T__NB_ZERO_RTT_SENT) || (param1->nb_zero_rtt_sent == param2->nb_zero_rtt_sent);
  cond &= (flags & ASSERT_PICOQUIC_CNX_T__NB_ZERO_RTT_ACKED) || (param1->nb_zero_rtt_acked == param2->nb_zero_rtt_acked);
  cond &= (flags & ASSERT_PICOQUIC_CNX_T__NB_RETRANSMISSION_TOTAL) || (param1->nb_retransmission_total == param2->nb_retransmission_total);
  cond &= (flags & ASSERT_PICOQUIC_CNX_T__NB_SPURIOUS) || (param1->nb_spurious == param2->nb_spurious);
  cond &= (flags & ASSERT_PICOQUIC_CNX_T__DATA_SENT) || (param1->data_sent == param2->data_sent);
  cond &= (flags & ASSERT_PICOQUIC_CNX_T__DATA_RECEIVED) || (param1->data_received == param2->data_received);
  cond &= (flags & ASSERT_PICOQUIC_CNX_T__MAXDATA_LOCAL) || (param1->maxdata_local == param2->maxdata_local);
  cond &= (flags & ASSERT_PICOQUIC_CNX_T__MAXDATA_REMOTE) || (param1->maxdata_remote == param2->maxdata_remote);
  cond &= (flags & ASSERT_PICOQUIC_CNX_T__MAX_STREAM_ID_BIDIR_LOCAL) || (param1->max_stream_id_bidir_local == param2->max_stream_id_bidir_local);
  cond &= (flags & ASSERT_PICOQUIC_CNX_T__MAX_STREAM_ID_BIDIR_LOCAL_COMPUTED) || (param1->max_stream_id_bidir_local_computed == param2->max_stream_id_bidir_local_computed);
  cond &= (flags & ASSERT_PICOQUIC_CNX_T__MAX_STREAM_ID_UNIDIR_LOCAL) || (param1->max_stream_id_unidir_local == param2->max_stream_id_unidir_local);
  cond &= (flags & ASSERT_PICOQUIC_CNX_T__MAX_STREAM_ID_UNIDIR_LOCAL_COMPUTED) || (param1->max_stream_id_unidir_local_computed == param2->max_stream_id_unidir_local_computed);
  cond &= (flags & ASSERT_PICOQUIC_CNX_T__MAX_STREAM_ID_BIDIR_REMOTE) || (param1->max_stream_id_bidir_remote == param2->max_stream_id_bidir_remote);
  cond &= (flags & ASSERT_PICOQUIC_CNX_T__MAX_STREAM_ID_UNIDIR_REMOTE) || (param1->max_stream_id_unidir_remote == param2->max_stream_id_unidir_remote);
  cond &= (flags & ASSERT_PICOQUIC_CNX_T__LAST_VISITED_STREAM_ID) || (param1->last_visited_stream_id == param2->last_visited_stream_id);
  cond &= (flags & ASSERT_PICOQUIC_CNX_T__LAST_VISITED_PLUGIN_STREAM_ID) || (param1->last_visited_plugin_stream_id == param2->last_visited_plugin_stream_id);
  cond &= (flags & ASSERT_PICOQUIC_CNX_T__KEEP_ALIVE_INTERVAL) || (param1->keep_alive_interval == param2->keep_alive_interval);
  cond &= (flags & ASSERT_PICOQUIC_CNX_T__NB_PATHS) || (param1->nb_paths == param2->nb_paths);
  cond &= (flags & ASSERT_PICOQUIC_CNX_T__NB_PATH_ALLOC) || (param1->nb_path_alloc == param2->nb_path_alloc);
  sassert(cond);
  for (int i=0; i<param1->nb_paths; i++)
    assert_cp__picoquic_path_t(param1->path[i], param2->path[i], ASSERT_NONE);
  cond &= (flags & ASSERT_PICOQUIC_CNX_T__CORE_RATE) || (param1->core_rate == param2->core_rate);
  cond &= (flags & ASSERT_PICOQUIC_CNX_T__WAKE_NOW) || (param1->wake_now == param2->wake_now);
  cond &= (flags & ASSERT_PICOQUIC_CNX_T__PLUGIN_REQUESTED) || (param1->plugin_requested == param2->plugin_requested);
  cond &= (flags & ASSERT_PICOQUIC_CNX_T__PROTOOP_INPUTC) || (param1->protoop_inputc == param2->protoop_inputc);
  cond &= (flags & ASSERT_PICOQUIC_CNX_T__PROTOOP_OUTPUTC_CALLEE) || (param1->protoop_outputc_callee == param2->protoop_outputc_callee);
  sassert(cond);
}

inline void assert_cp__picoquic_sack_item_t(picoquic_sack_item_t *param1, picoquic_sack_item_t *param2, uint64_t flags)
{
  sassert(param1 != param2);
  unsigned int cond = 1;
  cond &= (flags & ASSERT_PICOQUIC_SACK_ITEM_T__START_OF_SACK_RANGE) || (param1->start_of_sack_range == param2->start_of_sack_range);
  cond &= (flags & ASSERT_PICOQUIC_SACK_ITEM_T__END_OF_SACK_RANGE) || (param1->end_of_sack_range == param2->end_of_sack_range);
  sassert(cond);
}

inline void assert_cp__picoquic_packet_context_t(picoquic_packet_context_t *param1, picoquic_packet_context_t *param2, uint64_t flags)
{
  sassert(param1 != param2);
  unsigned int cond = 1;
  cond &= (flags & ASSERT_PICOQUIC_PACKET_CONTEXT_T__SEND_SEQUENCE) || (param1->send_sequence == param2->send_sequence);

  picoquic_sack_item_t *runner1 = &param1->first_sack_item, *runner2 = &param2->first_sack_item;
  while(runner1 != NULL && runner2 != NULL) {
    assert_cp__picoquic_sack_item_t(runner1, runner2, ASSERT_NONE);
    runner1 = runner1->next_sack;
    runner2 = runner2->next_sack;
  }
  cond &= runner1 == NULL && runner2 == NULL;

  cond &= (flags & ASSERT_PICOQUIC_PACKET_CONTEXT_T__TIME_STAMP_LARGEST_RECEIVED) || (param1->time_stamp_largest_received == param2->time_stamp_largest_received);
  cond &= (flags & ASSERT_PICOQUIC_PACKET_CONTEXT_T__HIGHEST_ACK_SENT) || (param1->highest_ack_sent == param2->highest_ack_sent);
  cond &= (flags & ASSERT_PICOQUIC_PACKET_CONTEXT_T__HIGHEST_ACK_TIME) || (param1->highest_ack_time == param2->highest_ack_time);
  cond &= (flags & ASSERT_PICOQUIC_PACKET_CONTEXT_T__ACK_DELAY_LOCAL) || (param1->ack_delay_local == param2->ack_delay_local);
  cond &= (flags & ASSERT_PICOQUIC_PACKET_CONTEXT_T__LATEST_PROGRESS_TIME) || (param1->latest_progress_time == param2->latest_progress_time);
  cond &= (flags & ASSERT_PICOQUIC_PACKET_CONTEXT_T__NB_RETRANSMIT) || (param1->nb_retransmit == param2->nb_retransmit);
  cond &= (flags & ASSERT_PICOQUIC_PACKET_CONTEXT_T__LATEST_RETRANSMIT_TIME) || (param1->latest_retransmit_time == param2->latest_retransmit_time);
  cond &= (flags & ASSERT_PICOQUIC_PACKET_CONTEXT_T__LATEST_RETRANSMIT_CC_NOTIFICATION_TIME) || (param1->latest_retransmit_cc_notification_time == param2->latest_retransmit_cc_notification_time);
  cond &= (flags & ASSERT_PICOQUIC_PACKET_CONTEXT_T__HIGHEST_ACKNOWLEDGED) || (param1->highest_acknowledged == param2->highest_acknowledged);
  cond &= (flags & ASSERT_PICOQUIC_PACKET_CONTEXT_T__LATEST_TIME_ACKNOWLEDGED) || (param1->latest_time_acknowledged == param2->latest_time_acknowledged);
  assert_cp__picoquic_packet_t(param1->retransmit_newest, param2->retransmit_newest, ASSERT_NONE);
  assert_cp__picoquic_packet_t(param1->retransmit_oldest, param2->retransmit_oldest, ASSERT_NONE);
  assert_cp__picoquic_packet_t(param1->retransmitted_newest, param2->retransmitted_newest, ASSERT_NONE);
  assert_cp__picoquic_packet_t(param1->retransmitted_oldest, param2->retransmitted_oldest, ASSERT_NONE);
  cond &= (flags & ASSERT_PICOQUIC_PACKET_CONTEXT_T__ACK_NEEDED) || (param1->ack_needed == param2->ack_needed);
  sassert(cond);
}

inline void assert_cp__picoquic_path_t(picoquic_path_t *param1, picoquic_path_t *param2, uint64_t flags)
{
  sassert(param1 != param2);
  unsigned int cond = 1;
  cond &= (flags & ASSERT_PICOQUIC_PATH_T__PEER_ADDR_LEN) || (param1->peer_addr_len == param2->peer_addr_len);
  cond &= (flags & ASSERT_PICOQUIC_PATH_T__LOCAL_ADDR_LEN) || (param1->local_addr_len == param2->local_addr_len);
  cond &= (flags & ASSERT_PICOQUIC_PATH_T__IF_INDEX_LOCAL) || (param1->if_index_local == param2->if_index_local);
  cond &= (flags & ASSERT_PICOQUIC_PATH_T__CHALLENGE) || (param1->challenge == param2->challenge);
  cond &= (flags & ASSERT_PICOQUIC_PATH_T__CHALLENGE_TIME) || (param1->challenge_time == param2->challenge_time);
  cond &= param1->challenge_response[0] == param2->challenge_response[0];
  cond &= param1->challenge_response[1] == param2->challenge_response[1];
  cond &= param1->challenge_response[2] == param2->challenge_response[2];
  cond &= param1->challenge_response[3] == param2->challenge_response[3];
  cond &= param1->challenge_response[4] == param2->challenge_response[4];
  cond &= param1->challenge_response[5] == param2->challenge_response[5];
  cond &= param1->challenge_response[6] == param2->challenge_response[6];
  cond &= param1->challenge_response[7] == param2->challenge_response[7];
  cond &= (flags & ASSERT_PICOQUIC_PATH_T__CHALLENGE_REPEAT_COUNT) || (param1->challenge_repeat_count == param2->challenge_repeat_count);
  cond &= (flags & ASSERT_PICOQUIC_PATH_T__MTU_PROBE_SENT) || (param1->mtu_probe_sent == param2->mtu_probe_sent);
  cond &= (flags & ASSERT_PICOQUIC_PATH_T__CHALLENGE_VERIFIED) || (param1->challenge_verified == param2->challenge_verified);
  cond &= (flags & ASSERT_PICOQUIC_PATH_T__CHALLENGE_RESPONSE_TO_SEND) || (param1->challenge_response_to_send == param2->challenge_response_to_send);
  cond &= (flags & ASSERT_PICOQUIC_PATH_T__PING_RECEIVED) || (param1->ping_received == param2->ping_received);
  cond &= (flags & ASSERT_PICOQUIC_PATH_T__LAST_BW_ESTIMATE_PATH_LIMITED) || (param1->last_bw_estimate_path_limited == param2->last_bw_estimate_path_limited);
  cond &= (flags & ASSERT_PICOQUIC_PATH_T__MAX_ACK_DELAY) || (param1->max_ack_delay == param2->max_ack_delay);
  cond &= (flags & ASSERT_PICOQUIC_PATH_T__RTT_SAMPLE) || (param1->rtt_sample == param2->rtt_sample);
  cond &= (flags & ASSERT_PICOQUIC_PATH_T__SMOOTHED_RTT) || (param1->smoothed_rtt == param2->smoothed_rtt);
  cond &= (flags & ASSERT_PICOQUIC_PATH_T__RTT_VARIANT) || (param1->rtt_variant == param2->rtt_variant);
  cond &= (flags & ASSERT_PICOQUIC_PATH_T__RETRANSMIT_TIMER) || (param1->retransmit_timer == param2->retransmit_timer);
  cond &= (flags & ASSERT_PICOQUIC_PATH_T__RTT_MIN) || (param1->rtt_min == param2->rtt_min);
  cond &= (flags & ASSERT_PICOQUIC_PATH_T__MAX_SPURIOUS_RTT) || (param1->max_spurious_rtt == param2->max_spurious_rtt);
  cond &= (flags & ASSERT_PICOQUIC_PATH_T__MAX_REORDER_DELAY) || (param1->max_reorder_delay == param2->max_reorder_delay);
  cond &= (flags & ASSERT_PICOQUIC_PATH_T__MAX_REORDER_GAP) || (param1->max_reorder_gap == param2->max_reorder_gap);
  cond &= (flags & ASSERT_PICOQUIC_PATH_T__SEND_MTU) || (param1->send_mtu == param2->send_mtu);
  cond &= (flags & ASSERT_PICOQUIC_PATH_T__SEND_MTU_MAX_TRIED) || (param1->send_mtu_max_tried == param2->send_mtu_max_tried);
  cond &= (flags & ASSERT_PICOQUIC_PATH_T__CWIN) || (param1->cwin == param2->cwin);
  cond &= (flags & ASSERT_PICOQUIC_PATH_T__BYTES_IN_TRANSIT) || (param1->bytes_in_transit == param2->bytes_in_transit);
  cond &= (flags & ASSERT_PICOQUIC_PATH_T__PACING_EVALUATION_TIME) || (param1->pacing_evaluation_time == param2->pacing_evaluation_time);
  cond &= (flags & ASSERT_PICOQUIC_PATH_T__PACING_BUCKET_NANOSEC) || (param1->pacing_bucket_nanosec == param2->pacing_bucket_nanosec);
  cond &= (flags & ASSERT_PICOQUIC_PATH_T__PACING_BUCKET_MAX) || (param1->pacing_bucket_max == param2->pacing_bucket_max);
  cond &= (flags & ASSERT_PICOQUIC_PATH_T__PACING_PACKET_TIME_NANOSEC) || (param1->pacing_packet_time_nanosec == param2->pacing_packet_time_nanosec);
  cond &= (flags & ASSERT_PICOQUIC_PATH_T__PACING_PACKET_TIME_MICROSEC) || (param1->pacing_packet_time_microsec == param2->pacing_packet_time_microsec);
  cond &= (flags & ASSERT_PICOQUIC_PATH_T__NB_PKT_SENT) || (param1->nb_pkt_sent == param2->nb_pkt_sent);
  cond &= (flags & ASSERT_PICOQUIC_PATH_T__DELIVERED) || (param1->delivered == param2->delivered);
  cond &= (flags & ASSERT_PICOQUIC_PATH_T__DELIVERED_LAST) || (param1->delivered_last == param2->delivered_last);
  cond &= (flags & ASSERT_PICOQUIC_PATH_T__DELIVERED_TIME_LAST) || (param1->delivered_time_last == param2->delivered_time_last);
  cond &= (flags & ASSERT_PICOQUIC_PATH_T__DELIVERED_SENT_LAST) || (param1->delivered_sent_last == param2->delivered_sent_last);
  cond &= (flags & ASSERT_PICOQUIC_PATH_T__DELIVERED_LIMITED_INDEX) || (param1->delivered_limited_index == param2->delivered_limited_index);
  cond &= (flags & ASSERT_PICOQUIC_PATH_T__DELIVERED_LAST_PACKET) || (param1->delivered_last_packet == param2->delivered_last_packet);
  cond &= (flags & ASSERT_PICOQUIC_PATH_T__BANDWIDTH_ESTIMATE) || (param1->bandwidth_estimate == param2->bandwidth_estimate);
  cond &= (flags & ASSERT_PICOQUIC_PATH_T__RECEIVED) || (param1->received == param2->received);
  cond &= (flags & ASSERT_PICOQUIC_PATH_T__RECEIVE_RATE_EPOCH) || (param1->receive_rate_epoch == param2->receive_rate_epoch);
  cond &= (flags & ASSERT_PICOQUIC_PATH_T__RECEIVED_PRIOR) || (param1->received_prior == param2->received_prior);
  cond &= (flags & ASSERT_PICOQUIC_PATH_T__RECEIVE_RATE_ESTIMATE) || (param1->receive_rate_estimate == param2->receive_rate_estimate);
  cond &= (flags & ASSERT_PICOQUIC_PATH_T__RECEIVE_RATE_MAX) || (param1->receive_rate_max == param2->receive_rate_max);
  assert_cp__picoquic_connection_id_t(&param1->local_cnxid, &param2->local_cnxid, 0);
  assert_cp__picoquic_connection_id_t(&param1->remote_cnxid, &param2->remote_cnxid, 0);
  cond &= param1->reset_secret[0] == param2->reset_secret[0];
  cond &= param1->reset_secret[1] == param2->reset_secret[1];
  cond &= param1->reset_secret[2] == param2->reset_secret[2];
  cond &= param1->reset_secret[3] == param2->reset_secret[3];
  cond &= param1->reset_secret[4] == param2->reset_secret[4];
  cond &= param1->reset_secret[5] == param2->reset_secret[5];
  cond &= param1->reset_secret[6] == param2->reset_secret[6];
  cond &= param1->reset_secret[7] == param2->reset_secret[7];
  cond &= param1->reset_secret[8] == param2->reset_secret[8];
  cond &= param1->reset_secret[9] == param2->reset_secret[9];
  cond &= param1->reset_secret[10] == param2->reset_secret[10];
  cond &= param1->reset_secret[11] == param2->reset_secret[11];
  cond &= param1->reset_secret[12] == param2->reset_secret[12];
  cond &= param1->reset_secret[13] == param2->reset_secret[13];
  cond &= param1->reset_secret[14] == param2->reset_secret[14];
  cond &= param1->reset_secret[15] == param2->reset_secret[15];
  sassert(cond);
}

inline void assert_cp__picoquic_packet_t(picoquic_packet_t *param1, picoquic_packet_t *param2, uint64_t flags)
{
  sassert(param1 != param2);
  unsigned int cond = 1;
  cond &= (flags & ASSERT_PICOQUIC_PACKET_T__SEQUENCE_NUMBER) || (param1->sequence_number == param2->sequence_number);
  cond &= (flags & ASSERT_PICOQUIC_PACKET_T__SEND_TIME) || (param1->send_time == param2->send_time);
  cond &= (flags & ASSERT_PICOQUIC_PACKET_T__DELIVERED_PRIOR) || (param1->delivered_prior == param2->delivered_prior);
  cond &= (flags & ASSERT_PICOQUIC_PACKET_T__DELIVERED_TIME_PRIOR) || (param1->delivered_time_prior == param2->delivered_time_prior);
  cond &= (flags & ASSERT_PICOQUIC_PACKET_T__DELIVERED_SENT_PRIOR) || (param1->delivered_sent_prior == param2->delivered_sent_prior);
  cond &= (flags & ASSERT_PICOQUIC_PACKET_T__LENGTH) || (param1->length == param2->length);
  cond &= (flags & ASSERT_PICOQUIC_PACKET_T__SEND_LENGTH) || (param1->send_length == param2->send_length);
  cond &= (flags & ASSERT_PICOQUIC_PACKET_T__CHECKSUM_OVERHEAD) || (param1->checksum_overhead == param2->checksum_overhead);
  cond &= (flags & ASSERT_PICOQUIC_PACKET_T__OFFSET) || (param1->offset == param2->offset);
  cond &= (flags & ASSERT_PICOQUIC_PACKET_T__IS_PURE_ACK) || (param1->is_pure_ack == param2->is_pure_ack);
  cond &= (flags & ASSERT_PICOQUIC_PACKET_T__CONTAINS_CRYPTO) || (param1->contains_crypto == param2->contains_crypto);
  cond &= (flags & ASSERT_PICOQUIC_PACKET_T__IS_CONGESTION_CONTROLLED) || (param1->is_congestion_controlled == param2->is_congestion_controlled);
  cond &= (flags & ASSERT_PICOQUIC_PACKET_T__HAS_PLUGIN_FRAMES) || (param1->has_plugin_frames == param2->has_plugin_frames);
  cond &= (flags & ASSERT_PICOQUIC_PACKET_T__IS_MTU_PROBE) || (param1->is_mtu_probe == param2->is_mtu_probe);
  cond &= (flags & ASSERT_PICOQUIC_PACKET_T__DELIVERED_APP_LIMITED) || (param1->delivered_app_limited == param2->delivered_app_limited);
  cond &= (flags & ASSERT_PICOQUIC_PACKET_T__HAS_HANDSHAKE_DONE) || (param1->has_handshake_done == param2->has_handshake_done);
  sassert(cond);
}

inline void assert_cp__picoquic_packet_header(picoquic_packet_header *param1, picoquic_packet_header *param2, uint64_t flags)
{
  sassert(param1 != param2);
  unsigned int cond = 1;
  assert_cp__picoquic_connection_id_t(&param1->dest_cnx_id, &param2->dest_cnx_id, 0);
  assert_cp__picoquic_connection_id_t(&param1->srce_cnx_id, &param2->srce_cnx_id, 0);
  cond &= (flags & ASSERT_PICOQUIC_PACKET_HEADER__PN) || (param1->pn == param2->pn);
  cond &= (flags & ASSERT_PICOQUIC_PACKET_HEADER__VN) || (param1->vn == param2->vn);
  cond &= (flags & ASSERT_PICOQUIC_PACKET_HEADER__OFFSET) || (param1->offset == param2->offset);
  cond &= (flags & ASSERT_PICOQUIC_PACKET_HEADER__PN_OFFSET) || (param1->pn_offset == param2->pn_offset);
  cond &= (flags & ASSERT_PICOQUIC_PACKET_HEADER__PNMASK) || (param1->pnmask == param2->pnmask);
  cond &= (flags & ASSERT_PICOQUIC_PACKET_HEADER__PN64) || (param1->pn64 == param2->pn64);
  cond &= (flags & ASSERT_PICOQUIC_PACKET_HEADER__PAYLOAD_LENGTH) || (param1->payload_length == param2->payload_length);
  cond &= (flags & ASSERT_PICOQUIC_PACKET_HEADER__VERSION_INDEX) || (param1->version_index == param2->version_index);
  cond &= (flags & ASSERT_PICOQUIC_PACKET_HEADER__EPOCH) || (param1->epoch == param2->epoch);
  cond &= (flags & ASSERT_PICOQUIC_PACKET_HEADER__SPIN) || (param1->spin == param2->spin);
  cond &= (flags & ASSERT_PICOQUIC_PACKET_HEADER__SPIN_VEC) || (param1->spin_vec == param2->spin_vec);
  cond &= (flags & ASSERT_PICOQUIC_PACKET_HEADER__HAS_SPIN_BIT) || (param1->has_spin_bit == param2->has_spin_bit);
  cond &= (flags & ASSERT_PICOQUIC_PACKET_HEADER__TOKEN_LENGTH) || (param1->token_length == param2->token_length);
  cond &= (flags & ASSERT_PICOQUIC_PACKET_HEADER__TOKEN_OFFSET) || (param1->token_offset == param2->token_offset);
  sassert(cond);
}

