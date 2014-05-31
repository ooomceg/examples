#include "stdafx.h"
#include "CPipeEventClientHandler.h"
#include "TPBMsgReceiver.inl"
#include "TPBMsgSender.inl"

void CPipeEventClientHandler::InitMsgHandle()
{
	typedef TPBMsgReceiver<CPipeEventClientHandler> receiver_t;
	RegisterHandleFunc(eS2C_Test, &receiver_t::OnRemoteMsg<eS2C_Test>);
	RegisterHandleFunc(eS2C_Hello, &receiver_t::OnRemoteMsg<eS2C_Hello>);
}

void CPipeEventClientHandler::OnRemoteMsg(const S2C_Test& msg)
{
	cout << "recv S2C_Test msg!!" << endl;
	cout << msg.id() << " " << msg.str() << endl;

	C2S_Hello hello;
	hello.add_aa(55);
	hello.add_aa(66);
	hello.add_aa(77);
	SendMsg(hello);
	SendMsg(hello);
}

void CPipeEventClientHandler::OnRemoteMsg(const S2C_Hello& msg)
{
	cout << "recv S2C_Hello msg!!" << endl;
	copy(msg.ss().begin(), msg.ss().end(), ostream_iterator<string>(cout, " "));
	cout << endl;
}