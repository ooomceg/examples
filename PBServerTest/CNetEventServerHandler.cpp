#include "stdafx.h"
#include "CNetEventServerHandler.h"
#include "CPipe.h"
#include "CPipeEventServerHandler.h"

void CNetEventServerHandler::OnClientConnConnected(CPipe* pipe)
{
	pipe->SetEventHandler(new CPipeEventServerHandler(pipe));
}