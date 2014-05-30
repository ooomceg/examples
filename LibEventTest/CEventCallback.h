#pragma once
#include <event2/util.h>

struct sockaddr;
struct evconnlistener;

class CEventCallback
{
public:
	static void ListenerCB(evconnlistener *, evutil_socket_t, sockaddr *, int socklen, void *);
	static void SignalCB(evutil_socket_t, short, void *);
	static void TimeoutCB(evutil_socket_t, short, void *);
};