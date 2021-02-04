#include "verifier.h"

/* Dummy signatures for seahorn
 *
 * Seahorn 
 */


/* 
 * @pre cnx1 != NULL && cnx2 != NULL
 * @post cnx2 is an exact copy of cnx1 
 */ 

#ifdef VERIFIER_CEX
void cp_cnx(picoquic_cnx_t* src, picoquic_cnx_t* dst) {
    // versions negotiation
	dst->proposed_version = src->proposed_version;
	dst->version_index = src->version_index;

	// flags
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

    //assume_cp_tp(&cnx1->local_parameters, &cnx2->local_parameters);
	//assume_cp_tp(&cnx1->remote_parameters, &cnx2->remote_parameters);

	dst->protoop_inputc = src->protoop_inputc;

}
#endif

inline void assume_cp_tp(picoquic_tp_t* tp1, picoquic_tp_t* tp2) {
	cp_tp(tp1, tp2);
	//picoquic_connection_id_t original_destination_connection_id;
    assume(tp1->max_idle_timeout == tp2->max_idle_timeout);
    assume(tp1->max_packet_size == tp2->max_packet_size);
    assume(tp1->initial_max_data == tp2->initial_max_data);
    /*uint64_t initial_max_stream_data_bidi_local;
    uint64_t initial_max_stream_data_bidi_remote;
    uint64_t initial_max_stream_data_uni;
    uint64_t initial_max_streams_bidi;
    uint64_t initial_max_streams_uni;
    uint64_t ack_delay_exponent;
    uint64_t max_ack_delay;  // TODO use TP
    unsigned int disable_active_migration;
    picoquic_tp_preferred_address_t preferred_address;  // TODO use TP
    uint64_t active_connection_id_limit;
    picoquic_connection_id_t initial_source_connection_id;
    picoquic_connection_id_t retry_source_connection_id; // TODO use this TP
    char* supported_plugins;
    char* plugins_to_inject;*/
}

inline void assume_cnx_cp(picoquic_cnx_t* cnx1, picoquic_cnx_t* cnx2) {
	sassert(cnx1 != NULL && cnx2 != NULL); /* assert cp_cnx @pre */

    cp_cnx(cnx2, cnx1); /* dummy cp_cnx call for seahorn */

	/* assuming @post of cp_cnx */
	
	// ..

	// versions negotiation
	assume(cnx1->proposed_version == cnx2->proposed_version);
	assume(cnx1->version_index == cnx2->version_index);

	// flags
	assume(cnx1->is_0RTT_accepted == cnx2->is_0RTT_accepted);
	assume(cnx1->remote_parameters_received == cnx2->remote_parameters_received);
	assume(cnx1->current_spin == cnx2->current_spin);
	assume(cnx1->client_mode == cnx2->client_mode);
	assume(cnx1->prev_spin == cnx2->prev_spin);
	assume(cnx1->spin_vec == cnx2->spin_vec);
	assume(cnx1->spin_edge == cnx2->spin_edge);
	assume(cnx1->spin_last_trigger == cnx2->spin_last_trigger);
	assume(cnx1->key_phase_enc == cnx2->key_phase_enc);
	assume(cnx1->key_phase_dec == cnx2->key_phase_dec);
	assume(cnx1->zero_rtt_data_accepted == cnx2->zero_rtt_data_accepted);
	assume(cnx1->one_rtt_data_acknowledged == cnx2->one_rtt_data_acknowledged);
	assume(cnx1->processed_transport_parameter == cnx2->processed_transport_parameter);

	assume_cp_tp(&cnx1->local_parameters, &cnx2->local_parameters);
	assume_cp_tp(&cnx1->remote_parameters, &cnx2->remote_parameters);

	assume(cnx1->protoop_inputc == cnx2->protoop_inputc);
}

inline void assume_pkt_ctx_cp(picoquic_packet_context_t* pc1, picoquic_packet_context_t* pc2)
{
	cp_pkt_ctx(pc1, pc2);
	assume(pc1->send_sequence == pc2->send_sequence);

    //picoquic_sack_item_t first_sack_item;
    assume(pc1->time_stamp_largest_received == pc2->time_stamp_largest_received);
    assume(pc1->highest_ack_sent == pc2->highest_ack_sent);
    assume(pc1->highest_ack_time == pc2->highest_ack_time);
    assume(pc1->ack_delay_local == pc2->ack_delay_local);
    assume(pc1->latest_progress_time == pc2->latest_progress_time);

    assume(pc1->nb_retransmit == pc2->nb_retransmit);
    assume(pc1->latest_retransmit_time == pc2->latest_retransmit_time);
    assume(pc1->latest_retransmit_cc_notification_time == pc2->latest_retransmit_cc_notification_time);
    assume(pc1->highest_acknowledged == pc2->highest_acknowledged);
    assume(pc1->latest_time_acknowledged == pc2->latest_time_acknowledged);
    //picoquic_packet_t* retransmit_newest;
    //picoquic_packet_t* retransmit_oldest;
    //picoquic_packet_t* retransmitted_newest;
    //picoquic_packet_t* retransmitted_oldest;

    assume(pc1->ack_needed == pc2->ack_needed);

    //plugin_struct_metadata_t *metadata;
}

inline void assume_path_cp(picoquic_path_t* p1, picoquic_path_t* p2) {
	cp_path(p1, p2);

    //struct sockaddr_storage peer_addr;
    assume(p1->peer_addr_len == p2->peer_addr_len);
    //struct sockaddr_storage local_addr;
    assume(p1->local_addr_len == p2->local_addr_len);
    assume(p1->if_index_local == p2->if_index_local);

    assume(p1->challenge == p2->challenge);
    assume(p1->challenge_time == p2->challenge_time);
    //assume(p1->challenge_response[PICOQUIC_CHALLENGE_LENGTH] == p2->challenge_response[PICOQUIC_CHALLENGE_LENGTH]);
    assume(p1->challenge_repeat_count == p2->challenge_repeat_count);

    assume(p1->mtu_probe_sent == p2->mtu_probe_sent);
	assume(p1->challenge_verified == p2->challenge_verified);
    assume(p1->challenge_response_to_send == p2->challenge_response_to_send);
    assume(p1->ping_received == p2->ping_received);
    assume(p1->last_bw_estimate_path_limited == p2->last_bw_estimate_path_limited);

	// ..
}

inline void assert_tp_cmp(picoquic_tp_t* tp1, picoquic_tp_t* tp2) {
	unsigned int cond = 1;

	// ...

	cond &= (tp1->max_idle_timeout == tp2->max_idle_timeout);
    cond &= (tp1->max_packet_size == tp2->max_packet_size);
    cond &= (tp1->initial_max_data == tp2->initial_max_data);

	// ..

	sassert(cond);
}

inline void assert_cnx_cmp(picoquic_cnx_t* cnx0, picoquic_cnx_t* cnx) {
	unsigned int cond = 1;
	cond &= (cnx0->proposed_version == cnx->proposed_version);
	cond &= (cnx0->version_index == cnx->version_index);

	// flags check
	cond &= (cnx0->is_0RTT_accepted == cnx->is_0RTT_accepted);
	cond &= (cnx0->remote_parameters_received == cnx->remote_parameters_received);
	cond &= (cnx0->current_spin == cnx->current_spin);
	cond &= (cnx0->client_mode == cnx->client_mode);
	cond &= (cnx0->prev_spin == cnx->prev_spin);
	cond &= (cnx0->spin_vec == cnx->spin_vec);
	cond &= (cnx0->spin_edge == cnx->spin_edge);
	cond &= (cnx0->spin_last_trigger == cnx->spin_last_trigger);
	cond &= (cnx0->key_phase_enc == cnx->key_phase_enc);
	cond &= (cnx0->key_phase_dec == cnx->key_phase_dec);
	cond &= (cnx0->zero_rtt_data_accepted == cnx->zero_rtt_data_accepted);
	cond &= (cnx0->one_rtt_data_acknowledged == cnx->one_rtt_data_acknowledged);
	cond &= (cnx0->processed_transport_parameter == cnx->processed_transport_parameter);
	cond &= (cnx0->protoop_inputc == cnx->protoop_inputc);

	assert_tp_cmp(&cnx0->local_parameters, &cnx->local_parameters);
	assert_tp_cmp(&cnx0->remote_parameters, &cnx->remote_parameters);

    sassert(cond);
}


inline void assert_pkt_ctx_cmp(picoquic_packet_context_t* pc1, picoquic_packet_context_t* pc2, uint64_t flags)
{
	unsigned int cond = 1;

	cond &= (pc1->send_sequence == pc2->send_sequence);

    //picoquic_sack_item_t first_sack_item;
    cond &= (pc1->time_stamp_largest_received == pc2->time_stamp_largest_received);
    cond &= (pc1->highest_ack_sent == pc2->highest_ack_sent);
    cond &= (pc1->highest_ack_time == pc2->highest_ack_time);
    cond &= (flags & ASSERT__PKTCTX__ACK_DELAY_LOCAL) ? 1 : (pc1->ack_delay_local == pc2->ack_delay_local);
    cond &= (pc1->latest_progress_time == pc2->latest_progress_time);

    cond &= (pc1->nb_retransmit == pc2->nb_retransmit);
    cond &= (pc1->latest_retransmit_time == pc2->latest_retransmit_time);
    cond &= (pc1->latest_retransmit_cc_notification_time == pc2->latest_retransmit_cc_notification_time);
    cond &= (pc1->highest_acknowledged == pc2->highest_acknowledged);
    cond &= (pc1->latest_time_acknowledged == pc2->latest_time_acknowledged);
    //picoquic_packet_t* retransmit_newest;
    //picoquic_packet_t* retransmit_oldest;
    //picoquic_packet_t* retransmitted_newest;
    //picoquic_packet_t* retransmitted_oldest;

	cond &= (pc1->ack_needed == pc2->ack_needed);

    //plugin_struct_metadata_t *metadata;
	
	sassert(cond);
}

inline void assert_path_cmp(picoquic_path_t* p1, picoquic_path_t* p2) {
	unsigned int cond = 1;

    //struct sockaddr_storage peer_addr;
    cond &= (p1->peer_addr_len == p2->peer_addr_len);
    //struct sockaddr_storage local_addr;
    cond &= (p1->local_addr_len == p2->local_addr_len);
    cond &= (p1->if_index_local == p2->if_index_local);

    cond &= (p1->challenge == p2->challenge);
    cond &= (p1->challenge_time == p2->challenge_time);
    //cond &= (p1->challenge_response[PICOQUIC_CHALLENGE_LENGTH] == p2->challenge_response[PICOQUIC_CHALLENGE_LENGTH]);
    cond &= (p1->challenge_repeat_count == p2->challenge_repeat_count);

    cond &= (p1->mtu_probe_sent == p2->mtu_probe_sent);
	cond &= (p1->challenge_verified == p2->challenge_verified);
    cond &= (p1->challenge_response_to_send == p2->challenge_response_to_send);
    cond &= (p1->ping_received == p2->ping_received);
    cond &= (p1->last_bw_estimate_path_limited == p2->last_bw_estimate_path_limited);

	sassert(cond);

	// ..
}
