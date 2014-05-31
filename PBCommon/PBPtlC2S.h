#pragma once
#include "PBPtlBase.h"
#include "Client2Server.pb.h"

enum EPtlC2S
{
	eC2S_begin = 0x4321,
	eC2S_Test,
	eC2S_Hello,
	eC2S_end,
};

CREATE_MAPPER_BY_NAME(C2S_Test);
CREATE_MAPPER_BY_NAME(C2S_Hello);