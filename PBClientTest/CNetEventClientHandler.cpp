#include "stdafx.h"
#include "CNetEventClientHandler.h"
#include "CPipe.h"
#include "CPipeEventClientHandler.h"
#include "PBPtlC2S.h"
#include "TPBMsgSender.inl"

void CNetEventClientHandler::OnConnected(CPipe* pipe)
{
	auto handler = new CPipeEventClientHandler(pipe);
	pipe->SetEventHandler(handler);

	C2S_Test msg;
	msg.set_id(123);
	msg.set_str("hello");
	handler->SendMsg(msg);
}