#ifndef ROBOT_H
#define ROBOT_H

#include <cstdlib>
#include <time.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include "typedef.h"

class Robot
{
	tpos pos;
	double dir;
public:
	void initRobot(uint h, uint w);
	void moveRobot(uint Hcount, uint Wcount);
	tpos getRobotPos();
	double getAngle();
};

#endif