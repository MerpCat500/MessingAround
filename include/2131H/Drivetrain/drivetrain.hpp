/**
 * @file drivetrain.hpp
 * @author Andrew Hilton (2131H)
 * @brief A header file for the Drivetrain class
 * @version 0.1
 * @date 2025-04-12
 *
 * @copyright Copyright (c) 2025
 *
 */

#pragma once

#include <cmath>

#include "drivetrain-info.hpp"
#include "drivetrain-util.hpp"
#include "motion.hpp"

class AbstractController;  // Forward declaration

class Drivetrain
{
 public:
  // Get an instance of the Drivetrain class. Will create a new instance if one doesn't exist.
  static Drivetrain& get()
  {
    static Drivetrain instance;
    return instance;
  }

  // Delete copy constructor to prevent copying
  Drivetrain(const Drivetrain&) = delete;
  // Delete assignment operator to prevent moving
  Drivetrain& operator=(const Drivetrain&) = delete;

  // Public methods
  static void followChassisCommand(const ChassisCommand& command)
  {
    Drivetrain::get().followChassisCommandImpl(command);
  }

  static Motion createMotion(
      uint32_t timeout,
      float position_tolerance,
      float angle_tolerance,
      AbstractController* controller)
  {
    return Motion(timeout, position_tolerance, angle_tolerance, controller);
  }

  // Setters
  static void setDrivetrainInfo(DrivetrainInfo* drivetrain_info)
  {
    Drivetrain::get().drivetrain_info = drivetrain_info;
  }

  // Getters
  static float getX() { return Drivetrain::get().getXImpl(); }
  static float getY() { return Drivetrain::get().getYImpl(); }
  static float getTheta() { return Drivetrain::get().getThetaImpl(); }

 private:
  // Private constructor
  Drivetrain() : x(0.0f), y(0.0f), theta(0.0f), drivetrain_info(nullptr) {};

  // Private member functions
  void followChassisCommandImpl(const ChassisCommand& command)
  {
    if (!drivetrain_info) { throw std::runtime_error("DrivetrainInfo is not set."); }

    float angular_tangential_velocity =
        command.angular_velocity * drivetrain_info->trackWidth() / 2.0f;

    DifferentialCommand wheel_velocities = {
        command.linear_velocity - angular_tangential_velocity,
        command.linear_velocity + angular_tangential_velocity};

    std::cout << "Left Wheel Velocity: " << wheel_velocities.left_velocity
              << "Right Wheel Velocity: " << wheel_velocities.right_velocity << std::endl;
  }

  // Private member variables
  float x, y, theta;                // Current position and orientation of the robot
  DrivetrainInfo* drivetrain_info;  // Pointer to the DrivetrainInfo instance

  // Getter method Implementations
  float getXImpl() const { return x; }
  float getYImpl() const { return y; }
  float getThetaImpl() const { return theta; }
};
