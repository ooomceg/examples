#include "stdafx.h"
#include "CPipeReactor.h"
#include "CNetEventClientHandler.h"
#include "CPipeEventClientHandler.h"
#include <WinSock2.h>

int main()
{
#ifdef WIN32
	WSADATA wsa_data;
	WSAStartup(MAKEWORD(2,1), &wsa_data);
#endif
	CPipeEventClientHandler::InitMsgHandle();

	auto reactor = new CPipeReactor;
	reactor->SetEventHandler(new CNetEventClientHandler);
	reactor->Connect("127.0.0.1", 23456);
	reactor->Close();
	return 0;
}