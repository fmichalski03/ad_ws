// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from ad_ws_interfaces:msg/Xsens.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "ad_ws_interfaces/msg/detail/xsens__rosidl_typesupport_introspection_c.h"
#include "ad_ws_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "ad_ws_interfaces/msg/detail/xsens__functions.h"
#include "ad_ws_interfaces/msg/detail/xsens__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void ad_ws_interfaces__msg__Xsens__rosidl_typesupport_introspection_c__Xsens_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  ad_ws_interfaces__msg__Xsens__init(message_memory);
}

void ad_ws_interfaces__msg__Xsens__rosidl_typesupport_introspection_c__Xsens_fini_function(void * message_memory)
{
  ad_ws_interfaces__msg__Xsens__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember ad_ws_interfaces__msg__Xsens__rosidl_typesupport_introspection_c__Xsens_message_member_array[4] = {
  {
    "acc_x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ad_ws_interfaces__msg__Xsens, acc_x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "acc_y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ad_ws_interfaces__msg__Xsens, acc_y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "acc_z",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ad_ws_interfaces__msg__Xsens, acc_z),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "rate_of_turn_x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ad_ws_interfaces__msg__Xsens, rate_of_turn_x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ad_ws_interfaces__msg__Xsens__rosidl_typesupport_introspection_c__Xsens_message_members = {
  "ad_ws_interfaces__msg",  // message namespace
  "Xsens",  // message name
  4,  // number of fields
  sizeof(ad_ws_interfaces__msg__Xsens),
  ad_ws_interfaces__msg__Xsens__rosidl_typesupport_introspection_c__Xsens_message_member_array,  // message members
  ad_ws_interfaces__msg__Xsens__rosidl_typesupport_introspection_c__Xsens_init_function,  // function to initialize message memory (memory has to be allocated)
  ad_ws_interfaces__msg__Xsens__rosidl_typesupport_introspection_c__Xsens_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ad_ws_interfaces__msg__Xsens__rosidl_typesupport_introspection_c__Xsens_message_type_support_handle = {
  0,
  &ad_ws_interfaces__msg__Xsens__rosidl_typesupport_introspection_c__Xsens_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_ad_ws_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ad_ws_interfaces, msg, Xsens)() {
  if (!ad_ws_interfaces__msg__Xsens__rosidl_typesupport_introspection_c__Xsens_message_type_support_handle.typesupport_identifier) {
    ad_ws_interfaces__msg__Xsens__rosidl_typesupport_introspection_c__Xsens_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ad_ws_interfaces__msg__Xsens__rosidl_typesupport_introspection_c__Xsens_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
