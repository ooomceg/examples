#include "stdafx.h"
#include "CPipeEventClientHandler.h"
#include "CPipe.h"
#include "TPBMsgReceiver.inl"
#include "TPBMsgSender.inl"

CPipeEventClientHandler::CPipeEventClientHandler(CPipe* pipe)
	: pipe_(pipe)
{

}

void CPipeEventClientHandler::Send(const char* data, size_t sz)
{
	pipe_->Send(data, sz);
}

size_t CPipeEventClientHandler::OnRecv(const char* data, size_t sz)
{
	return TPBMsgReceiver<CPipeEventClientHandler>::OnRecv((const uint8*)(data), sz);
}