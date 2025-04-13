/**
 * @file motion-executer.hpp
 * @author Andrew Hilton (2131H)
 * @brief A header file for the motion executer class
 * @version 0.1
 * @date 2025-04-12
 *
 * @copyright Copyright (c) 2025
 *
 */

#pragma once

#include <cmath>

#include "drivetrain.hpp"
#include "motion.hpp"
#include "pros/rtos.hpp"

class AbstractController;  // Forward declaration
class Motion;              // Forward declaration

class MotionExecuter
{
 public:
  static MotionExecuter &get()
  {
    static MotionExecuter instance;
    return instance;
  }

  // Delete copy constructor to prevent copying
  MotionExecuter(const MotionExecuter &) = delete;

  // Delete assignment operator to prevent moving
  MotionExecuter &operator=(const MotionExecuter &) = delete;

  static void addMotion(Motion *motion, bool async = false, bool replace = false)
  {
    MotionExecuter::get().addMotionImpl(motion, async, replace);
  }

 private:
  // Private constructor
  MotionExecuter()
      : motion_task(
            [this] {
              while (true)
              {
                threadImpl();
                pros::delay(10);  // Don't hog CPU
              }
            },
            "Motion Executer")
  {
  }

  // Member Variables
  Motion *current_motion = nullptr;
  pros::Task motion_task;

  // Member Functions
  void addMotionImpl(Motion *motion, bool async = false, bool replace = false)
  {
    // If the motion is to be overwritten, then overwrite it
    if (replace) { current_motion = motion; }
    // Else if we are in motion
    else if (motion != nullptr)
    {
      // Wait for the current motion to finish
      while (current_motion != nullptr)
      {
        pros::delay(10);  // Don't hog CPU
      }

      // Add the new motion
      current_motion = motion;
    }

    // If the motion isn't async
    if (!async)
    {
      // Wait for the motion to finish
      while (motion != nullptr)
      {
        pros::delay(10);  // Don't hog CPU
      }
    }
  }

  void threadImpl()
  {
    if (current_motion != nullptr)
    {
      // Send Commands to Chassis
      Drivetrain::followChassisCommand(current_motion->getControllerCommand());

      // Check if the motion is finished
      if (current_motion->isFinished(
              Drivetrain::getX(), Drivetrain::getY(), Drivetrain::getTheta()))
      {
        // Set Current Motion to nullptr
        current_motion = nullptr;
      }
    }
  }
};