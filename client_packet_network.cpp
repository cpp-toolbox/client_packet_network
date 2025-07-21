#include "client_packet_network.hpp"

void ClientPacketNetwork::tick() {
    std::vector<PacketWithSize> pws = network.get_network_events_received_since_last_tick();
    packet_handler.handle_packets(pws);
}
