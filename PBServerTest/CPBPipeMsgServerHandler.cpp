#include "stdafx.h"
#include "CPipeEventServerHandler.h"
#include "TPBMsgReceiver.inl"
#include "TPBMsgSender.inl"

void CPipeEventServerHandler::InitMsgHandle()
{
	typedef TPBMsgReceiver<CPipeEventServerHandler> receiver_t;
	RegisterHandleFunc(eC2S_Test, &receiver_t::OnRemoteMsg<eC2S_Test>);
	RegisterHandleFunc(eC2S_Hello, &receiver_t::OnRemoteMsg<eC2S_Hello>);
}

void CPipeEventServerHandler::OnRemoteMsg(const C2S_Test& msg)
{
	cout << "recv C2S_Test msg!" << endl;
	cout << msg.id() << " " << msg.str() << endl;

	S2C_Test reply;
	reply.set_id(5555);
	reply.set_str("r u ready ???");
	SendMsg(reply);
}

void CPipeEventServerHandler::OnRemoteMsg(const C2S_Hello& msg)
{
	cout << "recv C2S_Hello msg!" << endl;
	copy(msg.aa().begin(), msg.aa().end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	S2C_Hello hello;
	hello.add_ss("aaa");
	hello.add_ss("bbb");
	hello.add_ss("ccc");
	SendMsg(hello);
	SendMsg(hello);
}