#ifndef ROBOT_H
#define ROBOT_H

typedef struct
{
	double x;
	double y;
}tpos;

typedef unsigned int uint;

class Robot
{
	tpos pos;
	double dir;
public:
	void initRobot(uint h, uint w);
	void moveRobot(uint Hcount, uint Wcount);
	tpos getRobotPos();
};

#endif