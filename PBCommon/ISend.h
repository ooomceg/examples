#pragma once

class ISend
{
public:
	virtual void Send(const char* data, size_t sz) = 0;
};