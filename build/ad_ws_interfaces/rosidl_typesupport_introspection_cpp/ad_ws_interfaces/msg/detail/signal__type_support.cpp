// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from ad_ws_interfaces:msg/Signal.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "ad_ws_interfaces/msg/detail/signal__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace ad_ws_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void Signal_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) ad_ws_interfaces::msg::Signal(_init);
}

void Signal_fini_function(void * message_memory)
{
  auto typed_message = static_cast<ad_ws_interfaces::msg::Signal *>(message_memory);
  typed_message->~Signal();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Signal_message_member_array[1] = {
  {
    "value",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ad_ws_interfaces::msg::Signal, value),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Signal_message_members = {
  "ad_ws_interfaces::msg",  // message namespace
  "Signal",  // message name
  1,  // number of fields
  sizeof(ad_ws_interfaces::msg::Signal),
  Signal_message_member_array,  // message members
  Signal_init_function,  // function to initialize message memory (memory has to be allocated)
  Signal_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Signal_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Signal_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace ad_ws_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<ad_ws_interfaces::msg::Signal>()
{
  return &::ad_ws_interfaces::msg::rosidl_typesupport_introspection_cpp::Signal_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, ad_ws_interfaces, msg, Signal)() {
  return &::ad_ws_interfaces::msg::rosidl_typesupport_introspection_cpp::Signal_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
