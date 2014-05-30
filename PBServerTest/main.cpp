#include "stdafx.h"
#include "CPipeReactor.h"
#include "CPipeEventServerHandler.h"
#include "CNetEventServerHandler.h"
#include <WinSock2.h>

int main()
{
#ifdef WIN32
	WSADATA wsa_data;
	WSAStartup(MAKEWORD(2,1), &wsa_data);
#endif
	CPipeEventServerHandler::InitMsgHandle();

	auto reactor = new CPipeReactor;
	reactor->SetEventHandler(new CNetEventServerHandler);
	reactor->Listen(23456);
	reactor->Close();
	delete reactor;
	return 0;
}