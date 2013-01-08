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
#include "MetaServerHandlerTCP.hpp"
#include "MetaServer.hpp"

/*
 * System Includes
 */
#include <boost/bind.hpp>
#include <boost/asio/placeholders.hpp>
#include <glog/logging.h>

MetaServerHandlerTCP::MetaServerHandlerTCP(MetaServer& ms, boost::asio::io_service& ios,
		              const std::string& address,
		              const unsigned int port )
   : acceptor_(ios, boost::asio::ip::tcp::tcp::endpoint( boost::asio::ip::tcp::tcp::v6(),port)),
	 m_msRef(ms),
     address_(address),
     port_(port)
{
	LOG(INFO) << "MetaServerHandlerTCP Startup : " << address << "," << port;

	acceptor_.set_option(boost::asio::ip::tcp::acceptor::reuse_address(true));
	//acceptor_.set_option(boost::asio::ip::v6_only(false));

	// requires root access ... probably raw socket access
	//acceptor_.set_option(boost::asio::ip::tcp::acceptor::debug(true));

	start_accept();

}

MetaServerHandlerTCP::~MetaServerHandlerTCP()
{
	LOG(INFO) << "MetaServerHandlerTCP Shutdown";
}

void
MetaServerHandlerTCP::start_accept()
{

	tcp_connection::pointer new_connection = tcp_connection::create(acceptor_.get_io_service());

	//logger.debugStream() << "New TCP Connection: " << new_connection->socket().remote_endpoint().address().to_string();

	acceptor_.async_accept(new_connection->socket(),
			boost::bind(&MetaServerHandlerTCP::handle_accept, this, new_connection,
			boost::asio::placeholders::error));
}

void
MetaServerHandlerTCP::handle_accept(tcp_connection::pointer new_connection,
				      const boost::system::error_code& error)
{

	if(!error)
	{
//		logger.debug("TCP-1 : read off packet");
//		logger.debug("TCP-2 : analyse packet");
//		logger.debug("TCP-3 : make call to ms object");
//		logger.debug("TCP-4 : get response from ms and construct packet");
//		logger.debug("TCP-5 : send async response");
//		logger.debug("TCP-6 : loop back to start accept");

		start_accept();
	} else {
//		logger.errorStream() << "ERROR:" << error.message();
		LOG(WARNING) << "ERROR: " << error.message();
	}

}


