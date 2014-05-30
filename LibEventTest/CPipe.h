#pragma once

struct bufferevent;
class CPipeReactor;
class IPipeEventHandler;

class CPipe
{
public:
	CPipe(CPipeReactor*, bufferevent*);
	virtual ~CPipe();
	
	void Send(const char*, size_t size);
	void SetEventHandler(IPipeEventHandler* handler);
	IPipeEventHandler* GetEventHandler() const		{ return event_handler_; }
protected:
	void OnRecv(const char*, size_t size);
private:
	static void ReadCB(bufferevent* bev, void* user_data);
	static void WriteCB(bufferevent* bev, void* user_data);
	static void EventCB(bufferevent* bev, short events, void* user_data);
private:
	CPipeReactor*		reactor_;
	IPipeEventHandler*	event_handler_;
	bufferevent*		ev_bev_;
};