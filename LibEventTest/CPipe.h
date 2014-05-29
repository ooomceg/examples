#pragma once

struct bufferevent;
class CPipeReactor;

class CPipe
{
public:
	CPipe(CPipeReactor*, bufferevent*);
	~CPipe();
	
	void Send(const char*, size_t size);
private:
	static void ReadCB(bufferevent* bev, void* user_data);
	static void WriteCB(bufferevent* bev, void* user_data);
	static void EventCB(bufferevent* bev, short events, void* user_data);
private:
	CPipeReactor*	reactor_;
	bufferevent*	ev_bev_;
};