// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from ad_ws_interfaces:msg/Xsens.idl
// generated code does not contain a copyright notice

#ifndef AD_WS_INTERFACES__MSG__DETAIL__XSENS__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define AD_WS_INTERFACES__MSG__DETAIL__XSENS__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "ad_ws_interfaces/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "ad_ws_interfaces/msg/detail/xsens__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace ad_ws_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ad_ws_interfaces
cdr_serialize(
  const ad_ws_interfaces::msg::Xsens & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ad_ws_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  ad_ws_interfaces::msg::Xsens & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ad_ws_interfaces
get_serialized_size(
  const ad_ws_interfaces::msg::Xsens & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ad_ws_interfaces
max_serialized_size_Xsens(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace ad_ws_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ad_ws_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, ad_ws_interfaces, msg, Xsens)();

#ifdef __cplusplus
}
#endif

#endif  // AD_WS_INTERFACES__MSG__DETAIL__XSENS__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
