#pragma once

namespace PtlMapper
{
	template <uint32 msgid> struct GetTypeById { };
	template <typename MsgType> struct GetIdByType { };
}

#define CREATE_MAPPER(msgid, msgtype) \
	namespace PtlMapper { \
	template < > struct GetTypeById<msgid> { typedef msgtype res; }; \
	template < > struct GetIdByType<msgtype> { enum { res = msgid }; }; \
}

// macro function def
#define GENCODE_NETWORK_ENUM(name) e##name,
#define GENCODE_NETWORK_MAPPER(name) CREATE_MAPPER(e##name, name)
#define GENCODE_NETWORK_FUNDEF(name) void OnRemoteMsg(const name& msg);
#define GENCODE_NETWORK_DECL(name) class name;
// macro function dispatcher
#define GENCODE_NETWORK(tag, name) GENCODE_NETWORK_##tag(name)

// macro function entrance for client
#define GENCODE_NETWORK_ALL_C2S(tag) \
	GENCODE_NETWORK(tag, C2S_Test) \
	GENCODE_NETWORK(tag, C2S_Hello)

// macro function entrance for server
#define GENCODE_NETWORK_ALL_S2C(tag) \
	GENCODE_NETWORK(tag, S2C_Test) \
	GENCODE_NETWORK(tag, S2C_Hello)