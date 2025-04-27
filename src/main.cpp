#include "main.h"

#include "test/robot-config.hpp"

void initialize(void) {
  Drivetrain::setDrivetrainInfo(drivetrain_info);
  std::cout << "Drivetrain info set" << std::endl;
}

void autonomous(void) {}

void disabled(void) {}

void competition_initialize(void) {}

void opcontrol(void) {}
