#include "robot-config.hpp"

#include "2131H/Drivetrain/drivetrain-info.hpp"
#include "2131H/Drivetrain/drivetrain.hpp"

pros::MotorGroup left_motors({1, 2, 3}, pros::MotorGears::blue, pros::MotorUnits::deg);
pros::MotorGroup right_motors({4, 5, 6}, pros::MotorGears::blue, pros::MotorUnits::deg);

Drivetrain& drivetrain = Drivetrain::get();
DrivetrainInfo* drivetrain_info = &DrivetrainInfo::get(
    13.5f,         // Track width in inches
    13.0f,         // Track length in inches
    15.0f,         // Robot mass in pounds
    2.75f,         // Wheel diameter in inches
    450.0f,        // Wheel max RPM
    6,             // Motor count
    600.0f,        // Motor max RPM
    &left_motors,  // Pointer to left motors
    &right_motors  // Pointer to right motors
);
