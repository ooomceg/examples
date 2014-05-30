#pragma once

class CPipe;
class INetEventHandler;
struct event_base;
struct evconnlistener;
struct event;

class CPipeReactor
{
	friend class CEventCallback;
	typedef list<CPipe*> LstPipe;
public:
	CPipeReactor();
	~CPipeReactor();

	void SetEventHandler(INetEventHandler* handler);

	void AddPipe(CPipe*);
	void DelPipe(CPipe*);

	void Broadcast(const char* data, size_t size);

	bool Listen(int port);
	CPipe* Connect(const char* ip, int port);

	void Close();

private:
	INetEventHandler*	event_handler_;
	event_base*			ev_base_;
	evconnlistener*		ev_listener_;
	event*				ev_event_;
	LstPipe				lst_pipe_;
};