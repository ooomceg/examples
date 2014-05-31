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

#define CREATE_MAPPER_BY_NAME(msgname) CREATE_MAPPER(e##msgname, msgname)