#include "tcp_sender.hh"
#include "tcp_config.hh"
#include <random>
#include <algorithm>
    // Dummy implementation of a TCP sender

    // For Lab 3, please replace with a real implementation that passes the
    // automated checks run by `make check_lab3`.

    template <typename... Targs>
    void DUMMY_CODE(Targs &&.../* unused */) {}

    using namespace std;

    //! \param[in] capacity the capacity of the outgoing byte stream
    //! \param[in] retx_timeout the initial amount of time to wait before retransmitting the oldest outstanding segment
    //! \param[in] fixed_isn the Initial Sequence Number to use, if set (otherwise uses a random ISN)
    TCPSender::TCPSender(const size_t capacity, const uint16_t retx_timeout, const std::optional<WrappingInt32> fixed_isn)
    : _isn(fixed_isn.value_or(WrappingInt32{random_device()()}))
    , _initial_retransmission_timeout{retx_timeout}
    , _stream(capacity)
    , _rto{retx_timeout} {}
uint64_t TCPSender::bytes_in_flight() const { return _bytes_in_flight; }

void TCPSender::fill_window() {
    if (!_syn_sent) {
        _syn_sent = true;
        TCPSegment seg;
        seg.header().syn = true;
        send_segment(seg);
        return;
    }
    if (!_segments_outstanding.empty() && _segments_outstanding.front().header().syn)
        return;
    if (!_stream.buffer_size() && !_stream.eof())
        return;
    if (_fin_sent){
        return;
    }



    if (_receiver_window_size) {
        while (_receiver_free_space) {
            TCPSegment seg;
            size_t payload_size = min({_stream.buffer_size(),
                                       static_cast<size_t>(_receiver_free_space),
                                       static_cast<size_t>(TCPConfig::MAX_PAYLOAD_SIZE)});
            seg.payload() = _stream.read(payload_size);
            if (_stream.eof() && static_cast<size_t>(_receiver_free_space) > payload_size) {
                seg.header().fin = true;
                _fin_sent = true;
            }
            send_segment(seg);
            if (_stream.buffer_empty())
                break;
        }
    } else if (_receiver_free_space == 0) {
        // The zero-window-detect-segment should only be sent once (retransmition excute by tick function).
        // Before it is sent, _receiver_free_space is zero. Then it will be -1.
        TCPSegment seg;
        if (_stream.eof()) {
            seg.header().fin = true;
            _fin_sent = true;
            send_segment(seg);
        } else if (!_stream.buffer_empty()) {
            seg.payload() = _stream.read(1);
            send_segment(seg);
        }
    }
}

void TCPSender::send_segment(TCPSegment &seg) {
    seg.header().seqno = wrap(_next_seqno, _isn);
    _next_seqno += seg.length_in_sequence_space();
    _bytes_in_flight += seg.length_in_sequence_space();
    if (_syn_sent)
        _receiver_free_space -= seg.length_in_sequence_space();
    _segments_out.push(seg);
    _segments_outstanding.push(seg);
    if (!_timer_running) {
        _timer_running = true;
        _time_elapsed = 0;
    }
}
// See test code send_window.cc line 113 why the commented code is wrong.
//! \param ackno The remote receiver's ackno (acknowledgment number)
//! \param window_size The remote receiver's advertised window size
void TCPSender::ack_received(const WrappingInt32 ackno, const uint16_t window_size) {
    uint64_t ackno_now = unwrap(ackno, _isn, _next_seqno);

        bool  vaild_ack;
        if(_segments_outstanding.empty()){
            vaild_ack = (ackno_now <= _next_seqno) && (ackno_now >= unwrap(ackno, _isn, _next_seqno));
        }
        else{
            vaild_ack = (ackno_now <= _next_seqno) && (ackno_now >= unwrap(_segments_outstanding.front().header().seqno, _isn, _next_seqno));
        }
        if(!vaild_ack){
            return ;
        }
    _receiver_window_size = window_size;
    _receiver_free_space = window_size;

    while (!_segments_outstanding.empty()) {
        TCPSegment seg = _segments_outstanding.front();

        if (unwrap(seg.header().seqno, _isn, _next_seqno) + seg.length_in_sequence_space() <= ackno_now){
            _bytes_in_flight -= seg.length_in_sequence_space();
            _segments_outstanding.pop();
            // Do not do the following operations outside while loop.
            // Because if the ack is not corresponding to any segment in the segment_outstanding,
            // we should not restart the timer.
            _time_elapsed = 0;
            _rto = _initial_retransmission_timeout;
            _consecutive_retransmissions = 0;
        } else {
            break;
        }
    }
    if (!_segments_outstanding.empty()) {
        _receiver_free_space = static_cast<uint16_t>(
            ackno_now + static_cast<uint64_t>(window_size) -
            unwrap(_segments_outstanding.front().header().seqno, _isn, _next_seqno) - _bytes_in_flight);
    }

        if (!_bytes_in_flight)
            _timer_running = false;
    // Note that test code will call it again.
    fill_window();
}

    // See test code send_window.cc line 113 why the commented code is wrong.
    bool TCPSender::_ack_valid(uint64_t abs_ackno) {
    return abs_ackno <= _next_seqno &&
           //  abs_ackno >= unwrap(_segments_outstanding.front().header().seqno, _isn, _next_seqno) +
           //          _segments_outstanding.front().length_in_sequence_space();
           abs_ackno >= unwrap(_segments_outstanding.front().header().seqno, _isn, _next_seqno);
}
//! \param[in] ms_since_last_tick the number of milliseconds since the last call to this method
void TCPSender::tick(const size_t ms_since_last_tick) {
    if (!_timer_running)
        return;
    _time_elapsed += ms_since_last_tick;
    if (_time_elapsed >= _rto) {
        _segments_out.push(_segments_outstanding.front());
        if (_receiver_window_size || _segments_outstanding.front().header().syn) {
            ++_consecutive_retransmissions;
            _rto <<= 1;
        }
        _time_elapsed = 0;
    }
}

    unsigned int TCPSender::consecutive_retransmissions() const { return _consecutive_retransmissions; }

    void TCPSender::send_empty_segment() {
    TCPSegment seg;
    seg.header().seqno = wrap(_next_seqno, _isn);
    _segments_out.push(seg);
}
