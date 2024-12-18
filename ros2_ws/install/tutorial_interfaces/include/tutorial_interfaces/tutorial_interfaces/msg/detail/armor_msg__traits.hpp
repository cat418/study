// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from tutorial_interfaces:msg/ArmorMsg.idl
// generated code does not contain a copyright notice

#ifndef TUTORIAL_INTERFACES__MSG__DETAIL__ARMOR_MSG__TRAITS_HPP_
#define TUTORIAL_INTERFACES__MSG__DETAIL__ARMOR_MSG__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "tutorial_interfaces/msg/detail/armor_msg__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'pixels'
#include "geometry_msgs/msg/detail/point__traits.hpp"
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__traits.hpp"

namespace tutorial_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const ArmorMsg & msg,
  std::ostream & out)
{
  out << "{";
  // member: pixels
  {
    if (msg.pixels.size() == 0) {
      out << "pixels: []";
    } else {
      out << "pixels: [";
      size_t pending_items = msg.pixels.size();
      for (auto item : msg.pixels) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: pose
  {
    out << "pose: ";
    to_flow_style_yaml(msg.pose, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ArmorMsg & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: pixels
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.pixels.size() == 0) {
      out << "pixels: []\n";
    } else {
      out << "pixels:\n";
      for (auto item : msg.pixels) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: pose
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pose:\n";
    to_block_style_yaml(msg.pose, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ArmorMsg & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace tutorial_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use tutorial_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const tutorial_interfaces::msg::ArmorMsg & msg,
  std::ostream & out, size_t indentation = 0)
{
  tutorial_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tutorial_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const tutorial_interfaces::msg::ArmorMsg & msg)
{
  return tutorial_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<tutorial_interfaces::msg::ArmorMsg>()
{
  return "tutorial_interfaces::msg::ArmorMsg";
}

template<>
inline const char * name<tutorial_interfaces::msg::ArmorMsg>()
{
  return "tutorial_interfaces/msg/ArmorMsg";
}

template<>
struct has_fixed_size<tutorial_interfaces::msg::ArmorMsg>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<tutorial_interfaces::msg::ArmorMsg>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<tutorial_interfaces::msg::ArmorMsg>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TUTORIAL_INTERFACES__MSG__DETAIL__ARMOR_MSG__TRAITS_HPP_
