#pragma once

template <typename HolderType>
class TPBMsgReceiver
{
	typedef void (TPBMsgReceiver<HolderType>::*HandleFunc)(const uint8* data, size_t sz);
	typedef map<uint32, HandleFunc> MapHandleFunc;	// 考虑改用hashmap或者vector来做
public:
	template <typename MsgType>
	void Send(const MsgType& msg);

	size_t OnRecv(const uint8* data, size_t sz);
protected:
	template <uint32 msgid>
	void OnRemoteMsg(const uint8* data, size_t sz);

	static void RegisterHandleFunc(uint32, HandleFunc);
private:
	HandleFunc GetHandleFunc(uint32);
private:
	static MapHandleFunc s_maphandle;
};