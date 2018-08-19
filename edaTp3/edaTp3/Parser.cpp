#include "Header.h"


int parseCmdLine(int argc, const char *argv[], pCallback p, void * userData)
{
	int result = 0;
	int i;
	for (i = 1; (i<argc) && (result >= 0); i++)
	{
		if (argv[i] != NULL)
		{
			if (*argv[i] == '-')
			{
				if (p(argv[i], argv[i + 1], userData))
				{
					result++;
					i++;
				}
				else
				{
					result = -1;
				}
			}
			else
			{
				result = -1;
			}
		}
	}
	return result;
}

int parseCallback(const char * key, const char * value, void *user_data) {
	userData *pUserData = (userData*)user_data;
	int result = 0;
	if (!(strcmp(key, "-Robots")))
	{
		pUserData->amountOfRobots = atof(value);
		result = 1;
	}
	else if (!(strcmp(key, "-Height")))
	{
		pUserData->height = atof(value);
		result = 1;
	}
	else if (!(strcmp(key, "-Width")))
	{
		pUserData->width = atof(value);
		result = 1;
	}
	else if (!(strcmp(key, "-Mode")))
	{
		pUserData->mode = atoi(value);
		result = 1;
	}
	return result;
}

void how_to_use(void) {
	printf("ingresar de la forma: \n \t\t -Robots... - Mode... -Height... -Width... \n");
	printf("Si usted eligio el modo 1, las opciones son las siguientes:\n \t\t -Robots -Height -Width \n");
	printf("Si usted eliigio el modo 2, las opciones son las siguientes:\n \t\t -Height -Width \n");
}