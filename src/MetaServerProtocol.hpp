/**
 * MetaServerProtocol.hpp
 *
 * Assumptions:
 * 		1) All valid error use cases will respond with a valid error response
 * 		2) All error use cases that are not valid, will just drop and not send any response
 *
 * 	NMT_NULL	Indicates that no response needs to be sent back
 * 		Type Size: 4 bytes
 * 		Value: 0
 * 		Payload Size: 0
 *
 * 	NMT_SERVERKEEPALIVE		indicates a keep alive for a server, also serves as a "registration"
 * 		Type Size: 4 bytes
 * 		Value: 1 ( 00 00 00 01 )
 * 		Payload Size: 0
 *
 * 	NMT_HANDSHAKE			Auth request
 * 		Type Size: 4 bytes
 * 		Value: 3 ( 00 00 00 03 )
 * 		Payload Size: 4 bytes ( a random int )
 *
 * 	NMT_SERVERSHAKE			Auth response
 * 		Type Size: 4 bytes
 * 		Value: 4 ( 00 00 00 04 )
 * 		Payload Size: 4 bytes ( random int )
 *
 *	Use Case 1: Server Registration or Keep-alive
 *		1) Server sends a NMT_SERVERKEEPALIVE
 *		2) MS responds with a NMT_HANDSHAKE, contains a random number, creates a record
 *		3) Server responds with NMT_SERVERSHAKE, contains same random number
 *
 */
#ifndef METASERVERPROTOCOL_HPP_
#define METASERVERPROTOCOL_HPP_

enum NetMsgType
{
  NMT_NULL = 0,
  NMT_SERVERKEEPALIVE = 1,
  NMT_CLIENTKEEPALIVE = 2,
  NMT_HANDSHAKE = 3,
  NMT_SERVERSHAKE = 4,
  NMT_CLIENTSHAKE = 5,
  NMT_TERMINATE = 6,
  NMT_LISTREQ = 7,
  NMT_LISTRESP = 8,
  NMT_PROTO_ERANGE = 9,
  NMT_LAST = 10
};


#endif /* METASERVERPROTOCOL_HPP_ */
