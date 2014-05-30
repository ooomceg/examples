#pragma once

template <typename HolderType>
class TPBMsgSender
{
public:
	template <typename PBMsgType>
	void SendMsg(const PBMsgType& msg);
};