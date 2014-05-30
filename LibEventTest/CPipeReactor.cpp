#include "stdafx.h"
#include "CPipeReactor.h"
#include "CPipe.h"
#include "INetEventHandler.h"
#include "CEventCallback.h"

#include <event2/listener.h>
#include <event2/event_struct.h>
#include <event2/bufferevent.h>
#include <event2/buffer.h>

using namespace std;

CPipeReactor::CPipeReactor()
	: ev_base_(NULL)
	, ev_listener_(NULL)
	, ev_event_(NULL)
{
	event_handler_ = new CDefaultNetEventHandler;
}

CPipeReactor::~CPipeReactor()
{
	assert(!ev_listener_);
	assert(!ev_base_);
	assert(!ev_event_);

	delete event_handler_;
	event_handler_ = NULL;

	for (auto pipe : lst_pipe_)
	{
		delete pipe;
	}
}

void CPipeReactor::SetEventHandler(INetEventHandler* handler)
{
	if (event_handler_)
	{
		delete event_handler_;
		event_handler_ = 0;
	}
	event_handler_ = handler;
}

bool CPipeReactor::Listen(int port)
{
	assert(!ev_base_);
	ev_base_ = event_base_new();
	if (!ev_base_)
	{
		return false;
	}

	sockaddr_in sin;
	memset(&sin, 0, sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);

	// register conn listener
	ev_listener_ = evconnlistener_new_bind(ev_base_, CEventCallback::ListenerCB, (void*)this, 
		LEV_OPT_REUSEABLE | LEV_OPT_CLOSE_ON_FREE, -1, (sockaddr*)&sin, sizeof(sin));
	if (!ev_listener_)
	{
		cerr << "listen failed!" << strerror(errno) << " " << GetLastError() << endl;
		return false;
	}

	// register event handler
	ev_event_ = evsignal_new(ev_base_, SIGINT, CEventCallback::SignalCB, (void*)this);
	if (!ev_event_ || event_add(ev_event_, NULL) < 0)
	{
		cerr << "create signal event failed!" << endl;
		return false;
	}

	// register a timer
	event* ev_event_timeout = new event;
	// flags: 0 , EV_PERSIST 
	event_assign(ev_event_timeout, ev_base_, -1, EV_PERSIST, CEventCallback::TimeoutCB, (void*)ev_event_timeout);

	timeval tv;
	evutil_timerclear(&tv);
	tv.tv_sec = 3;
	event_add(ev_event_timeout, &tv);

	cout << "server start listen at " << port << endl;
	event_handler_->OnStartListen();

	//begin event loop
	event_base_dispatch(ev_base_);

	return true;
}

CPipe* CPipeReactor::Connect(const char* ip, int port)
{
	assert(!ev_base_);

	ev_base_ = event_base_new();
	if (!ev_base_)
	{
		return NULL;
	}

	bufferevent* bev = bufferevent_socket_new(ev_base_, -1, BEV_OPT_CLOSE_ON_FREE);
	if (!bev)
	{
		return NULL;
	}

	sockaddr_in addr;
	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.S_un.S_addr = inet_addr(ip);

	int sockfd = bufferevent_socket_connect(bev, (sockaddr*)&addr, sizeof(addr));
	if (sockfd < 0)
	{
		cout << strerror(errno) << " " << GetLastError() << endl;
		return NULL;
	}

	CPipe* pipe = new CPipe(this, bev);
	AddPipe(pipe);

	event_handler_->OnConnected(pipe);

	event_base_dispatch(ev_base_);

	return pipe;
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

void CPipeReactor::Close()
{
	if (ev_event_)
	{
		event_free(ev_event_);
		ev_event_ = NULL;
	}
	
	if (ev_listener_)
	{
		evconnlistener_free(ev_listener_);
		ev_listener_ = NULL;
	}
	
	if (ev_base_)
	{
		event_base_free(ev_base_);
		ev_base_ = NULL;
	}

	event_handler_->OnNetworkClosed();
}