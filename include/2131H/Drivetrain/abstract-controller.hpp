/**
 * @file abstract-controller.hpp
 * @author Andrew Hilton (2131H)
 * @brief A file for the abstract controller class
 * @version 0.1
 * @date 2025-04-12
 *
 * @copyright Copyright (c) 2025
 *
 */

#pragma once

#include "motion.hpp"

class Motion;  // Forward declaration

class AbstractController
{
 public:
  /**
   * @brief Return Chassis Commands, given a motion
   *
   * @param motion Motion info for the controller
   * @return Chassis Command that the drivetrain can follow
   */
  virtual ChassisCommand execute(const Motion &motion) = 0;
};