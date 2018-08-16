#include "Simulation.h"

Simulation::Simulation(uint nRobots, string modo, uint w, uint h) :p(h, w), d()
{
	robots = new Robot[nRobots];
	robotCount = nRobots;
	mode = modo;
	for (int i = 0; i < nRobots; i++)
	{
		robots[i].initRobots(h, w);
	}
	tickCount = 0;
	err.errNum = NO_ERROR;
}

string Simulation::getMode()
{
	return mode;
}

uint Simulation::getTickCount()
{
	return tickCount;
}

errorType Simulation::getError()
{
	return err;
}

uint Simulation::simulate()
{
	
}

void Simulation::step()
{
	for (int i = 0; i < robotCount; i++)
	{
		robots[i].moveRobot(p.getHeight(), p.getWidth());
		p.cleanTile(robots[i].getRobotPos());
	}
	tickCount++;
}

void Simulation::destroy()
{
	delete robots[];
}
