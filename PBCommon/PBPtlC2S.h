#pragma once
#include "PBPtlBase.h"
#include "Client2Server.pb.h"

enum EPtlC2S
{
	eC2S_begin = 0x4321,
	eC2S_Test,
	eC2S_end,
};

namespace PtlMapper
{
	template < > struct GetTypeById<eC2S_Test> { typedef C2S_Test res; };
	template < > struct GetIdByType<C2S_Test> { enum { res = eC2S_Test }; };
}
