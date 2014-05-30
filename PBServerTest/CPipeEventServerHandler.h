#pragma once
#include "IPipeEventHandler.h"
#include "TPBMsgReceiver.h"
#include "TPBMsgSender.h"
#include "ISend.h"


class CPipe;
class C2S_Test;

class CPipeEventServerHandler
	: public IPipeEventHandler
	, public TPBMsgSender<CPipeEventServerHandler>
	, public TPBMsgReceiver<CPipeEventServerHandler>
	, public ISend
{
public:
	CPipeEventServerHandler(CPipe* pipe);

	virtual void OnRecv(const char* data, size_t sz);

	void Send(const char* data, size_t sz);

	static void InitMsgHandle();

	// msg handler
	void OnRemoteMsg(const C2S_Test& msg);
	// ---
private:
	CPipe* pipe_;
};