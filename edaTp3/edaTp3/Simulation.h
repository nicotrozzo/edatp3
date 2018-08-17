#ifndef SIMULATION_H
#define SIMULATION_H

#include <iostream>
#include "Piso.h"
#include "Robot.h"
#include "Dibujator.h"

typedef unsigned int uint;

using namespace std;

class Simulation
{
	uint tickCount;
	string mode;
	uint robotCount;
	Robot *robots;
	Piso p;
	Dibujator d;
	errorType err;
	void step();
public:
	Simulation(uint nRobotos, string modo, uint w, uint h);
	string getMode();
	uint simulate();
	uint getTickCount();
	errorType getError();
	void destroy();
};

#endif

