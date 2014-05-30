#pragma once

#include "stdafx.h"
#include "TPBMsgSender.h"
#include "PBPtlS2C.h"
#include "PBPtlC2S.h"
#include "ISend.h"
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/io/zero_copy_stream_impl_lite.h>

const uint32 _BUF_SIZE = 1024;

template <typename HolderType>
template <typename PBMsgType>
void TPBMsgSender<HolderType>::SendMsg(const PBMsgType& msg)
{
	auto is = static_cast<ISend*>(static_cast<HolderType*>(this));

	uint32 msgid = PtlMapper::GetIdByType<PBMsgType>::res;
	uint32 msglen = msg.ByteSize();
	uint32 prefixlen = sizeof(msgid) + sizeof(msglen);
	uint32 bufferlen = prefixlen + msglen;

	static uint8 buf[_BUF_SIZE];
	google::protobuf::io::ArrayOutputStream array_output(buf, bufferlen);
	google::protobuf::io::CodedOutputStream coded_output(&array_output);

	coded_output.WriteLittleEndian32(bufferlen);
	coded_output.WriteLittleEndian32(msgid);

	msg.SerializeToCodedStream(&coded_output);

	is->Send((const char*)buf, bufferlen);
}