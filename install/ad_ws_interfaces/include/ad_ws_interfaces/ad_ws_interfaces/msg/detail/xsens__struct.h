// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ad_ws_interfaces:msg/Xsens.idl
// generated code does not contain a copyright notice

#ifndef AD_WS_INTERFACES__MSG__DETAIL__XSENS__STRUCT_H_
#define AD_WS_INTERFACES__MSG__DETAIL__XSENS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Xsens in the package ad_ws_interfaces.
typedef struct ad_ws_interfaces__msg__Xsens
{
  uint8_t structure_needs_at_least_one_member;
} ad_ws_interfaces__msg__Xsens;

// Struct for a sequence of ad_ws_interfaces__msg__Xsens.
typedef struct ad_ws_interfaces__msg__Xsens__Sequence
{
  ad_ws_interfaces__msg__Xsens * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ad_ws_interfaces__msg__Xsens__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // AD_WS_INTERFACES__MSG__DETAIL__XSENS__STRUCT_H_
