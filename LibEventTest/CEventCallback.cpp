#include "stdafx.h"
#include "CEventCallback.h"
#include "CPipeReactor.h"
#include "CPipe.h"
#include "INetEventHandler.h"

#include <event2/bufferevent.h>
#include <event2/buffer.h>
#include <event2/listener.h>
#include <event2/util.h>
#include <event2/event.h>
#include <event2/event_struct.h>

void CEventCallback::TimeoutCB(evutil_socket_t fd, short events, void* user_data)
{
	static int counter = 0;
	++counter;
	auto ev_event_timeout = static_cast<event*>(user_data);
	cout << "on timer" << endl;
	//delete ev_event_timeout;
	if (counter == 10)
	{
		event_del(ev_event_timeout);
		delete ev_event_timeout;
	}
}

void CEventCallback::ListenerCB(evconnlistener* listener, evutil_socket_t fd, 
							  sockaddr* sa, int socklen, void* user_data)
{
	auto reactor = static_cast<CPipeReactor*>(user_data);
	event_base* base = reactor->ev_base_;

	bufferevent* bev = bufferevent_socket_new(base, fd, BEV_OPT_CLOSE_ON_FREE);
	if (!bev) {
		fprintf(stderr, "Error constructing bufferevent!");
		event_base_loopbreak(base);
		return;
	}

	CPipe* newpipe = new CPipe(reactor, bev);
	reactor->AddPipe(newpipe);

	reactor->event_handler_->OnClientConnConnected(newpipe);
}

void CEventCallback::SignalCB(evutil_socket_t sig, short events, void *user_data)
{
	auto reactor = static_cast<CPipeReactor*>(user_data);
	timeval delay = { 2, 0 };

	printf("Caught an interrupt signal; exiting cleanly in two seconds.\n");

	event_base_loopexit(reactor->ev_base_, &delay);
}