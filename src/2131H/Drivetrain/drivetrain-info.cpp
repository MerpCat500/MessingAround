#include "2131H/Drivetrain/drivetrain-info.hpp"

#include <cmath>
#include <stdexcept>

// Static method to get the singleton instance
DrivetrainInfo &DrivetrainInfo::get(
    float track_width,
    float track_length,
    float robot_mass,
    float wheel_diameter,
    float wheel_max_rpm,
    uint32_t motor_count,
    uint32_t motor_max_rpm,
    pros::MotorGroup *left_motors_ptr,
    pros::MotorGroup *right_motors_ptr,
    float slew_constant)
{
  if (track_width <= 0 || track_length <= 0 || robot_mass <= 0 || wheel_diameter <= 0 ||
      wheel_max_rpm <= 0 || motor_count == 0 || motor_max_rpm == 0)
  {
    throw std::invalid_argument("Invalid parameters for DrivetrainInfo");
  }

  static DrivetrainInfo instance(
      track_width,
      track_length,
      robot_mass,
      wheel_diameter,
      wheel_max_rpm,
      motor_count,
      motor_max_rpm,
      left_motors_ptr,
      right_motors_ptr,
      slew_constant);
  return instance;
}

// Constructor
constexpr DrivetrainInfo::DrivetrainInfo(
    float track_width,
    float track_length,
    float robot_mass,
    float wheel_diameter,
    float wheel_max_rpm,
    uint32_t motor_count,
    uint32_t motor_max_rpm,
    pros::MotorGroup *left_motors_ptr,
    pros::MotorGroup *right_motors_ptr,
    float slew_constant)
    : track_width(track_width),
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
          ((wheel_diameter / 39.37) * (robot_mass / 2.20462)) * 39.37 * slew_constant),
      left_motors(left_motors_ptr),
      right_motors(right_motors_ptr)
{
}

// Getter methods
float DrivetrainInfo::trackWidth() const { return track_width; }
float DrivetrainInfo::trackLength() const { return track_length; }
float DrivetrainInfo::robotMass() const { return robot_mass; }
float DrivetrainInfo::wheelDiameter() const { return wheel_diameter; }
float DrivetrainInfo::wheelCircumference() const { return wheel_circumference; }
float DrivetrainInfo::wheelMaxRPM() const { return wheel_max_rpm; }
uint32_t DrivetrainInfo::motorCount() const { return motor_count; }
uint32_t DrivetrainInfo::motorMaxRPM() const { return motor_max_rpm; }
uint32_t DrivetrainInfo::motorMaxNM() const { return motor_max_nm; }
float DrivetrainInfo::gearRatioToWheel() const { return gear_ratio_to_wheel; }
float DrivetrainInfo::gearRatioToMotor() const { return gear_ratio_to_motor; }
float DrivetrainInfo::maxSpeed() const { return max_speed; }
float DrivetrainInfo::maxAcceleration() const { return max_acceleration; }