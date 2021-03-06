// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Server2Client.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "Server2Client.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace {

const ::google::protobuf::Descriptor* S2C_Test_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  S2C_Test_reflection_ = NULL;
const ::google::protobuf::Descriptor* S2C_Hello_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  S2C_Hello_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_Server2Client_2eproto() {
  protobuf_AddDesc_Server2Client_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "Server2Client.proto");
  GOOGLE_CHECK(file != NULL);
  S2C_Test_descriptor_ = file->message_type(0);
  static const int S2C_Test_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(S2C_Test, id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(S2C_Test, str_),
  };
  S2C_Test_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      S2C_Test_descriptor_,
      S2C_Test::default_instance_,
      S2C_Test_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(S2C_Test, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(S2C_Test, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(S2C_Test));
  S2C_Hello_descriptor_ = file->message_type(1);
  static const int S2C_Hello_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(S2C_Hello, ss_),
  };
  S2C_Hello_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      S2C_Hello_descriptor_,
      S2C_Hello::default_instance_,
      S2C_Hello_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(S2C_Hello, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(S2C_Hello, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(S2C_Hello));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_Server2Client_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    S2C_Test_descriptor_, &S2C_Test::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    S2C_Hello_descriptor_, &S2C_Hello::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_Server2Client_2eproto() {
  delete S2C_Test::default_instance_;
  delete S2C_Test_reflection_;
  delete S2C_Hello::default_instance_;
  delete S2C_Hello_reflection_;
}

void protobuf_AddDesc_Server2Client_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\023Server2Client.proto\"#\n\010S2C_Test\022\n\n\002id\030"
    "\001 \002(\005\022\013\n\003str\030\002 \002(\t\"\027\n\tS2C_Hello\022\n\n\002ss\030\001 "
    "\003(\t", 83);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "Server2Client.proto", &protobuf_RegisterTypes);
  S2C_Test::default_instance_ = new S2C_Test();
  S2C_Hello::default_instance_ = new S2C_Hello();
  S2C_Test::default_instance_->InitAsDefaultInstance();
  S2C_Hello::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_Server2Client_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_Server2Client_2eproto {
  StaticDescriptorInitializer_Server2Client_2eproto() {
    protobuf_AddDesc_Server2Client_2eproto();
  }
} static_descriptor_initializer_Server2Client_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int S2C_Test::kIdFieldNumber;
const int S2C_Test::kStrFieldNumber;
#endif  // !_MSC_VER

S2C_Test::S2C_Test()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void S2C_Test::InitAsDefaultInstance() {
}

S2C_Test::S2C_Test(const S2C_Test& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void S2C_Test::SharedCtor() {
  _cached_size_ = 0;
  id_ = 0;
  str_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

S2C_Test::~S2C_Test() {
  SharedDtor();
}

void S2C_Test::SharedDtor() {
  if (str_ != &::google::protobuf::internal::kEmptyString) {
    delete str_;
  }
  if (this != default_instance_) {
  }
}

void S2C_Test::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* S2C_Test::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return S2C_Test_descriptor_;
}

const S2C_Test& S2C_Test::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_Server2Client_2eproto();
  return *default_instance_;
}

S2C_Test* S2C_Test::default_instance_ = NULL;

S2C_Test* S2C_Test::New() const {
  return new S2C_Test;
}

void S2C_Test::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    id_ = 0;
    if (has_str()) {
      if (str_ != &::google::protobuf::internal::kEmptyString) {
        str_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool S2C_Test::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required int32 id = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &id_)));
          set_has_id();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(18)) goto parse_str;
        break;
      }

      // required string str = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_str:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_str()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->str().data(), this->str().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void S2C_Test::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required int32 id = 1;
  if (has_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->id(), output);
  }

  // required string str = 2;
  if (has_str()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->str().data(), this->str().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      2, this->str(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* S2C_Test::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required int32 id = 1;
  if (has_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->id(), target);
  }

  // required string str = 2;
  if (has_str()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->str().data(), this->str().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->str(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int S2C_Test::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required int32 id = 1;
    if (has_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->id());
    }

    // required string str = 2;
    if (has_str()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->str());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void S2C_Test::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const S2C_Test* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const S2C_Test*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void S2C_Test::MergeFrom(const S2C_Test& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_id()) {
      set_id(from.id());
    }
    if (from.has_str()) {
      set_str(from.str());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void S2C_Test::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void S2C_Test::CopyFrom(const S2C_Test& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool S2C_Test::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000003) != 0x00000003) return false;

  return true;
}

void S2C_Test::Swap(S2C_Test* other) {
  if (other != this) {
    std::swap(id_, other->id_);
    std::swap(str_, other->str_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata S2C_Test::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = S2C_Test_descriptor_;
  metadata.reflection = S2C_Test_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int S2C_Hello::kSsFieldNumber;
#endif  // !_MSC_VER

S2C_Hello::S2C_Hello()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void S2C_Hello::InitAsDefaultInstance() {
}

S2C_Hello::S2C_Hello(const S2C_Hello& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void S2C_Hello::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

S2C_Hello::~S2C_Hello() {
  SharedDtor();
}

void S2C_Hello::SharedDtor() {
  if (this != default_instance_) {
  }
}

void S2C_Hello::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* S2C_Hello::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return S2C_Hello_descriptor_;
}

const S2C_Hello& S2C_Hello::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_Server2Client_2eproto();
  return *default_instance_;
}

S2C_Hello* S2C_Hello::default_instance_ = NULL;

S2C_Hello* S2C_Hello::New() const {
  return new S2C_Hello;
}

void S2C_Hello::Clear() {
  ss_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool S2C_Hello::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated string ss = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_ss:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->add_ss()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->ss(this->ss_size() - 1).data(),
            this->ss(this->ss_size() - 1).length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(10)) goto parse_ss;
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void S2C_Hello::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // repeated string ss = 1;
  for (int i = 0; i < this->ss_size(); i++) {
  ::google::protobuf::internal::WireFormat::VerifyUTF8String(
    this->ss(i).data(), this->ss(i).length(),
    ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      1, this->ss(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* S2C_Hello::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // repeated string ss = 1;
  for (int i = 0; i < this->ss_size(); i++) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->ss(i).data(), this->ss(i).length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target = ::google::protobuf::internal::WireFormatLite::
      WriteStringToArray(1, this->ss(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int S2C_Hello::ByteSize() const {
  int total_size = 0;

  // repeated string ss = 1;
  total_size += 1 * this->ss_size();
  for (int i = 0; i < this->ss_size(); i++) {
    total_size += ::google::protobuf::internal::WireFormatLite::StringSize(
      this->ss(i));
  }

  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void S2C_Hello::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const S2C_Hello* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const S2C_Hello*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void S2C_Hello::MergeFrom(const S2C_Hello& from) {
  GOOGLE_CHECK_NE(&from, this);
  ss_.MergeFrom(from.ss_);
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void S2C_Hello::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void S2C_Hello::CopyFrom(const S2C_Hello& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool S2C_Hello::IsInitialized() const {

  return true;
}

void S2C_Hello::Swap(S2C_Hello* other) {
  if (other != this) {
    ss_.Swap(&other->ss_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata S2C_Hello::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = S2C_Hello_descriptor_;
  metadata.reflection = S2C_Hello_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)
