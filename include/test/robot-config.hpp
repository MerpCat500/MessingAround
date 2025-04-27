/**
 * @file robot-config.hpp
 * @author Andrew Hilton (2131H)
 * @brief A header file that contains the configuration for the robot
 * @version 0.1
 * @date 2025-04-12
 *
 * @copyright Copyright (c) 2025
 *
 */

#pragma once

#include "2131H/Drivetrain2/drivetrain-info.hpp"
#include "2131H/Drivetrain2/drivetrain.hpp"

extern Drivetrain& drivetrain;
constexpr DrivetrainInfo drivetrain_info = setDrivetrainInfo(
    13.5f,   // Track width in inches
    13.0f,   // Track length in inches
    15.0f,   // Robot mass in pounds
    2.75f,   // Wheel diameter in inches
    450.0f,  // Wheel max RPM
    6,       // Motor count
    600.0f   // Motor max RPM
);
