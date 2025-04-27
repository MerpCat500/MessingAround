
#pragma once

#include "2131H/Drivetrain2/motion.hpp"
#include "2131H/Drivetrain2/util.hpp"

class AbstractController
{
 public:
  /**
   * @brief Return Chassis Commands, given a motion
   *
   * @param motion Motion info for the controller
   * @return Chassis Command that the drivetrain can follow
   */
  virtual ChassisCommand execute(Motion *motion) = 0;
};