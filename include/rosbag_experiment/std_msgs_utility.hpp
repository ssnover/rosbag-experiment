/*
 * file: std_msgs_utility.hpp
 * purpose: Utility functions for constructing std_msgs types.
 */

#pragma once

#include <std_msgs/Float64.h>

inline std_msgs::Float64 toFloat64(double data) noexcept
{
  std_msgs::Float64 m;
  m.data = data;
  return m;
}