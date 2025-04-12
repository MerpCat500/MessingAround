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

struct ChassisCommand
{
  float linear_velocity;
  float angular_velocity;
};

class AbstractController
{
 public:
  virtual ChassisCommand execute(const Motion &motion) = 0;
};