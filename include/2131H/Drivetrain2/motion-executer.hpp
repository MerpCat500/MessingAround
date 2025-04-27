

#include "2131H/Drivetrain2/motion.hpp"

namespace MotionExecuter
{
void addMotionImpl(Motion *motion, bool async = false, bool replace = false);
void threadImpl();
Motion createMotion();
}  // namespace MotionExecuter