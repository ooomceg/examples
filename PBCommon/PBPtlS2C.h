#pragma once
#include "PBPtlBase.h"
#include "Server2Client.pb.h"

enum EPtlS2C
{
	eS2C_begin = 0x1234,
	eS2C_Test,
	eS2C_Hello,
	eS2C_end,
};

CREATE_MAPPER_BY_NAME(S2C_Test);
CREATE_MAPPER_BY_NAME(S2C_Hello);
