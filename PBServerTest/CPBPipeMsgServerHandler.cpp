#include "stdafx.h"
#include "CPipeEventServerHandler.h"
#include "TPBMsgReceiver.inl"
#include "TPBMsgSender.inl"

void CPipeEventServerHandler::InitMsgHandle()
{
	typedef TPBMsgReceiver<CPipeEventServerHandler> receiver_t;
	RegisterHandleFunc(eC2S_Test, &receiver_t::OnRemoteMsg<eC2S_Test>);
}

void CPipeEventServerHandler::OnRemoteMsg(const C2S_Test& msg)
{
	cout << "recv S2C_Test msg!" << endl;
	cout << msg.id() << " " << msg.str() << endl;

	S2C_Test reply;
	reply.set_id(5555);
	reply.set_str("r u ready ???");
	SendMsg(reply);
}