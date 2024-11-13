// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from ad_ws_interfaces:msg/Xsens.idl
// generated code does not contain a copyright notice

#ifndef AD_WS_INTERFACES__MSG__DETAIL__XSENS__FUNCTIONS_H_
#define AD_WS_INTERFACES__MSG__DETAIL__XSENS__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "ad_ws_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "ad_ws_interfaces/msg/detail/xsens__struct.h"

/// Initialize msg/Xsens message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * ad_ws_interfaces__msg__Xsens
 * )) before or use
 * ad_ws_interfaces__msg__Xsens__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_ad_ws_interfaces
bool
ad_ws_interfaces__msg__Xsens__init(ad_ws_interfaces__msg__Xsens * msg);

/// Finalize msg/Xsens message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ad_ws_interfaces
void
ad_ws_interfaces__msg__Xsens__fini(ad_ws_interfaces__msg__Xsens * msg);

/// Create msg/Xsens message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * ad_ws_interfaces__msg__Xsens__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_ad_ws_interfaces
ad_ws_interfaces__msg__Xsens *
ad_ws_interfaces__msg__Xsens__create();

/// Destroy msg/Xsens message.
/**
 * It calls
 * ad_ws_interfaces__msg__Xsens__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ad_ws_interfaces
void
ad_ws_interfaces__msg__Xsens__destroy(ad_ws_interfaces__msg__Xsens * msg);

/// Check for msg/Xsens message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_ad_ws_interfaces
bool
ad_ws_interfaces__msg__Xsens__are_equal(const ad_ws_interfaces__msg__Xsens * lhs, const ad_ws_interfaces__msg__Xsens * rhs);

/// Copy a msg/Xsens message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_ad_ws_interfaces
bool
ad_ws_interfaces__msg__Xsens__copy(
  const ad_ws_interfaces__msg__Xsens * input,
  ad_ws_interfaces__msg__Xsens * output);

/// Initialize array of msg/Xsens messages.
/**
 * It allocates the memory for the number of elements and calls
 * ad_ws_interfaces__msg__Xsens__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_ad_ws_interfaces
bool
ad_ws_interfaces__msg__Xsens__Sequence__init(ad_ws_interfaces__msg__Xsens__Sequence * array, size_t size);

/// Finalize array of msg/Xsens messages.
/**
 * It calls
 * ad_ws_interfaces__msg__Xsens__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ad_ws_interfaces
void
ad_ws_interfaces__msg__Xsens__Sequence__fini(ad_ws_interfaces__msg__Xsens__Sequence * array);

/// Create array of msg/Xsens messages.
/**
 * It allocates the memory for the array and calls
 * ad_ws_interfaces__msg__Xsens__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_ad_ws_interfaces
ad_ws_interfaces__msg__Xsens__Sequence *
ad_ws_interfaces__msg__Xsens__Sequence__create(size_t size);

/// Destroy array of msg/Xsens messages.
/**
 * It calls
 * ad_ws_interfaces__msg__Xsens__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ad_ws_interfaces
void
ad_ws_interfaces__msg__Xsens__Sequence__destroy(ad_ws_interfaces__msg__Xsens__Sequence * array);

/// Check for msg/Xsens message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_ad_ws_interfaces
bool
ad_ws_interfaces__msg__Xsens__Sequence__are_equal(const ad_ws_interfaces__msg__Xsens__Sequence * lhs, const ad_ws_interfaces__msg__Xsens__Sequence * rhs);

/// Copy an array of msg/Xsens messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_ad_ws_interfaces
bool
ad_ws_interfaces__msg__Xsens__Sequence__copy(
  const ad_ws_interfaces__msg__Xsens__Sequence * input,
  ad_ws_interfaces__msg__Xsens__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // AD_WS_INTERFACES__MSG__DETAIL__XSENS__FUNCTIONS_H_
