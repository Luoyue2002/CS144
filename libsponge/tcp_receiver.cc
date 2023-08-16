#include "tcp_receiver.hh"

// Dummy implementation of a TCP receiver

// For Lab 2, please replace with a real implementation that passes the
// automated checks run by `make check_lab2`.

template <typename... Targs>
void DUMMY_CODE(Targs &&... /* unused */) {}

using namespace std;

void TCPReceiver::segment_received(const TCPSegment &seg) {
//    DUMMY_CODE(seg);
    auto tcp_header = seg.header();
    if(!_syn_recv && !tcp_header.syn){
        return ;
    }
    if(_syn_recv && tcp_header.syn){
        return ;
    }
//    if(_fin_recv){
//        return ;
//    }
    if(!_syn_recv && tcp_header.syn){
        _syn_recv = true;
        _isn =tcp_header.seqno;
    }
//    if(_syn_recv && tcp_header.fin){
//        _fin_recv = true;
//    }
    size_t checkpoint = _reassembler.stream_out().bytes_written() + 1;

    uint64_t seq_no = unwrap(tcp_header.seqno, _isn, checkpoint);

    uint64_t push_index = seq_no-1+ static_cast<size_t>(tcp_header.syn);

    _reassembler.push_substring(seg.payload().copy(), push_index , tcp_header.fin);

}

optional<WrappingInt32> TCPReceiver::ackno() const {
//    auto tcp_header = seg.header();
    if (!_syn_recv)
        return nullopt;
    size_t ack_no = _reassembler.stream_out().bytes_written() + 1;
    if (_reassembler.stream_out().input_ended()){
        // in fin
        ack_no = ack_no + static_cast<size_t>(true);
    }
    return wrap(ack_no,_isn) ;
}

size_t TCPReceiver::window_size() const {
    return stream_out().remaining_capacity();
}
