// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tutorial_interfaces:msg/ArmorMsg.idl
// generated code does not contain a copyright notice

#ifndef TUTORIAL_INTERFACES__MSG__DETAIL__ARMOR_MSG__BUILDER_HPP_
#define TUTORIAL_INTERFACES__MSG__DETAIL__ARMOR_MSG__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tutorial_interfaces/msg/detail/armor_msg__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tutorial_interfaces
{

namespace msg
{

namespace builder
{

class Init_ArmorMsg_pose
{
public:
  explicit Init_ArmorMsg_pose(::tutorial_interfaces::msg::ArmorMsg & msg)
  : msg_(msg)
  {}
  ::tutorial_interfaces::msg::ArmorMsg pose(::tutorial_interfaces::msg::ArmorMsg::_pose_type arg)
  {
    msg_.pose = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tutorial_interfaces::msg::ArmorMsg msg_;
};

class Init_ArmorMsg_pixels
{
public:
  Init_ArmorMsg_pixels()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ArmorMsg_pose pixels(::tutorial_interfaces::msg::ArmorMsg::_pixels_type arg)
  {
    msg_.pixels = std::move(arg);
    return Init_ArmorMsg_pose(msg_);
  }

private:
  ::tutorial_interfaces::msg::ArmorMsg msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::tutorial_interfaces::msg::ArmorMsg>()
{
  return tutorial_interfaces::msg::builder::Init_ArmorMsg_pixels();
}

}  // namespace tutorial_interfaces

#endif  // TUTORIAL_INTERFACES__MSG__DETAIL__ARMOR_MSG__BUILDER_HPP_
