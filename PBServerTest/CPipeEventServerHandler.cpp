#include "stdafx.h"
#include "CPipeEventServerHandler.h"
#include "CPipe.h"
#include "Server2Client.pb.h"
#include "TPBMsgReceiver.inl"
#include "TPBMsgSender.inl"
#include "PBPtlS2C.h"

CPipeEventServerHandler::CPipeEventServerHandler(CPipe* pipe)
	: pipe_(pipe)
{

}

void CPipeEventServerHandler::Send(const char* data, size_t sz)
{
	pipe_->Send(data, sz);
}

size_t CPipeEventServerHandler::OnRecv(const char* data, size_t sz)
{
	cout << "recv msg: " << sz << endl;
	return TPBMsgReceiver<CPipeEventServerHandler>::OnRecv((const uint8*)(data), sz);
}