#include "main.h"

//This function resets the drive sensors do fix something idk i trust jonah
void reset_drive_sensors(){
    leftMotors.tare_position();
    rightMotors.tare_position(); //I changed these to reset all the motors (does this change things?)
}

//Changing the curve functions changes the sens*

// Left curve function
double left_curve_function(double x) {return (powf(2.718, -(3 / 10)) + powf(2.718, (fabs(x) - 127) / 10) * (1 - powf(2.718, -(3 / 10)))) * x;}

// Right curve function
double right_curve_function(double x) {return (powf(2.718, -(3 / 10)) + powf(2.718, (fabs(x) - 127) / 10) * (1 - powf(2.718, -(3 / 10)))) * x;}

//Function to check if the joystick is within the threshold to avoid physical joystick problems
void checkThreshold(int x_dir, int y_dir, int rotation){

    int joystickThreshold = 5;
    
    //If the sticks are above the threshold then the bot is allowed to move
    if (abs(x_dir) > joystickThreshold || abs(y_dir) > joystickThreshold || abs(rotation) > joystickThreshold) {
        drive(x_dir, y_dir, rotation);
        reset_drive_sensors();
    }

    else{ //This is where things might go wrong bc idk what im doing here
        leftMotors.moveVoltage(0);
        rightMotors.moveVoltage(0);
        leftMotors.set_brake_modes(E_MOTOR_BRAKE_HOLD);
        rightMotors.set_brake_modes(E_MOTOR_BRAKE_HOLD);
    }
}

//This is where the bot actually moves after everything 
void drive(int x_dir, int y_dir, int rotation){
    left_front_motor.move_voltage((y_dir + x_dir + rotation) * (12000.0 / 127.0));  
    left_back_motor.move_voltage((y_dir - x_dir + rotation) * (12000.0 / 127.0)); 
    right_front_motor.move_voltage(-y_dir + x_dir + rotation *(12000.00 / 127.0));
    right_back_motor.move_voltage(-y_dir - x_dir + rotation *(12000.00 / 127.0));
}

//Main function where everything comes together
void arcade_flipped(){

    while(true){

        int y_dir, x_dir, rotation;

        y_dir = right_curve_function(master.get_analog(ANALOG_RIGHT_Y));
        x_dir = right_curve_function(master.get_analog(ANALOG_RIGHT_X));
        rotation = left_curve_function(master.get_analog(ANALOG_LEFT_X));

        checkThreshold(x_dir, y_dir, rotation);

    }

}