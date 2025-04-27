#include "test/robot-config.hpp"

#include "2131H/Drivetrain2/drivetrain-info.hpp"
#include "2131H/Drivetrain2/drivetrain.hpp"

pros::MotorGroup left_motors({1, 2, 3}, pros::MotorGears::blue, pros::MotorUnits::deg);
pros::MotorGroup right_motors({4, 5, 6}, pros::MotorGears::blue, pros::MotorUnits::deg);

Drivetrain &drivetrain = Drivetrain::get();
