#include "network_interface.hh"

#include "arp_message.hh"
#include "ethernet_frame.hh"

#include <iostream>

// Dummy implementation of a network interface
// Translates from {IP datagram, next hop address} to link-layer frame, and from link-layer frame to IP datagram

// For Lab 5, please replace with a real implementation that passes the
// automated checks run by `make check_lab5`.

// You will need to add private members to the class declaration in `network_interface.hh`

template <typename... Targs>
void DUMMY_CODE(Targs &&... /* unused */) {}

using namespace std;

//! \param[in] ethernet_address Ethernet (what ARP calls "hardware") address of the interface
//! \param[in] ip_address IP (what ARP calls "protocol") address of the interface
NetworkInterface::NetworkInterface(const EthernetAddress &ethernet_address, const Address &ip_address)
    : _ethernet_address(ethernet_address), _ip_address(ip_address) {
    cerr << "DEBUG: Network interface has Ethernet address " << to_string(_ethernet_address) << " and IP address "
         << ip_address.ip() << "\n";


}

//! \param[in] dgram the IPv4 datagram to be sent
//! \param[in] next_hop the IP address of the interface to send it to (typically a router or default gateway, but may also be another host if directly connected to the same network as the destination)
//! (Note: the Address type can be converted to a uint32_t (raw 32-bit IP address) with the Address::ipv4_numeric() method.)
void NetworkInterface::send_datagram(const InternetDatagram &dgram, const Address &next_hop) {
    // convert IP address of next hop to raw 32-bit representation (used in ARP header)
    const uint32_t next_hop_ip = next_hop.ipv4_numeric();

//    DUMMY_CODE(dgram, next_hop, next_hop_ip);
    if (_arp_table.find(next_hop_ip)!=_arp_table.end()){
        auto it = _arp_table.find(next_hop_ip);
        EthernetFrame ethernet_frame;
        ethernet_frame.header() = { it->second.first,_ethernet_address,EthernetHeader::TYPE_IPv4};
        ethernet_frame.payload() = dgram.serialize();
        _frames_out.push(ethernet_frame);
    }
    else{
        // send arp  save diagram
        // is in ip waiting map?
        if (_ip_waiting_arp.find(next_hop_ip) == _ip_waiting_arp.end()){
            // not in ,
            // arp 包
            ARPMessage arp_;
            arp_.opcode = ARPMessage::OPCODE_REQUEST;
            arp_.sender_ethernet_address = _ethernet_address;
            arp_.sender_ip_address = _ip_address.ipv4_numeric();
            arp_.target_ethernet_address = {  };
            arp_.target_ip_address = next_hop_ip;

            //
            EthernetFrame ethernet_frame;
            ethernet_frame.header() = {ETHERNET_BROADCAST,_ethernet_address,EthernetHeader::TYPE_ARP};
            ethernet_frame.payload() = arp_.serialize();
            _frames_out.push(ethernet_frame);

            // refresh _ip_waiting_arp
            _ip_waiting_arp.emplace(next_hop_ip,_ip_waiting_default_ttl);

        }
        // refresh _internet_datagram_waiting_arp{}
        std::pair<Address, InternetDatagram> now_pair(next_hop,dgram);
        _internet_datagram_waiting_arp.emplace_back(now_pair);

    }
}

//! \param[in] frame the incoming Ethernet frame
optional<InternetDatagram> NetworkInterface::recv_frame(const EthernetFrame &frame) {
//    DUMMY_CODE(frame);
    auto recv_header = frame.header();
    if (recv_header.dst != _ethernet_address && recv_header.dst != ETHERNET_BROADCAST){
                                             // arp need to be response
        return {};
    }

    // deal frame
    switch (recv_header.type){

        case  EthernetHeader::TYPE_ARP :
            // response
            {
                ARPMessage recv_arp;
                auto arp_parse_result = recv_arp.parse(frame.payload());
                if (arp_parse_result == ParseResult::NoError) {
                    // 处理arp        请求包回复 响应包对应的全发出去
                    // refresh arp table

                    // 请求包
                    if(recv_arp.target_ip_address == _ip_address.ipv4_numeric()  && recv_arp.opcode == ARPMessage::OPCODE_REQUEST){

                        // reply
                        ARPMessage arp_reply;
                        arp_reply.opcode = ARPMessage::OPCODE_REPLY;
                        arp_reply.sender_ethernet_address = _ethernet_address;
                        arp_reply.sender_ip_address = _ip_address.ipv4_numeric();
                        arp_reply.target_ethernet_address = recv_arp.sender_ethernet_address;
                        arp_reply.target_ip_address = recv_arp.sender_ip_address;

                        //
                        EthernetFrame ethernet_frame;
                        ethernet_frame.header() = {recv_arp.sender_ethernet_address,_ethernet_address,EthernetHeader::TYPE_ARP};
                        ethernet_frame.payload() = arp_reply.serialize();
                        _frames_out.push(ethernet_frame);
                    }
                    // 响应包
                    /// recv_arp.target_ethernet_address == _ethernet_address
                    if( recv_arp.target_ip_address == _ip_address.ipv4_numeric()  && recv_arp.opcode == ARPMessage::OPCODE_REPLY){

                    }
                    auto sender_ip = recv_arp.sender_ip_address;
                    auto sender_ethernet = recv_arp.sender_ethernet_address;
                    _arp_table[sender_ip] = {sender_ethernet, _arp_default_ttl};


                    for(auto it = _internet_datagram_waiting_arp.begin() ; it !=_internet_datagram_waiting_arp.end();  ){
                        Address address = (*it).first;
                        InternetDatagram internetDatagram = (*it).second;
                        if(address.ipv4_numeric() == sender_ip){
                            send_datagram(internetDatagram,address);
                            auto copy_it = it ;
                            it = _internet_datagram_waiting_arp.erase(copy_it);
//                            it-- ;
                        }
                        else{
                            it++;
                        }
                    }


                    _ip_waiting_arp.erase(sender_ip);
                    return {};




                }
                if (arp_parse_result != ParseResult::NoError) {
                    return {};
                }

                break;
            }


        case  EthernetHeader::TYPE_IPv4 :
            {
                InternetDatagram recv_datagram;
                auto parse_result = recv_datagram.parse(frame.payload());
                if (parse_result == ParseResult::NoError) {
                    return recv_datagram;
                }
                if (parse_result != ParseResult::NoError) {
                    return {};
                }

                break;
            }



//        default :
            // do nothing

    }





    return {};

}

//! \param[in] ms_since_last_tick the number of milliseconds since the last call to this method
void NetworkInterface::tick(const size_t ms_since_last_tick) {
//    DUMMY_CODE(ms_since_last_tick);
        for (auto it = _arp_table.begin(); it != _arp_table.end(); ) {
            if (it->second.second <= 0 + ms_since_last_tick) {
                it = _arp_table.erase(it);
//                it--;
            } else {
                it->second.second = it->second.second - ms_since_last_tick;
                it++;
            }
        }

        for (auto it1 = _ip_waiting_arp.begin(); it1 != _ip_waiting_arp.end(); it1++ ) {
            if (it1->second <= 0 + ms_since_last_tick){
                ARPMessage arp_;
                arp_.opcode = ARPMessage::OPCODE_REQUEST;
                arp_.sender_ethernet_address = _ethernet_address;
                arp_.sender_ip_address = _ip_address.ipv4_numeric();
                arp_.target_ethernet_address = {  };
                arp_.target_ip_address = it1->first;

                //
                EthernetFrame ethernet_frame;
                ethernet_frame.header() = {ETHERNET_BROADCAST,_ethernet_address,EthernetHeader::TYPE_ARP};
                ethernet_frame.payload() = arp_.serialize();
                _frames_out.push(ethernet_frame);

                // refresh _ip_waiting_arp
                _ip_waiting_arp[it1->first] = _ip_waiting_default_ttl;


            }
            else {
                it1->second =it1->second - ms_since_last_tick;

            }



        }
}


