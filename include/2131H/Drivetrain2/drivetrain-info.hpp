/**
 * @file drivetrain-info.hpp
 * @author Andrew
 * @brief A header file for the DrivetrainInfo class.
 * @version 0.1
 * @date 2025-04-11
 *
 * @copyright Copyright (c) 2025
 *
 */

#pragma once

#include <cstdint>

class DrivetrainInfo {
public:
  // Constants
  const float track_width;      // Lateral distance between wheels
  const float track_width_half; // Half of the track width
  const float track_length;     // Longitudinal distance between wheels
  const float robot_mass;       // Mass of robot in LBS

  const float wheel_diameter;      // Wheel diameter in inches
  const float wheel_circumference; // Wheel circumference in inches
  const float wheel_max_rpm;       // Max RPM of the wheels

  const uint32_t motor_count;   // Total count of motors
  const uint32_t motor_max_rpm; // Max RPM of the motors
  const float motor_max_nm;     // Max torque of the motors in NM

  const float gear_ratio_to_wheel; // Gear ratio from motor to wheel
  const float gear_ratio_to_motor; // Gear ratio from wheel to motor

  const float max_speed; // Max speed of the drivetrain in Inches per Second
  const float
      max_acceleration; // Acceleration of the drivetrain in Inches / S^2

private:
  // Private constructor
  constexpr DrivetrainInfo(float track_width, float track_length,
                           float robot_mass, float wheel_diameter,
                           float wheel_max_rpm, uint32_t motor_count,
                           uint32_t motor_max_rpm, float slew_constant = 1.0f);

  friend constexpr DrivetrainInfo
  setDrivetrainInfo(float track_width, float track_length, float robot_mass,
                    float wheel_diameter, float wheel_max_rpm,
                    uint32_t motor_count, uint32_t motor_max_rpm,
                    float slew_constant);
};

constexpr DrivetrainInfo
setDrivetrainInfo(float track_width, float track_length, float robot_mass,
                  float wheel_diameter, float wheel_max_rpm,
                  uint32_t motor_count, uint32_t motor_max_rpm,
                  float slew_constant = 1.0f);