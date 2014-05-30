#pragma once

class IPipeEventHandler
{
public:
	virtual void OnRecv(const char* data, size_t sz) = 0;
};

class CDefaultPipeEventHandler
	: public IPipeEventHandler
{
public:
	virtual void OnRecv(const char* data, size_t sz) { }
};