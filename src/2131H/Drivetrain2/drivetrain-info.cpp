#include "2131H/Drivetrain2/drivetrain-info.hpp"

#include <cmath>
#include <cstdint>

// Constructor
constexpr DrivetrainInfo::DrivetrainInfo(
    float track_width,
    float track_length,
    float robot_mass,
    float wheel_diameter,
    float wheel_max_rpm,
    uint32_t motor_count,
    uint32_t motor_max_rpm,
    float slew_constant)
    : track_width(track_width),
      track_width_half(track_width / 2.0f),
      track_length(track_length),
      robot_mass(robot_mass),
      wheel_diameter(wheel_diameter),
      wheel_circumference(wheel_diameter * M_PI),
      wheel_max_rpm(wheel_max_rpm),
      motor_count(motor_count),
      motor_max_rpm(motor_max_rpm),
      motor_max_nm(0.35 * (600.0 / motor_max_rpm)),
      gear_ratio_to_wheel(wheel_max_rpm / motor_max_rpm),
      gear_ratio_to_motor(motor_max_rpm / wheel_max_rpm),
      max_speed(wheel_circumference * (motor_max_rpm / 60.0) * (wheel_max_rpm / motor_max_rpm)),
      max_acceleration(
          (motor_count * motor_max_nm * gear_ratio_to_motor) /
          ((wheel_diameter / 39.37) * (robot_mass / 2.20462)) * 39.37 * slew_constant)
{
}

constexpr DrivetrainInfo setDrivetrainInfo(
    float track_width,
    float track_length,
    float robot_mass,
    float wheel_diameter,
    float wheel_max_rpm,
    uint32_t motor_count,
    uint32_t motor_max_rpm,
    float slew_constant)
{
  return DrivetrainInfo(
      track_width,
      track_length,
      robot_mass,
      wheel_diameter,
      wheel_max_rpm,
      motor_count,
      motor_max_rpm,
      slew_constant);
}