/**
 Worldforge Next Generation MetaServer

 Copyright (C) 2011 Sean Ryan <sryan@evercrack.com>

 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

 */

/*
 * Local Includes
 */
#include "MetaServerHandler.hpp"
#include "MetaServerPacket.hpp"

/*
 * System Includes
 */
#include <boost/asio/io_service.hpp>
#include <boost/asio/ip/udp.hpp>
#include <log4cpp/Category.hh>

/*
 * Forward Declarations
 */
class MetaServer;
class MetaServerPacket;

class MetaServerHandlerUDP : public MetaServerHandler
{

public:

	MetaServerHandlerUDP(MetaServer& ms, boost::asio::io_service& ios, const std::string address, const unsigned int port);
	~MetaServerHandlerUDP();
	void start_receive();
	void handle_receive(const boost::system::error_code& error, std::size_t);
	void handle_send(MetaServerPacket& p, const boost::system::error_code& error, std::size_t);
	void process_outbound(const boost::system::error_code& error);


private:

	boost::asio::ip::udp::socket m_Socket;
	boost::asio::ip::udp::endpoint m_remoteEndpoint;
	boost::array<char, MAX_PACKET_BYTES> m_recvBuffer;

	boost::asio::deadline_timer* m_outboundTimer;
	unsigned int m_outboundMaxInterval;
	unsigned long m_outboundTick;

	const std::string m_Address;
	const unsigned int m_Port;
	MetaServer& m_msRef;
	log4cpp::Category& logger;



};
