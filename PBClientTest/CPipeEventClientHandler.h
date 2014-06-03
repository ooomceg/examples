#pragma once
#include "IPipeEventHandler.h"
#include "TPBMsgReceiver.h"
#include "TPBMsgSender.h"
#include "ISend.h"
#include "GenCodeMacroDef.h"

class CPipe;

GENCODE_NETWORK_ALL_S2C(DECL);

class CPipeEventClientHandler
	: public IPipeEventHandler
	, public TPBMsgSender<CPipeEventClientHandler>
	, public TPBMsgReceiver<CPipeEventClientHandler>
	, public ISend
{
public:
	CPipeEventClientHandler(CPipe* pipe);

	void Send(const char* data, size_t sz);

	virtual size_t OnRecv(const char* data, size_t sz);

	static void InitMsgHandle();

	// msg handler
	//void OnRemoteMsg(const S2C_Test& msg);
	//void OnRemoteMsg(const S2C_Hello& msg);
	GENCODE_NETWORK_ALL_S2C(FUNDEF);
	// ---
private:
	CPipe*			pipe_;
};