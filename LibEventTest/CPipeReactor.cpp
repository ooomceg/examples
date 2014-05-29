#include "stdafx.h"
#include "CPipeReactor.h"
#include "CPipe.h"

#include <event2/bufferevent.h>
#include <event2/buffer.h>
#include <event2/listener.h>
#include <event2/util.h>
#include <event2/event.h>
#include <event2/event_struct.h>

using namespace std;

CPipeReactor::CPipeReactor()
{
	ev_base_ = event_base_new();
	assert(ev_base_);
}

CPipeReactor::~CPipeReactor()
{
	assert(!ev_listener_);
	assert(!ev_base_);
	assert(!ev_event_);

	for (auto pipe : lst_pipe_)
	{
		delete pipe;
	}
}

void CPipeReactor::Start(int port)
{
	sockaddr_in sin;
	memset(&sin, 0, sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);

	// register conn listener
	ev_listener_ = evconnlistener_new_bind(ev_base_, ListenerCB, (void*)this, 
		LEV_OPT_REUSEABLE | LEV_OPT_CLOSE_ON_FREE, -1, (sockaddr*)&sin, sizeof(sin));
	if (!ev_listener_)
	{
		cerr << "listen failed!" << endl;
		return;
	}

	// register event handler
	ev_event_ = evsignal_new(ev_base_, SIGINT, SignalCB, (void*)this);
	if (!ev_event_ || event_add(ev_event_, NULL) < 0)
	{
		cerr << "create signal event failed!" << endl;
		return;
	}

	// register a timer
	event* ev_event_timeout = new event;
	// flags: 0 , EV_PERSIST 
	event_assign(ev_event_timeout, ev_base_, -1, EV_PERSIST, TimeoutCB, (void*)ev_event_timeout);

	timeval tv;
	evutil_timerclear(&tv);
	tv.tv_sec = 3;
	event_add(ev_event_timeout, &tv);

	cout << "server start listen at " << port << endl;

	//begin event loop
	event_base_dispatch(ev_base_);
}

void CPipeReactor::AddPipe(CPipe* pipe)
{
	lst_pipe_.push_back(pipe);
}

void CPipeReactor::DelPipe(CPipe* pipe)
{
	lst_pipe_.erase(remove(lst_pipe_.begin(), lst_pipe_.end(), pipe), lst_pipe_.end());
}

void CPipeReactor::Broadcast(const char* data, size_t size)
{
	for (auto pipe : lst_pipe_)
	{
		pipe->Send(data, size);
	}
}

void CPipeReactor::End()
{
	event_free(ev_event_);
	evconnlistener_free(ev_listener_);
	event_base_free(ev_base_);

	ev_event_ = NULL;
	ev_listener_ = NULL;
	ev_base_ = NULL;
}

void CPipeReactor::TimeoutCB(evutil_socket_t fd, short events, void* user_data)
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

void CPipeReactor::ListenerCB(evconnlistener* listener, evutil_socket_t fd, 
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

	reactor->AddPipe(new CPipe(reactor, bev));
}

void CPipeReactor::SignalCB(evutil_socket_t sig, short events, void *user_data)
{
	auto reactor = static_cast<CPipeReactor*>(user_data);
	timeval delay = { 2, 0 };

	printf("Caught an interrupt signal; exiting cleanly in two seconds.\n");

	event_base_loopexit(reactor->ev_base_, &delay);
}