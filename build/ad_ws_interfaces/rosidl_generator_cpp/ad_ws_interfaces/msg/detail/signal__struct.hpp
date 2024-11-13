// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ad_ws_interfaces:msg/Signal.idl
// generated code does not contain a copyright notice

#ifndef AD_WS_INTERFACES__MSG__DETAIL__SIGNAL__STRUCT_HPP_
#define AD_WS_INTERFACES__MSG__DETAIL__SIGNAL__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ad_ws_interfaces__msg__Signal __attribute__((deprecated))
#else
# define DEPRECATED__ad_ws_interfaces__msg__Signal __declspec(deprecated)
#endif

namespace ad_ws_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Signal_
{
  using Type = Signal_<ContainerAllocator>;

  explicit Signal_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->value = 0.0f;
    }
  }

  explicit Signal_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->value = 0.0f;
    }
  }

  // field types and members
  using _value_type =
    float;
  _value_type value;

  // setters for named parameter idiom
  Type & set__value(
    const float & _arg)
  {
    this->value = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ad_ws_interfaces::msg::Signal_<ContainerAllocator> *;
  using ConstRawPtr =
    const ad_ws_interfaces::msg::Signal_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ad_ws_interfaces::msg::Signal_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ad_ws_interfaces::msg::Signal_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ad_ws_interfaces::msg::Signal_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ad_ws_interfaces::msg::Signal_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ad_ws_interfaces::msg::Signal_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ad_ws_interfaces::msg::Signal_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ad_ws_interfaces::msg::Signal_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ad_ws_interfaces::msg::Signal_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ad_ws_interfaces__msg__Signal
    std::shared_ptr<ad_ws_interfaces::msg::Signal_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ad_ws_interfaces__msg__Signal
    std::shared_ptr<ad_ws_interfaces::msg::Signal_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Signal_ & other) const
  {
    if (this->value != other.value) {
      return false;
    }
    return true;
  }
  bool operator!=(const Signal_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Signal_

// alias to use template instance with default allocator
using Signal =
  ad_ws_interfaces::msg::Signal_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace ad_ws_interfaces

#endif  // AD_WS_INTERFACES__MSG__DETAIL__SIGNAL__STRUCT_HPP_
