// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ad_ws_interfaces:msg/Xsens.idl
// generated code does not contain a copyright notice
#include "ad_ws_interfaces/msg/detail/xsens__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
ad_ws_interfaces__msg__Xsens__init(ad_ws_interfaces__msg__Xsens * msg)
{
  if (!msg) {
    return false;
  }
  // structure_needs_at_least_one_member
  return true;
}

void
ad_ws_interfaces__msg__Xsens__fini(ad_ws_interfaces__msg__Xsens * msg)
{
  if (!msg) {
    return;
  }
  // structure_needs_at_least_one_member
}

bool
ad_ws_interfaces__msg__Xsens__are_equal(const ad_ws_interfaces__msg__Xsens * lhs, const ad_ws_interfaces__msg__Xsens * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // structure_needs_at_least_one_member
  if (lhs->structure_needs_at_least_one_member != rhs->structure_needs_at_least_one_member) {
    return false;
  }
  return true;
}

bool
ad_ws_interfaces__msg__Xsens__copy(
  const ad_ws_interfaces__msg__Xsens * input,
  ad_ws_interfaces__msg__Xsens * output)
{
  if (!input || !output) {
    return false;
  }
  // structure_needs_at_least_one_member
  output->structure_needs_at_least_one_member = input->structure_needs_at_least_one_member;
  return true;
}

ad_ws_interfaces__msg__Xsens *
ad_ws_interfaces__msg__Xsens__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ad_ws_interfaces__msg__Xsens * msg = (ad_ws_interfaces__msg__Xsens *)allocator.allocate(sizeof(ad_ws_interfaces__msg__Xsens), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ad_ws_interfaces__msg__Xsens));
  bool success = ad_ws_interfaces__msg__Xsens__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ad_ws_interfaces__msg__Xsens__destroy(ad_ws_interfaces__msg__Xsens * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ad_ws_interfaces__msg__Xsens__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ad_ws_interfaces__msg__Xsens__Sequence__init(ad_ws_interfaces__msg__Xsens__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ad_ws_interfaces__msg__Xsens * data = NULL;

  if (size) {
    data = (ad_ws_interfaces__msg__Xsens *)allocator.zero_allocate(size, sizeof(ad_ws_interfaces__msg__Xsens), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ad_ws_interfaces__msg__Xsens__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ad_ws_interfaces__msg__Xsens__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
ad_ws_interfaces__msg__Xsens__Sequence__fini(ad_ws_interfaces__msg__Xsens__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      ad_ws_interfaces__msg__Xsens__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

ad_ws_interfaces__msg__Xsens__Sequence *
ad_ws_interfaces__msg__Xsens__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ad_ws_interfaces__msg__Xsens__Sequence * array = (ad_ws_interfaces__msg__Xsens__Sequence *)allocator.allocate(sizeof(ad_ws_interfaces__msg__Xsens__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ad_ws_interfaces__msg__Xsens__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ad_ws_interfaces__msg__Xsens__Sequence__destroy(ad_ws_interfaces__msg__Xsens__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ad_ws_interfaces__msg__Xsens__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ad_ws_interfaces__msg__Xsens__Sequence__are_equal(const ad_ws_interfaces__msg__Xsens__Sequence * lhs, const ad_ws_interfaces__msg__Xsens__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ad_ws_interfaces__msg__Xsens__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ad_ws_interfaces__msg__Xsens__Sequence__copy(
  const ad_ws_interfaces__msg__Xsens__Sequence * input,
  ad_ws_interfaces__msg__Xsens__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ad_ws_interfaces__msg__Xsens);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ad_ws_interfaces__msg__Xsens * data =
      (ad_ws_interfaces__msg__Xsens *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ad_ws_interfaces__msg__Xsens__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ad_ws_interfaces__msg__Xsens__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ad_ws_interfaces__msg__Xsens__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
