#pragma once

namespace PtlMapper
{
	template <uint32 msgid> struct GetTypeById { };
	template <typename MsgType> struct GetIdByType { };
}