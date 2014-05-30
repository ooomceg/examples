#pragma once
#include "INetEventHandler.h"

class CNetEventServerHandler
	: public CDefaultNetEventHandler
{
public:
	virtual void OnClientConnConnected(CPipe* pipe);
};