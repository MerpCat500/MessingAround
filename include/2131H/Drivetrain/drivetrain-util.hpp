/**
 * @file drivetrain-util.hpp
 * @author Andrew Hilton (2131H)
 * @brief A header file for the extra drivetrain structures
 * @version 0.1
 * @date 2025-04-12
 *
 * @copyright Copyright (c) 2025
 *
 */

#pragma once

struct ChassisCommand
{
  float linear_velocity;   // Linear velocity in inches per second
  float angular_velocity;  // Angular Velocity in degrees per second
};

struct DifferentialCommand
{
  float left_velocity;   // Left wheel velocity in inches per second
  float right_velocity;  // Right wheel velocity in inches per second
};