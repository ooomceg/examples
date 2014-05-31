#pragma once
#include "IPipeEventHandler.h"
#include "TPBMsgReceiver.h"
#include "TPBMsgSender.h"
#include "ISend.h"


class CPipe;
class C2S_Test;
class C2S_Hello;

class CPipeEventServerHandler
	: public IPipeEventHandler
	, public TPBMsgSender<CPipeEventServerHandler>
	, public TPBMsgReceiver<CPipeEventServerHandler>
	, public ISend
{
public:
	CPipeEventServerHandler(CPipe* pipe);

	virtual size_t OnRecv(const char* data, size_t sz);

	void Send(const char* data, size_t sz);

	static void InitMsgHandle();

	// msg handler
	void OnRemoteMsg(const C2S_Test& msg);
	void OnRemoteMsg(const C2S_Hello& msg);
	// ---
private:
	CPipe* pipe_;
};