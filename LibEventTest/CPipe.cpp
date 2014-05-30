#include "stdafx.h"
#include "CPipe.h"
#include "CPipeReactor.h"
#include "IPipeEventHandler.h"

#include <event2/bufferevent.h>
#include <event2/buffer.h>
#include <event2/event.h>

CPipe::CPipe(CPipeReactor* reactor, bufferevent* bev)
	: reactor_(reactor)
	, ev_bev_(bev)
{
	event_handler_ = new CDefaultPipeEventHandler;
	bufferevent_setcb(ev_bev_, ReadCB, WriteCB, EventCB, this);
	bufferevent_enable(ev_bev_, EV_WRITE);
	bufferevent_enable(ev_bev_, EV_READ);
}

CPipe::~CPipe()
{
	delete event_handler_;
	event_handler_ = NULL;
	bufferevent_free(ev_bev_);
	ev_bev_ = NULL;
	reactor_->DelPipe(this);
}

void CPipe::Send(const char* data, size_t len)
{
	evbuffer* output = bufferevent_get_output(ev_bev_);
	bufferevent_write(ev_bev_, data, len);
}

void CPipe::OnRecv(const char* data, size_t len)
{
	event_handler_->OnRecv(data, len);
}

void CPipe::SetEventHandler(IPipeEventHandler* handler)
{
	if (event_handler_)
	{
		delete event_handler_;
		event_handler_ = NULL;
	}
	event_handler_ = handler;
}

void CPipe::ReadCB(bufferevent* bev, void* user_data)
{
	auto pipe = static_cast<CPipe*>(user_data);

	evbuffer* input = bufferevent_get_input(bev);
	size_t sz = evbuffer_get_length(input);

	char buf[1024];
	int n;
	while ((n = evbuffer_remove(input, buf, sizeof(buf))) > 0)
	{
		pipe->event_handler_->OnRecv(buf, n);
	}
}

void CPipe::WriteCB(bufferevent *bev, void *user_data)
{
	auto pipe = static_cast<CPipe*>(user_data);

	evbuffer* output = bufferevent_get_output(bev);
	if (evbuffer_get_length(output) == 0) {
		//printf("flushed answer\n");
		//delete pipe;
		//pipe->event_handler_->OnSent();
	}
}

void CPipe::EventCB(bufferevent *bev, short events, void *user_data)
{
	auto pipe = static_cast<CPipe*>(user_data);

	if (events & BEV_EVENT_EOF) {
		printf("Connection closed.\n");
		delete pipe;
	}
	else if (events & BEV_EVENT_CONNECTED) {
		cout << "client connected!" << endl;
	} else if (events & BEV_EVENT_ERROR) {
		printf("Got an error on the connection: %s\n",
		    strerror(errno));/*XXX win32*/
		delete pipe;
	}
	/* None of the other events can happen here, since we haven't enabled
	 * timeouts */
}