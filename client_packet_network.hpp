#ifndef CLIENT_PACKET_NETWORK_HPP
#define CLIENT_PACKET_NETWORK_HPP

#include "sbpt_generated_includes.hpp"

class ClientPacketNetwork {
  public:
    ClientPacketNetwork(std::string ip_address, uint16_t port = 7777,
                        OnConnectCallback on_connect_callback = default_on_connect_callback)
        : network(ip_address, port, on_connect_callback) {
        network.initialize_network();
        network.attempt_to_connect_to_server();
    };
    Network network;
    PacketHandler packet_handler;

    void tick();
};

#endif // CLIENT_PACKET_NETWORK_HPP
