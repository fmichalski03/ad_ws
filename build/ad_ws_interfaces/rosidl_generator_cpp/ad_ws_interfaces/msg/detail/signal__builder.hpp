// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ad_ws_interfaces:msg/Signal.idl
// generated code does not contain a copyright notice

#ifndef AD_WS_INTERFACES__MSG__DETAIL__SIGNAL__BUILDER_HPP_
#define AD_WS_INTERFACES__MSG__DETAIL__SIGNAL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ad_ws_interfaces/msg/detail/signal__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ad_ws_interfaces
{

namespace msg
{

namespace builder
{

class Init_Signal_value
{
public:
  Init_Signal_value()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::ad_ws_interfaces::msg::Signal value(::ad_ws_interfaces::msg::Signal::_value_type arg)
  {
    msg_.value = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ad_ws_interfaces::msg::Signal msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ad_ws_interfaces::msg::Signal>()
{
  return ad_ws_interfaces::msg::builder::Init_Signal_value();
}

}  // namespace ad_ws_interfaces

#endif  // AD_WS_INTERFACES__MSG__DETAIL__SIGNAL__BUILDER_HPP_
