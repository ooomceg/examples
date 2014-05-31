#pragma once

#include "stdafx.h"
#include "TPBMsgReceiver.h"
#include <google/protobuf/io/coded_stream.h>

template <typename HolderType>
typename TPBMsgReceiver<HolderType>::MapHandleFunc TPBMsgReceiver<HolderType>::s_maphandle;

template <typename HolderType>
void TPBMsgReceiver<HolderType>::RegisterHandleFunc(uint32 msgid, HandleFunc func)
{
	s_maphandle[msgid] = func;
}

template <typename HolderType>
typename TPBMsgReceiver<HolderType>::HandleFunc
TPBMsgReceiver<HolderType>::GetHandleFunc(uint32 msgid)
{
	return s_maphandle[msgid];
}

template <typename HolderType>
template <uint32 msgid>
void TPBMsgReceiver<HolderType>::OnRemoteMsg(const uint8* data, size_t sz)
{
	PtlMapper::GetTypeById<msgid>::res msg;
	msg.ParseFromArray(data, sz);
	static_cast<HolderType*>(this)->OnRemoteMsg(msg);;
}

template <typename HolderType>
size_t TPBMsgReceiver<HolderType>::OnRecv(const uint8* data, size_t size)
{
	using google::protobuf::io::CodedInputStream;

	static uint32 buflen = 0;
	static uint32 msgid = 0;
	static uint32 prefixlen = sizeof(buflen) + sizeof(msgid);

	if (size < sizeof(buflen))
	{
		return 0;
	}

	CodedInputStream::ReadLittleEndian32FromArray(data, &buflen);

	if (buflen > size)
	{
		return 0;
	}
	
	CodedInputStream::ReadLittleEndian32FromArray(data+sizeof(buflen), &msgid);

	HandleFunc func = GetHandleFunc(msgid);
	if (!func)
	{
		cerr << "invalid msg id: " << msgid << endl;
		return buflen;	// drop the data
	}
	
	(this->*func)(data+prefixlen, buflen - prefixlen);

	return buflen;
}