#ifndef SIMULATION_H
#define SIMULATION_H

#include <iostream>
#include <allegro5/allegro.h>
#include "typedef.h"
#include "Piso.h"
#include "Robot.h"
#include "Dibujator.h"

class Simulation
{
	uint tickCount;
	uint mode;
	uint robotCount;
	Robot *robots;
	Piso p;
	Dibujator d;
	errorType err;
	void step();
public:
	Simulation(uint nRobotos, uint mod, uint w, uint h);
	uint getMode();
	uint simulate();
	uint getTickCount();
	errorType getError();
	void destroy();
};

#endif