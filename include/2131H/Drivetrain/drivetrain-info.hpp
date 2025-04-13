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

#include "pros/motor_group.hpp"

class DrivetrainInfo
{
 public:
  /**
   * @brief Get an instance of the DrivetrainInfo class. Will create a new
   * instance if one doesn't exist.
   *
   * @param track_width Lateral distance between wheels
   * @param track_length Longitudinal distance between wheels
   * @param robot_mass Mass of robot in LBS
   * @param wheel_diameter Wheel diameter in inches
   * @param wheel_max_rpm Max RPM of the wheels
   * @param motor_count Total count of motors
   * @param motor_max_rpm Max RPM of the motors
   * @return DrivetrainInfo&
   */
  static DrivetrainInfo &get(
      float track_width,
      float track_length,
      float robot_mass,
      float wheel_diameter,
      float wheel_max_rpm,
      uint32_t motor_count,
      uint32_t motor_max_rpm,
      pros::MotorGroup *left_motors_ptr,
      pros::MotorGroup *right_motors_ptr,
      float slew_constant = 1.0f);

  // Delete copy constructor to prevent copying
  DrivetrainInfo(const DrivetrainInfo &) = delete;

  // Delete assignment operator to prevent moving
  DrivetrainInfo &operator=(const DrivetrainInfo &) = delete;

  // Getter methods

  /**
   * @brief Get the track width of the drivetrain.
   * @return Track width in inches.
   */
  float trackWidth() const;

  /**
   * @brief Get the track length of the drivetrain.
   * @return Track length in inches.
   */
  float trackLength() const;

  /**
   * @brief Get the mass of the robot.
   * @return Robot mass in pounds (LBS).
   */
  float robotMass() const;

  /**
   * @brief Get the wheel diameter.
   * @return Wheel diameter in inches.
   */
  float wheelDiameter() const;

  /**
   * @brief Get the wheel circumference.
   * @return Wheel circumference in inches.
   */
  float wheelCircumference() const;

  /**
   * @brief Get the maximum RPM of the wheels.
   * @return Maximum wheel RPM.
   */
  float wheelMaxRPM() const;

  /**
   * @brief Get the total number of motors.
   * @return Motor count.
   */
  uint32_t motorCount() const;

  /**
   * @brief Get the maximum RPM of the motors.
   * @return Maximum motor RPM.
   */
  uint32_t motorMaxRPM() const;

  /**
   * @brief Get the maximum torque of the motors.
   * @return Maximum motor torque in Newton-meters (NM).
   */
  uint32_t motorMaxNM() const;

  /**
   * @brief Get the gear ratio from the motor to the wheel.
   * @return Gear ratio to the wheel.
   */
  float gearRatioToWheel() const;

  /**
   * @brief Get the gear ratio from the wheel to the motor.
   * @return Gear ratio to the motor.
   */
  float gearRatioToMotor() const;

  /**
   * @brief Get the maximum speed of the drivetrain.
   * @return Maximum speed in inches per second.
   */
  float maxSpeed() const;

  /**
   * @brief Get the maximum acceleration of the drivetrain.
   * @return Maximum acceleration in inches per second squared.
   */
  float maxAcceleration() const;

  pros::MotorGroup *leftMotors() const;
  pros::MotorGroup *rightMotors() const;

 private:
  // Private constructor
  constexpr DrivetrainInfo(
      float track_width,
      float track_length,
      float robot_mass,
      float wheel_diameter,
      float wheel_max_rpm,
      uint32_t motor_count,
      uint32_t motor_max_rpm,
      pros::MotorGroup *left_motors_ptr,
      pros::MotorGroup *right_motors_ptr,
      float slew_constant = 1.0f);

  // Member variables
  const float track_width;       // Lateral distance between wheels
  const float track_width_half;  // Half of the track width
  const float track_length;      // Longitudinal distance between wheels
  const float robot_mass;        // Mass of robot in LBS

  const float wheel_diameter;       // Wheel diameter in inches
  const float wheel_circumference;  // Wheel circumference in inches
  const float wheel_max_rpm;        // Max RPM of the wheels

  const uint32_t motor_count;    // Total count of motors
  const uint32_t motor_max_rpm;  // Max RPM of the motors
  const uint32_t motor_max_nm;   // Max torque of the motors in NM

  const float gear_ratio_to_wheel;  // Gear ratio from motor to wheel
  const float gear_ratio_to_motor;  // Gear ratio from wheel to motor

  const float max_speed;         // Max speed of the drivetrain in Inches per Second
  const float max_acceleration;  // Acceleration of the drivetrain in Inches / S^2

  pros::MotorGroup *left_motors;   // Left motor group
  pros::MotorGroup *right_motors;  // Right motor group

  pros::MotorGroup *all_motors;  // All motors combined
};
