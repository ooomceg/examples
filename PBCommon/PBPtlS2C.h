#pragma once
#include "GenCodeMacroDef.h"
#include "Server2Client.pb.h"

enum EPtlS2C
{
	eS2C_begin = 0x1234,
	GENCODE_NETWORK_ALL_S2C(ENUM)
	eS2C_end,
};

GENCODE_NETWORK_ALL_S2C(MAPPER);