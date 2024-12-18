// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tutorial_interfaces:msg/ArmorMsg.idl
// generated code does not contain a copyright notice

#ifndef TUTORIAL_INTERFACES__MSG__DETAIL__ARMOR_MSG__STRUCT_H_
#define TUTORIAL_INTERFACES__MSG__DETAIL__ARMOR_MSG__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'pixels'
#include "geometry_msgs/msg/detail/point__struct.h"
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__struct.h"

/// Struct defined in msg/ArmorMsg in the package tutorial_interfaces.
/**
  * tutorial_interfaces/msg/ArmorMsg.msg
 */
typedef struct tutorial_interfaces__msg__ArmorMsg
{
  geometry_msgs__msg__Point__Sequence pixels;
  geometry_msgs__msg__Pose pose;
} tutorial_interfaces__msg__ArmorMsg;

// Struct for a sequence of tutorial_interfaces__msg__ArmorMsg.
typedef struct tutorial_interfaces__msg__ArmorMsg__Sequence
{
  tutorial_interfaces__msg__ArmorMsg * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tutorial_interfaces__msg__ArmorMsg__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TUTORIAL_INTERFACES__MSG__DETAIL__ARMOR_MSG__STRUCT_H_
