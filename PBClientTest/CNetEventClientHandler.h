#pragma once
#include "INetEventHandler.h"

class CNetEventClientHandler
	: public CDefaultNetEventHandler
{
public:
	virtual void OnConnected(CPipe* pipe);
};