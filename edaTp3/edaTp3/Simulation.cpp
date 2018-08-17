#include "Simulation.h"

#define REST .03

Simulation::Simulation(uint nRobots, string mod, uint w, uint h) :p(h, w), d(h,w,nRobots)
{
	robots = new Robot[nRobots];
	robotCount = nRobots;
	mode = mod;
	for (int i = 0; i < nRobots; i++)
	{
		robots[i].initRobot(h, w);
	}
	tickCount = 0;
	err.errNum = NO_ERROR;
	if (mode == "Mode 1")	//dibuja el estado inicial
	{
		for (int i = 0; i < p.getWidth(); i++)
		{
			for (int j = 0; j < p.getHeight(); j++)
			{
				d.drawTile(i, j, p.isDirty(i, j));
			}
		}
		for (int i = 0; i < robotCount; i++)
		{
			d.drawRobot(robots[i].getRobotPos(),robots[i].getAngle());	//si pinta mandamos angulo para rotar
		}
		al_flip_display();
		al_rest(REST);
	}
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
		step();
		if (mode == "Mode 1")	//si esta en el modo 1, dibuja la situacion
		{
			for (int i = 0 ; i < p.getWidth(); i++)	//dibuja todas las baldosas
			{
				for (int j = 0; j < p.getHeight(); j++)
				{
					d.drawTile(i,j,p.isDirty(i,j));
				}
			}
			for (int i = 0; i < robotCount; i++)	//dibuja todos los robots
			{
				d.drawRobot(robots[i].getRobotPos());	//si pinta mandamos angulo para rotar
			}
			al_flip_display();
			al_rest(REST);
		}
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
