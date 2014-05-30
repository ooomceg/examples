#pragma once
#include "PBPtlBase.h"
#include "Server2Client.pb.h"

enum EPtlS2C
{
	eS2C_begin = 0x1234,
	eS2C_Test,
	eS2C_end,
};

namespace PtlMapper
{
	template < > struct GetTypeById<eS2C_Test> { typedef S2C_Test res; };
	template < > struct GetIdByType<S2C_Test> { enum { res = eS2C_Test }; };
}
