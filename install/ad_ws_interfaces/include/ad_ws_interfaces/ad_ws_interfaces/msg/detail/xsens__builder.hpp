// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ad_ws_interfaces:msg/Xsens.idl
// generated code does not contain a copyright notice

#ifndef AD_WS_INTERFACES__MSG__DETAIL__XSENS__BUILDER_HPP_
#define AD_WS_INTERFACES__MSG__DETAIL__XSENS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ad_ws_interfaces/msg/detail/xsens__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ad_ws_interfaces
{

namespace msg
{

namespace builder
{

class Init_Xsens_rate_of_turn_x
{
public:
  explicit Init_Xsens_rate_of_turn_x(::ad_ws_interfaces::msg::Xsens & msg)
  : msg_(msg)
  {}
  ::ad_ws_interfaces::msg::Xsens rate_of_turn_x(::ad_ws_interfaces::msg::Xsens::_rate_of_turn_x_type arg)
  {
    msg_.rate_of_turn_x = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ad_ws_interfaces::msg::Xsens msg_;
};

class Init_Xsens_acc_z
{
public:
  explicit Init_Xsens_acc_z(::ad_ws_interfaces::msg::Xsens & msg)
  : msg_(msg)
  {}
  Init_Xsens_rate_of_turn_x acc_z(::ad_ws_interfaces::msg::Xsens::_acc_z_type arg)
  {
    msg_.acc_z = std::move(arg);
    return Init_Xsens_rate_of_turn_x(msg_);
  }

private:
  ::ad_ws_interfaces::msg::Xsens msg_;
};

class Init_Xsens_acc_y
{
public:
  explicit Init_Xsens_acc_y(::ad_ws_interfaces::msg::Xsens & msg)
  : msg_(msg)
  {}
  Init_Xsens_acc_z acc_y(::ad_ws_interfaces::msg::Xsens::_acc_y_type arg)
  {
    msg_.acc_y = std::move(arg);
    return Init_Xsens_acc_z(msg_);
  }

private:
  ::ad_ws_interfaces::msg::Xsens msg_;
};

class Init_Xsens_acc_x
{
public:
  Init_Xsens_acc_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Xsens_acc_y acc_x(::ad_ws_interfaces::msg::Xsens::_acc_x_type arg)
  {
    msg_.acc_x = std::move(arg);
    return Init_Xsens_acc_y(msg_);
  }

private:
  ::ad_ws_interfaces::msg::Xsens msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ad_ws_interfaces::msg::Xsens>()
{
  return ad_ws_interfaces::msg::builder::Init_Xsens_acc_x();
}

}  // namespace ad_ws_interfaces

#endif  // AD_WS_INTERFACES__MSG__DETAIL__XSENS__BUILDER_HPP_
