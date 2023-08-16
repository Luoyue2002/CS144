#include "byte_stream.hh"

// Dummy implementation of a flow-controlled in-memory byte stream.

// For Lab 0, please replace with a real implementation that passes the
// automated checks run by `make check_lab0`.

// You will need to add private members to the class declaration in `byte_stream.hh`

template <typename... Targs>
void DUMMY_CODE(Targs &&... /* unused */) {}

using namespace std;

//: _byte_stream(),_capacity_size(capacity),_size_can_write(capacity),_size_can_read(0),_total_write_in(0),_total_read_out(0),is_empty(true),is_eof(false) {
    //    DUMMY_CODE(capacity);
//        _capacity_size = capacity;
//        _byte_stream = {};
//        _size_can_write =capacity ;
//        _size_can_read = 0 ;
//        is_empty = true;
//        is_eof = false;
//        _total_read_out =0;
//        _total_write_in =0;
//}
ByteStream::ByteStream(const size_t capacity):_capacity_size(capacity),_size_can_write(capacity){

}


size_t ByteStream::write(const string &data) {
//    DUMMY_CODE(data);
    _size_can_write = _capacity_size - _byte_stream.size();
    _size_can_read  = _byte_stream.size();
    size_t write_in_size;
    if(is_eof){
        return 0;
    }
    if( _size_can_write < data.size() ){
        write_in_size = _size_can_write;
    }
    else{
        write_in_size = data.size();
    }

    _size_can_write = _size_can_write - write_in_size;
    _size_can_read  = _size_can_read  + write_in_size;

    //write in
    for(size_t i=0; i < write_in_size ;i++){
        _byte_stream.push_back(data[i]);
    }
    _total_write_in = _total_write_in + write_in_size;
    return write_in_size;

}

//! \param[in] len bytes will be copied from the output side of the buffer
string ByteStream::peek_output(const size_t len) const {
//    DUMMY_CODE(len);
    size_t copy_size;
    if (len < _size_can_read){
        copy_size = len;
    }
    else{
        copy_size = _size_can_read;
    }

    string peek_string ;
    size_t count = 1;

    for(auto dq_it = _byte_stream.begin();count <= copy_size ;dq_it++ , count++ ){
        auto  _char = (*dq_it);
        peek_string = peek_string.append(1,_char);
    }

    return peek_string;
}

//! \param[in] len bytes will be removed from the output side of the buffer
void ByteStream::pop_output(const size_t len) {
//    DUMMY_CODE(len);
    _size_can_write = _capacity_size - _byte_stream.size();
    _size_can_read  = _byte_stream.size();
    size_t pop_size;
    if (len < _size_can_read){
        pop_size = len;
    }
    else{
        pop_size = _size_can_read;
    }
    for(size_t i=0; i < pop_size ;i++){
        _byte_stream.pop_front();
    }
    _total_read_out = _total_read_out + pop_size;

}

//! Read (i.e., copy and then pop) the next "len" bytes of the stream
//! \param[in] len bytes will be popped and returned
//! \returns a string
std::string ByteStream::read(const size_t len) {
//    DUMMY_CODE(len);
    _size_can_write = _capacity_size - _byte_stream.size();
    _size_can_read  = _byte_stream.size();
    size_t read_out_size;
    if (len < _size_can_read){
        read_out_size = len;
    }
    else{
        read_out_size = _size_can_read;
    }
    string read_out_string = this->peek_output(read_out_size);
    this->pop_output(read_out_size);
    _size_can_read  = _size_can_read  - read_out_size;
    _size_can_write = _size_can_write + read_out_size;
    _total_read_out = _total_read_out + read_out_size;
    return read_out_string;
}

void ByteStream::end_input() {
    is_eof = true;
}

bool ByteStream::input_ended() const {
    return is_eof;
}

size_t ByteStream::buffer_size() const {
    return _byte_stream.size();
}

bool ByteStream::buffer_empty() const {
//    is_empty = _byte_stream.empty();
    return _byte_stream.empty();
}


bool ByteStream::eof() const {

    return input_ended()&&buffer_empty();
}

size_t ByteStream::bytes_written() const {
    return _total_write_in;
}

size_t ByteStream::bytes_read() const {
    return _total_read_out;
}

size_t ByteStream::remaining_capacity() const {
    return _capacity_size - _byte_stream.size();
}
