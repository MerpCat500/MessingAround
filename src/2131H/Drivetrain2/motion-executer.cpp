

#include "2131H/Drivetrain2/motion-executer.hpp"

#include "2131H/Drivetrain2/abstract-controller.hpp"
#include "2131H/Drivetrain2/drivetrain-info.hpp"
#include "2131H/Drivetrain2/motion.hpp"
#include "pros/rtos.hpp"

namespace MotionExecuter
{

// Member Variables
Motion *current_motion = nullptr;
AbstractController *current_controller = nullptr;

pros::Task motion_task = pros::Task(
    [] {
      while (true)
      {
        threadImpl();
        pros::delay(10);  // Don't hog CPU
      }
    },
    "Motion Executer");

// Member Functions
void addMotionImpl(
    Motion *motion, DrivetrainInfo *info, AbstractController *controller, bool async, bool replace)
{
  // If the motion is to be overwritten, then overwrite it
  if (replace)
  {
    current_motion = motion;
    current_controller = controller;
  }
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
    current_controller = controller;
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
    current_controller->execute(current_motion);
    // TODO Send Output to Drivetrain

    // TODO Check if motion can exit / finish
    // Check if the motion is finished
    // if (current_motion->isFinished(Drivetrain::getX(), Drivetrain::getY(),
    // Drivetrain::getTheta()))
    // {
    //   // Set Current Motion to nullptr
    //   current_motion = nullptr;
    // }
  }
}
}  // namespace MotionExecuter