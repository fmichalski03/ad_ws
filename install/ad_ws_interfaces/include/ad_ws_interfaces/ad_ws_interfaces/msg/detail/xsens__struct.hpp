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
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit Xsens_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  // field types and members
  using _structure_needs_at_least_one_member_type =
    uint8_t;
  _structure_needs_at_least_one_member_type structure_needs_at_least_one_member;


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
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
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
