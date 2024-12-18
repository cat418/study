// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from tutorial_interfaces:msg/ArmorMsg.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "tutorial_interfaces/msg/detail/armor_msg__rosidl_typesupport_introspection_c.h"
#include "tutorial_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "tutorial_interfaces/msg/detail/armor_msg__functions.h"
#include "tutorial_interfaces/msg/detail/armor_msg__struct.h"


// Include directives for member types
// Member `pixels`
#include "geometry_msgs/msg/point.h"
// Member `pixels`
#include "geometry_msgs/msg/detail/point__rosidl_typesupport_introspection_c.h"
// Member `pose`
#include "geometry_msgs/msg/pose.h"
// Member `pose`
#include "geometry_msgs/msg/detail/pose__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void tutorial_interfaces__msg__ArmorMsg__rosidl_typesupport_introspection_c__ArmorMsg_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  tutorial_interfaces__msg__ArmorMsg__init(message_memory);
}

void tutorial_interfaces__msg__ArmorMsg__rosidl_typesupport_introspection_c__ArmorMsg_fini_function(void * message_memory)
{
  tutorial_interfaces__msg__ArmorMsg__fini(message_memory);
}

size_t tutorial_interfaces__msg__ArmorMsg__rosidl_typesupport_introspection_c__size_function__ArmorMsg__pixels(
  const void * untyped_member)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return member->size;
}

const void * tutorial_interfaces__msg__ArmorMsg__rosidl_typesupport_introspection_c__get_const_function__ArmorMsg__pixels(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void * tutorial_interfaces__msg__ArmorMsg__rosidl_typesupport_introspection_c__get_function__ArmorMsg__pixels(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void tutorial_interfaces__msg__ArmorMsg__rosidl_typesupport_introspection_c__fetch_function__ArmorMsg__pixels(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const geometry_msgs__msg__Point * item =
    ((const geometry_msgs__msg__Point *)
    tutorial_interfaces__msg__ArmorMsg__rosidl_typesupport_introspection_c__get_const_function__ArmorMsg__pixels(untyped_member, index));
  geometry_msgs__msg__Point * value =
    (geometry_msgs__msg__Point *)(untyped_value);
  *value = *item;
}

void tutorial_interfaces__msg__ArmorMsg__rosidl_typesupport_introspection_c__assign_function__ArmorMsg__pixels(
  void * untyped_member, size_t index, const void * untyped_value)
{
  geometry_msgs__msg__Point * item =
    ((geometry_msgs__msg__Point *)
    tutorial_interfaces__msg__ArmorMsg__rosidl_typesupport_introspection_c__get_function__ArmorMsg__pixels(untyped_member, index));
  const geometry_msgs__msg__Point * value =
    (const geometry_msgs__msg__Point *)(untyped_value);
  *item = *value;
}

bool tutorial_interfaces__msg__ArmorMsg__rosidl_typesupport_introspection_c__resize_function__ArmorMsg__pixels(
  void * untyped_member, size_t size)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  geometry_msgs__msg__Point__Sequence__fini(member);
  return geometry_msgs__msg__Point__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember tutorial_interfaces__msg__ArmorMsg__rosidl_typesupport_introspection_c__ArmorMsg_message_member_array[2] = {
  {
    "pixels",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tutorial_interfaces__msg__ArmorMsg, pixels),  // bytes offset in struct
    NULL,  // default value
    tutorial_interfaces__msg__ArmorMsg__rosidl_typesupport_introspection_c__size_function__ArmorMsg__pixels,  // size() function pointer
    tutorial_interfaces__msg__ArmorMsg__rosidl_typesupport_introspection_c__get_const_function__ArmorMsg__pixels,  // get_const(index) function pointer
    tutorial_interfaces__msg__ArmorMsg__rosidl_typesupport_introspection_c__get_function__ArmorMsg__pixels,  // get(index) function pointer
    tutorial_interfaces__msg__ArmorMsg__rosidl_typesupport_introspection_c__fetch_function__ArmorMsg__pixels,  // fetch(index, &value) function pointer
    tutorial_interfaces__msg__ArmorMsg__rosidl_typesupport_introspection_c__assign_function__ArmorMsg__pixels,  // assign(index, value) function pointer
    tutorial_interfaces__msg__ArmorMsg__rosidl_typesupport_introspection_c__resize_function__ArmorMsg__pixels  // resize(index) function pointer
  },
  {
    "pose",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tutorial_interfaces__msg__ArmorMsg, pose),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers tutorial_interfaces__msg__ArmorMsg__rosidl_typesupport_introspection_c__ArmorMsg_message_members = {
  "tutorial_interfaces__msg",  // message namespace
  "ArmorMsg",  // message name
  2,  // number of fields
  sizeof(tutorial_interfaces__msg__ArmorMsg),
  tutorial_interfaces__msg__ArmorMsg__rosidl_typesupport_introspection_c__ArmorMsg_message_member_array,  // message members
  tutorial_interfaces__msg__ArmorMsg__rosidl_typesupport_introspection_c__ArmorMsg_init_function,  // function to initialize message memory (memory has to be allocated)
  tutorial_interfaces__msg__ArmorMsg__rosidl_typesupport_introspection_c__ArmorMsg_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t tutorial_interfaces__msg__ArmorMsg__rosidl_typesupport_introspection_c__ArmorMsg_message_type_support_handle = {
  0,
  &tutorial_interfaces__msg__ArmorMsg__rosidl_typesupport_introspection_c__ArmorMsg_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_tutorial_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tutorial_interfaces, msg, ArmorMsg)() {
  tutorial_interfaces__msg__ArmorMsg__rosidl_typesupport_introspection_c__ArmorMsg_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  tutorial_interfaces__msg__ArmorMsg__rosidl_typesupport_introspection_c__ArmorMsg_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Pose)();
  if (!tutorial_interfaces__msg__ArmorMsg__rosidl_typesupport_introspection_c__ArmorMsg_message_type_support_handle.typesupport_identifier) {
    tutorial_interfaces__msg__ArmorMsg__rosidl_typesupport_introspection_c__ArmorMsg_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &tutorial_interfaces__msg__ArmorMsg__rosidl_typesupport_introspection_c__ArmorMsg_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
