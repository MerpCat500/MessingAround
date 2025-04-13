/**
 * @file motion.hpp
 * @author Andrew Hilton (2131H)
 * @brief A header file for motion class
 * @version 0.1
 * @date 2025-04-12
 *
 * @copyright Copyright (c) 2025
 *
 */

#pragma once

#include <cstdint>
#include <optional>

#ifndef DRIVETRAIN_UTIL_INCLUDED
#include "drivetrain-util.hpp"
#define DRIVETRAIN_UTIL_INCLUDED
#endif

#include "abstract-controller.hpp"
#include "motion-executer.hpp"

class AbstractController;  // Forward declaration
class Motion;              // Forward declaration

enum class TURN_DIRECTION
{
  CCW,
  CW,
  AUTO
};

struct Motion
{
  Motion(
      uint32_t timeout,
      float position_tolerance,
      float angle_tolerance,
      AbstractController *controller)
      : timeout(timeout),
        position_tolerance(position_tolerance),
        angle_tolerance(angle_tolerance),
        controller(controller)
  {
  }

  Motion &setTargetPose(float x, float y, float theta)
  {
    target_x = x;
    target_y = y;
    target_theta = theta;
    return *this;
  }

  Motion &setTargetPoint(float x, float y)
  {
    target_x = x;
    target_y = y;
    return *this;
  }

  Motion &setTargetAngle(float theta)
  {
    target_theta = theta;
    return *this;
  }

  Motion &setPreferredTurnDirection(TURN_DIRECTION turn_direction)
  {
    preferred_turn_direction = turn_direction;
    return *this;
  }

  Motion &setSpeeds(float max, float min)
  {
    max_speed = max;
    min_speed = min;
    return *this;
  }

  Motion &setTimeout(uint32_t timeout)
  {
    this->timeout = timeout;
    return *this;
  }

  // Getters
  std::optional<float> getX() const { return target_x; }
  std::optional<float> getY() const { return target_y; }
  std::optional<float> getTheta() const { return target_theta; }
  float getMaxSpeed() const { return max_speed; }
  float getMinSpeed() const { return min_speed; }
  uint32_t getTimeout() const { return timeout; }
  float getPositionTolerance() const { return position_tolerance; }
  float getAngleTolerance() const { return angle_tolerance; }
  TURN_DIRECTION getPreferredTurnDirection() const { return preferred_turn_direction; }

  ChassisCommand getControllerCommand() { return controller->execute(*this); }
  void execute() { MotionExecuter::get().addMotion(this); }
  bool isFinished(float x, float y, float theta)
  {
    if (target_x.has_value() && target_y.has_value() && target_theta.has_value())
    {
      return (
          std::hypot(target_x.value() - x, target_y.value() - y) < position_tolerance &&
          std::abs(target_theta.value() - theta) < angle_tolerance);
    }
    else if (target_x.has_value() && target_y.has_value())
    {
      return (std::hypot(target_x.value() - x, target_y.value() - y) < position_tolerance);
    }
    else if (target_theta.has_value())
    {
      return (std::abs(target_theta.value() - theta) < angle_tolerance);
    }

    throw std::runtime_error("Motion has no target set");
    return false;
  }

 private:
  std::optional<float> target_x = std::nullopt;
  std::optional<float> target_y = std::nullopt;
  std::optional<float> target_theta = std::nullopt;

  float max_speed = 127.0f;
  float min_speed = 0.0f;

  uint32_t timeout;
  float position_tolerance;
  float angle_tolerance;

  TURN_DIRECTION preferred_turn_direction = TURN_DIRECTION::AUTO;

  AbstractController *controller;
};
