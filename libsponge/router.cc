#include "router.hh"

#include <iostream>

using namespace std;

// Dummy implementation of an IP router

// Given an incoming Internet datagram, the router decides
// (1) which interface to send it out on, and
// (2) what next hop address to send it to.

// For Lab 6, please replace with a real implementation that passes the
// automated checks run by `make check_lab6`.

// You will need to add private members to the class declaration in `router.hh`

template <typename... Targs>
void DUMMY_CODE(Targs &&... /* unused */) {}

//! \param[in] route_prefix The "up-to-32-bit" IPv4 address prefix to match the datagram's destination address against
//! \param[in] prefix_length For this route to be applicable, how many high-order (most-significant) bits of the route_prefix will need to match the corresponding bits of the datagram's destination address?
//! \param[in] next_hop The IP address of the next hop. Will be empty if the network is directly attached to the router (in which case, the next hop address should be the datagram's final destination).
//! \param[in] interface_num The index of the interface to send the datagram out on.
void Router::add_route(const uint32_t route_prefix,
                       const uint8_t prefix_length,
                       const optional<Address> next_hop,
                       const size_t interface_num) {
    cerr << "DEBUG: adding route " << Address::from_ipv4_numeric(route_prefix).ip() << "/" << int(prefix_length)
         << " => " << (next_hop.has_value() ? next_hop->ip() : "(direct)") << " on interface " << interface_num << "\n";

//    DUMMY_CODE(route_prefix, prefix_length, next_hop, interface_num);

    // Your code here.
    router_struct new_record;
    new_record.route_prefix = route_prefix;
    new_record.prefix_length = prefix_length;
    new_record.next_hop = next_hop;
    new_record.interface_num = interface_num;

    _router_table.emplace_back(new_record);

}

//! \param[in] dgram The datagram to be routed
void Router::route_one_datagram(InternetDatagram &dgram) {
//    DUMMY_CODE(dgram);
    // Your code here.
    auto dgram_target = dgram.header().dst;
    // match


    router_struct * match_record = nullptr ;
    uint32_t longest_match = 0;
    for( auto it = _router_table.begin(); it!= _router_table.end(); it++){
        auto record = *it;
        uint32_t  mask = 0;
        if (record.prefix_length > 0) {
            mask = ~((1 << (32 - record.prefix_length)) - 1);
        }
        if( (record.prefix_length==0) || ((mask & dgram.header().dst) == record.route_prefix) ){
            if (record.prefix_length >= longest_match) {
                longest_match = record.prefix_length;
                match_record = &(*it);
            }
        }

    }

    if (dgram.header().ttl > 0) {
        dgram.header().ttl =dgram.header().ttl - 1;
    }
    if (dgram.header().ttl <= 0) {
        return;
    }

    if(match_record != nullptr && dgram.header().ttl > 0){
        auto next_hop = match_record->next_hop;
        if(next_hop.has_value()){
            interface( match_record->interface_num).send_datagram(dgram, next_hop.value());
        }
        else{
            interface( match_record->interface_num).send_datagram(dgram, Address::from_ipv4_numeric(dgram_target));
        }
    }



}

void Router::route() {
    // Go through all the interfaces, and route every incoming datagram to its proper outgoing interface.
    for (auto &interface : _interfaces) {
        auto &queue = interface.datagrams_out();
        while (not queue.empty()) {
            route_one_datagram(queue.front());
            queue.pop();
        }
    }
}
