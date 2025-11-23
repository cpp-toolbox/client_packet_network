#ifndef CLIENT_PACKET_NETWORK_HPP
#define CLIENT_PACKET_NETWORK_HPP

#include "sbpt_generated_includes.hpp"

/**
 * @brief a system which manages the network connection as well as automatically calling callbacks associated with
 * different packet types
 */
class ClientPacketNetwork {
  public:
    ClientPacketNetwork(std::string ip_address, uint16_t port = 7777,
                        OnConnectCallback on_connect_callback = default_on_connect_callback)
        : network(ip_address, port, on_connect_callback) {
        network.attempt_to_connect_to_server();
    };
    Network network;
    PacketHandler packet_handler;

    /**
     * @warn must be called frequently or else network events will not flow
     */
    void tick();
};

#endif // CLIENT_PACKET_NETWORK_HPP
