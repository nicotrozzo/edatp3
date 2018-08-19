#include "Simulation.h"
#include "Header.h"


int main(int argc, char *argv[])
{
	userData user_data;
	//parsea
	if ((parseCmdLine(argc, argv, parseCallback, &user_data) > 0))
	{
		if (user_data.mode == 1)
		{
			Simulation sim(user_data.amountOfRobots, user_data.mode, user_data.width, user_data.height);
			uint tickCount = sim.simulate();
			display(tickCount);
		}
		else
		{
			double tickCount[10000];
			bool listo = false;
			for (int n = 1; !listo ; n++)
			{
				for (int i = 0; i < 1000; i++)
				{
					Simulation sim(n, user_data.mode, user_data.width, user_data.height);
					tickCount[n - 1] += sim.simulate();
					sim.destroy();
				}
				tickCount[n - 1] /= 1000.0;
				drawHistogram(tickCount[n - 1], n);
				if (n > 1)
				{
					listo = (abs(tickCount[n - 2] - tickCount[n - 1]) <= .1);
				}
			}
		}
	}
	else
	{
		printf("La informacion no fue ingresada de la manera esperada.\n");
		how_to_use();

		al_rest(10.0);
	}
}