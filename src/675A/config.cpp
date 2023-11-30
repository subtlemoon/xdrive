#include "main.h"
using namespace pros;

Controller master (E_CONTROLLER_MASTER);

Motor left_front_motor(1, E_MOTOR_GEARSET_18, false);
Motor left_back_motor (2, E_MOTOR_GEARSET_18, false);
Motor right_front_motor (3, E_MOTOR_GEARSET_18, false);
Motor right_back_motor (4, E_MOTOR_GEARSET_18, false);

Motor_Group leftMotors({left_front_motor, left_back_motor});
Motor_Group rightMotors({right_front_motor, right_back_motor});

Motor_Group frontMotors({left_front_motor, right_front_motor});
Motor_Group backMotors({left_back_motor, right_back_motor});