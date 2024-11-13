// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ad_ws_interfaces:msg/Xsens.idl
// generated code does not contain a copyright notice

#ifndef AD_WS_INTERFACES__MSG__DETAIL__XSENS__TRAITS_HPP_
#define AD_WS_INTERFACES__MSG__DETAIL__XSENS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ad_ws_interfaces/msg/detail/xsens__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ad_ws_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Xsens & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Xsens & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Xsens & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace ad_ws_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use ad_ws_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const ad_ws_interfaces::msg::Xsens & msg,
  std::ostream & out, size_t indentation = 0)
{
  ad_ws_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ad_ws_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const ad_ws_interfaces::msg::Xsens & msg)
{
  return ad_ws_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ad_ws_interfaces::msg::Xsens>()
{
  return "ad_ws_interfaces::msg::Xsens";
}

template<>
inline const char * name<ad_ws_interfaces::msg::Xsens>()
{
  return "ad_ws_interfaces/msg/Xsens";
}

template<>
struct has_fixed_size<ad_ws_interfaces::msg::Xsens>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ad_ws_interfaces::msg::Xsens>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ad_ws_interfaces::msg::Xsens>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // AD_WS_INTERFACES__MSG__DETAIL__XSENS__TRAITS_HPP_
