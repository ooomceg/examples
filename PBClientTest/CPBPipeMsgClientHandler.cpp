#include "stdafx.h"
#include "CPipeEventClientHandler.h"
#include "TPBMsgReceiver.inl"
#include "PBPtlS2C.h"

void CPipeEventClientHandler::InitMsgHandle()
{
	typedef TPBMsgReceiver<CPipeEventClientHandler> receiver_t;
	RegisterHandleFunc(eS2C_Test, &receiver_t::OnRemoteMsg<eS2C_Test>);
}

void CPipeEventClientHandler::OnRemoteMsg(const S2C_Test& msg)
{
	cout << "recv S2C_Test msg!!" << endl;
	cout << msg.id() << " " << msg.str() << endl;
}