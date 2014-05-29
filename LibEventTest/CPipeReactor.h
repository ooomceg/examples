#pragma once
#include <event2/util.h>

class CPipe;
struct event_base;
struct evconnlistener;
struct event;

class CPipeReactor
{
	typedef list<CPipe*> LstPipe;
public:
	CPipeReactor();
	~CPipeReactor();

	void AddPipe(CPipe*);
	void DelPipe(CPipe*);

	void Broadcast(const char* data, size_t size);

	void Start(int port);
	void End();
private:
	static void ListenerCB(evconnlistener *, evutil_socket_t, sockaddr *, int socklen, void *);
	static void SignalCB(evutil_socket_t, short, void *);
	static void TimeoutCB(evutil_socket_t, short, void *);
private:
	event_base*			ev_base_;
	evconnlistener*		ev_listener_;
	event*				ev_event_;
	LstPipe				lst_pipe_;
};