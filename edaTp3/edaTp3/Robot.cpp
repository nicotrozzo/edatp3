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
	dir = (rand() % 360) * 2 * M_PI / 360;	//inicializa un angulo random en radianes
}

void Robot::moveRobot(uint Hcount, uint Wcount)
{
	tpos newPos = { pos.x + cos(dir) , pos.y + sin(dir) };
	bool valid = ((newPos.x > 0) && (newPos.x < Wcount)) && ((newPos.y>0) && (newPos.y<Hcount));
	if (valid)
	{
		pos = newPos;	//si no choca en la siguiente direccion, avanza
	}
	else
	{
		dir = (rand() % 360) * 2 * M_PI / 360;	//si iba a chocar, cambia la direccion
	}
}

tpos Robot::getRobotPos()
{
	return pos;
}

