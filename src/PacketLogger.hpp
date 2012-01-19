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

#ifndef PACKETLOGGER_HPP_
#define PACKETLOGGER_HPP_

/*
 * Local Includes
 */
#include "MetaServerPacket.hpp"
#include "DataObject.hpp"
#include "PacketLogger.hpp"

/*
 * System Includes
 */
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <map>
#include <queue>
#include <algorithm>

#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/posix_time/posix_time_types.hpp>
#include <boost/date_time/gregorian/gregorian_types.hpp>

class PacketLogger
{

public:

	PacketLogger();
	PacketLogger(std::string file);
	~PacketLogger();

	void LogPacket(MetaServerPacket msp);

	void flush(unsigned int exp);

	std::ofstream m_Write;
	std::list<MetaServerPacket> m_Plist;
	std::string m_File;
	boost::posix_time::ptime m_lastRefresh;

};

#endif /* PACKETLOGGER_HPP_ */
