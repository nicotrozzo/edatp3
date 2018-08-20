#include <string>
#include "Simulation.h"

#define REST .3

Simulation::Simulation(uint nRobots, uint mod, uint w, uint h) : p(h, w), d(h, w, nRobots, mod)   //cambie string mod por uint mod
{
	robots = new Robot[nRobots];
	robotCount = nRobots;
	mode = mod;
	for (uint i = 0; i < nRobots; i++)
	{
		robots[i].initRobot(h, w);
	}
	tickCount = 0;
	err.errNum = NO_ERROR;
	if (((d.getError()).errNum == NO_ERROR) && ((p.getError()).errNum == NO_ERROR))
	{
		if (mode == 1)	//dibuja el estado inicial
		{
			al_clear_to_color(al_map_rgb(0, 0, 0)); //display arranca en negro
			for (uint i = 0; i < p.getWidth(); i++)
			{
				for (uint j = 0; j < p.getHeight(); j++)
				{
					d.drawTile(i, j, p.isDirty(i, j));
					al_flip_display();
				}
			}
			for (uint i = 0; i < robotCount; i++)
			{
				d.drawRobot(robots[i].getRobotPos(), robots[i].getAngle());	//si pinta mandamos angulo para rotar
			}
			al_flip_display();
			al_rest(REST);
		}
	}
	else
	{
		if ((d.getError()).errNum != NO_ERROR)
		{
			cout << ((d.getError()).detail);
		}
		else
		{
			cout << ((p.getError()).detail);
		}
		cout << "Simulacion terminada por error\n";
		d.destroy();
		p.destroy();
		destroy();
	}
}

uint Simulation::getMode()
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
		if (mode == 1)	//si esta en el modo 1, dibuja la situacion
		{
			for (uint i = 0 ; i < p.getWidth(); i++)	//dibuja todas las baldosas
			{
				for (uint j = 0; j < p.getHeight(); j++)
				{
					d.drawTile(i,j,p.isDirty(i,j));
				}
			}
			for (uint i = 0; i < robotCount; i++)	//dibuja todos los robots
			{
				d.drawRobot(robots[i].getRobotPos(),robots[i].getAngle());	//si pinta mandamos angulo para rotar
			}
			al_flip_display();
			al_rest(REST);
		}
	}
	return tickCount;
}

void Simulation::step()
{
	for (uint i = 0; i < robotCount; i++)
	{
		robots[i].moveRobot(p.getHeight(), p.getWidth());
		p.cleanTile(robots[i].getRobotPos());
	}
	tickCount++;
}

void Simulation::destroy()
{
	delete[] robots;
}
