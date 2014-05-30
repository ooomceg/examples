#pragma once
#include "IPipeEventHandler.h"
#include "TPBMsgReceiver.h"
#include "TPBMsgSender.h"
#include "ISend.h"

class CPipe;
class S2C_Test;

class CPipeEventClientHandler
	: public IPipeEventHandler
	, public TPBMsgSender<CPipeEventClientHandler>
	, public TPBMsgReceiver<CPipeEventClientHandler>
	, public ISend
{
public:
	CPipeEventClientHandler(CPipe* pipe);

	void Send(const char* data, size_t sz);

	virtual void OnRecv(const char* data, size_t sz);

	static void InitMsgHandle();

	// msg handler
	void OnRemoteMsg(const S2C_Test& msg);
	// ---
private:
	CPipe*			pipe_;
};