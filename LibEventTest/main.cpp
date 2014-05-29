#include "stdafx.h"
#include "CPipeReactor.h"

int main(int argc, char** argv)
{
#ifdef WIN32
	WSADATA wsa_data;
	WSAStartup(MAKEWORD(2,1), &wsa_data);
#endif
	auto reactor = new CPipeReactor();
	reactor->Start(9995);
	reactor->End();
	delete reactor;
	return 0;
}