// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from armor_interfaces:msg/Armor.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "armor_interfaces/msg/detail/armor__rosidl_typesupport_introspection_c.h"
#include "armor_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "armor_interfaces/msg/detail/armor__functions.h"
#include "armor_interfaces/msg/detail/armor__struct.h"


// Include directives for member types
// Member `type`
// Member `color`
#include "rosidl_runtime_c/string_functions.h"
// Member `apexs`
#include "geometry_msgs/msg/point32.h"
// Member `apexs`
#include "geometry_msgs/msg/detail/point32__rosidl_typesupport_introspection_c.h"
// Member `pose`
// Member `world_pose`
#include "geometry_msgs/msg/pose.h"
// Member `pose`
// Member `world_pose`
#include "geometry_msgs/msg/detail/pose__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void armor_interfaces__msg__Armor__rosidl_typesupport_introspection_c__Armor_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  armor_interfaces__msg__Armor__init(message_memory);
}

void armor_interfaces__msg__Armor__rosidl_typesupport_introspection_c__Armor_fini_function(void * message_memory)
{
  armor_interfaces__msg__Armor__fini(message_memory);
}

size_t armor_interfaces__msg__Armor__rosidl_typesupport_introspection_c__size_function__Armor__apexs(
  const void * untyped_member)
{
  (void)untyped_member;
  return 4;
}

const void * armor_interfaces__msg__Armor__rosidl_typesupport_introspection_c__get_const_function__Armor__apexs(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__Point32 * member =
    (const geometry_msgs__msg__Point32 *)(untyped_member);
  return &member[index];
}

void * armor_interfaces__msg__Armor__rosidl_typesupport_introspection_c__get_function__Armor__apexs(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__Point32 * member =
    (geometry_msgs__msg__Point32 *)(untyped_member);
  return &member[index];
}

void armor_interfaces__msg__Armor__rosidl_typesupport_introspection_c__fetch_function__Armor__apexs(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const geometry_msgs__msg__Point32 * item =
    ((const geometry_msgs__msg__Point32 *)
    armor_interfaces__msg__Armor__rosidl_typesupport_introspection_c__get_const_function__Armor__apexs(untyped_member, index));
  geometry_msgs__msg__Point32 * value =
    (geometry_msgs__msg__Point32 *)(untyped_value);
  *value = *item;
}

void armor_interfaces__msg__Armor__rosidl_typesupport_introspection_c__assign_function__Armor__apexs(
  void * untyped_member, size_t index, const void * untyped_value)
{
  geometry_msgs__msg__Point32 * item =
    ((geometry_msgs__msg__Point32 *)
    armor_interfaces__msg__Armor__rosidl_typesupport_introspection_c__get_function__Armor__apexs(untyped_member, index));
  const geometry_msgs__msg__Point32 * value =
    (const geometry_msgs__msg__Point32 *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember armor_interfaces__msg__Armor__rosidl_typesupport_introspection_c__Armor_message_member_array[7] = {
  {
    "number",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(armor_interfaces__msg__Armor, number),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "type",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(armor_interfaces__msg__Armor, type),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "color",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(armor_interfaces__msg__Armor, color),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "distance_to_center",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(armor_interfaces__msg__Armor, distance_to_center),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "apexs",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(armor_interfaces__msg__Armor, apexs),  // bytes offset in struct
    NULL,  // default value
    armor_interfaces__msg__Armor__rosidl_typesupport_introspection_c__size_function__Armor__apexs,  // size() function pointer
    armor_interfaces__msg__Armor__rosidl_typesupport_introspection_c__get_const_function__Armor__apexs,  // get_const(index) function pointer
    armor_interfaces__msg__Armor__rosidl_typesupport_introspection_c__get_function__Armor__apexs,  // get(index) function pointer
    armor_interfaces__msg__Armor__rosidl_typesupport_introspection_c__fetch_function__Armor__apexs,  // fetch(index, &value) function pointer
    armor_interfaces__msg__Armor__rosidl_typesupport_introspection_c__assign_function__Armor__apexs,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "pose",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(armor_interfaces__msg__Armor, pose),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "world_pose",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(armor_interfaces__msg__Armor, world_pose),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers armor_interfaces__msg__Armor__rosidl_typesupport_introspection_c__Armor_message_members = {
  "armor_interfaces__msg",  // message namespace
  "Armor",  // message name
  7,  // number of fields
  sizeof(armor_interfaces__msg__Armor),
  armor_interfaces__msg__Armor__rosidl_typesupport_introspection_c__Armor_message_member_array,  // message members
  armor_interfaces__msg__Armor__rosidl_typesupport_introspection_c__Armor_init_function,  // function to initialize message memory (memory has to be allocated)
  armor_interfaces__msg__Armor__rosidl_typesupport_introspection_c__Armor_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t armor_interfaces__msg__Armor__rosidl_typesupport_introspection_c__Armor_message_type_support_handle = {
  0,
  &armor_interfaces__msg__Armor__rosidl_typesupport_introspection_c__Armor_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_armor_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, armor_interfaces, msg, Armor)() {
  armor_interfaces__msg__Armor__rosidl_typesupport_introspection_c__Armor_message_member_array[4].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point32)();
  armor_interfaces__msg__Armor__rosidl_typesupport_introspection_c__Armor_message_member_array[5].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Pose)();
  armor_interfaces__msg__Armor__rosidl_typesupport_introspection_c__Armor_message_member_array[6].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Pose)();
  if (!armor_interfaces__msg__Armor__rosidl_typesupport_introspection_c__Armor_message_type_support_handle.typesupport_identifier) {
    armor_interfaces__msg__Armor__rosidl_typesupport_introspection_c__Armor_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &armor_interfaces__msg__Armor__rosidl_typesupport_introspection_c__Armor_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
