#pragma once
#include "GenCodeMacroDef.h"
#include "Client2Server.pb.h"

enum EPtlC2S
{
	eC2S_begin = 0x4321,
	GENCODE_NETWORK_ALL_C2S(ENUM)
	eC2S_end,
};

GENCODE_NETWORK_ALL_C2S(MAPPER);