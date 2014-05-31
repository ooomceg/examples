#pragma once

class IPipeEventHandler
{
public:
	virtual size_t OnRecv(const char* data, size_t sz) = 0;
};

class CDefaultPipeEventHandler
	: public IPipeEventHandler
{
public:
	virtual size_t OnRecv(const char* data, size_t sz) { return sz; }
};