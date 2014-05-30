#pragma once

class CPipe;
class INetEventHandler
{
public:
	virtual void OnStartListen() = 0;
	virtual void OnNetworkClosed() = 0;
	virtual void OnConnected(CPipe* pipe) = 0;
	virtual void OnClientConnConnected(CPipe* pipe) = 0;
};

class CDefaultNetEventHandler
	: public INetEventHandler
{
public:
	virtual ~CDefaultNetEventHandler() { }
	virtual void OnStartListen() { }
	virtual void OnNetworkClosed() { }
	virtual void OnConnected(CPipe* pipe) { }
	virtual void OnClientConnConnected(CPipe* pipe) { }
};