#include "Simulation.h"

typedef struct
{
	uint n;
	uint W;
	uint H;
	string Mode;
};

int main(int argc, char *argv[])
{
	//parsea
	if (parse)
	{
		if (args.Mode == "Mode 1")
		{
			Simulation sim(args.n, args.Mode, args.W, args.H);
			uint tickCount = sim.simulate();
			display(tickCount);
		}
		else
		{
			double tickCount[10000];
			bool listo = false;
			for (int n = 1; !listo; n++)
			{
				for (int i = 0; i < 1000; i++)
				{
					Simulation sim(n, args.Mode, args.W, args.H);
					tickCount[n - 1] += sim.simulate();
					sim.destroy();
				}
				tickCount[n - 1] /= 1000.0;
				drawHistogram(tickCount[n - 1], n);
				if (n > 1)
					listo = (abs(tickCount[n - 2] - tickCount[n - 1]) <= .1);
			}
		}
	}
}