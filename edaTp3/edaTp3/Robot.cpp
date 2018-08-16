#include "Robot.h"
#include <cstdlib>
#include <time.h>
#define _USE_MATH_DEFINES
#include <math.h>

void Robot::initRobot(uint h, uint w)
{
	srand(time(NULL));
	pos.y = (rand() % (1000 * h) ) / 1000.0;	//incializa en un lugar random con 3 decimales en cada coordenada
	pos.x = (rand() % 1000 * w) / 1000.0;
	dir = (rand() % floor(100 * 2 * M_PI)) / 100.0;	//inicializa un angulo random
}

void Robot::moveRobot(uint Hcount, uint Wcount)
{
	tpos newPos = { pos.x + cos(dir) , pos.y + sin(dir) };
	bool valid = ((newPos.x > 0) && (newPos.x < Wcount)) && ((newPos.y>0) && (newPos.y<Hcount));
	if (valid)
		pos = newPos;
}

tpos getRobotPos()
{
	return pos;
}

