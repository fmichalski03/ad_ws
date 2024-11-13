// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ad_ws_interfaces:msg/Xsens.idl
// generated code does not contain a copyright notice

#ifndef AD_WS_INTERFACES__MSG__DETAIL__XSENS__STRUCT_HPP_
#define AD_WS_INTERFACES__MSG__DETAIL__XSENS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ad_ws_interfaces__msg__Xsens __attribute__((deprecated))
#else
# define DEPRECATED__ad_ws_interfaces__msg__Xsens __declspec(deprecated)
#endif

namespace ad_ws_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Xsens_
{
  using Type = Xsens_<ContainerAllocator>;

  explicit Xsens_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->acc_x = 0.0f;
      this->acc_y = 0.0f;
      this->acc_z = 0.0f;
      this->rate_of_turn_x = 0.0f;
    }
  }

  explicit Xsens_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->acc_x = 0.0f;
      this->acc_y = 0.0f;
      this->acc_z = 0.0f;
      this->rate_of_turn_x = 0.0f;
    }
  }

  // field types and members
  using _acc_x_type =
    float;
  _acc_x_type acc_x;
  using _acc_y_type =
    float;
  _acc_y_type acc_y;
  using _acc_z_type =
    float;
  _acc_z_type acc_z;
  using _rate_of_turn_x_type =
    float;
  _rate_of_turn_x_type rate_of_turn_x;

  // setters for named parameter idiom
  Type & set__acc_x(
    const float & _arg)
  {
    this->acc_x = _arg;
    return *this;
  }
  Type & set__acc_y(
    const float & _arg)
  {
    this->acc_y = _arg;
    return *this;
  }
  Type & set__acc_z(
    const float & _arg)
  {
    this->acc_z = _arg;
    return *this;
  }
  Type & set__rate_of_turn_x(
    const float & _arg)
  {
    this->rate_of_turn_x = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ad_ws_interfaces::msg::Xsens_<ContainerAllocator> *;
  using ConstRawPtr =
    const ad_ws_interfaces::msg::Xsens_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ad_ws_interfaces::msg::Xsens_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ad_ws_interfaces::msg::Xsens_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ad_ws_interfaces::msg::Xsens_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ad_ws_interfaces::msg::Xsens_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ad_ws_interfaces::msg::Xsens_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ad_ws_interfaces::msg::Xsens_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ad_ws_interfaces::msg::Xsens_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ad_ws_interfaces::msg::Xsens_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ad_ws_interfaces__msg__Xsens
    std::shared_ptr<ad_ws_interfaces::msg::Xsens_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ad_ws_interfaces__msg__Xsens
    std::shared_ptr<ad_ws_interfaces::msg::Xsens_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Xsens_ & other) const
  {
    if (this->acc_x != other.acc_x) {
      return false;
    }
    if (this->acc_y != other.acc_y) {
      return false;
    }
    if (this->acc_z != other.acc_z) {
      return false;
    }
    if (this->rate_of_turn_x != other.rate_of_turn_x) {
      return false;
    }
    return true;
  }
  bool operator!=(const Xsens_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Xsens_

// alias to use template instance with default allocator
using Xsens =
  ad_ws_interfaces::msg::Xsens_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace ad_ws_interfaces

#endif  // AD_WS_INTERFACES__MSG__DETAIL__XSENS__STRUCT_HPP_
