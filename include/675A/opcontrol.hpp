//These two are included in every header file
#pragma once
#include "api.h"

//Idk what these do and they not in the file anywhere else
#include <functional>
#include <iostream>
#include <tuple> 

//Motors are included with this
#include "pros/motors.h"

//All the functions defined
void reset_drive_sensors();
double left_curve_function(double x);
double right_curve_function(double x);
void checkThreshold(int x_dir, int y_dir, int rotation);
void drive(int x_dir, int y_dir, int rotation);
void arcade_flipped();