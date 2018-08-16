#include "Simulation.h"
#include <allegro5/allegro.h>

#define REST .03

Simulation::Simulation(uint nRobots, string modo, uint w, uint h) :p(h, w), d(h,w,nRobots)
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
	while (!p.isFloorClean())
	{
		if (mode == "Mode 1")	//si esta en el modo 1, dibuja la situacion
		{
			al_rest(REST);
			for (int i = 0; i < robotCount; i++)
			{
				d.draw(robots[i].getRobotPos());
			}
		}
		step();
		d.draw(mode,)
	}

	return tickCount;
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
