#include "Header.h"


int parseCmdLine(int argc, char *argv[], pCallback p, void * userData)
{
	int result = 0;
	int i;
	for (i = 1; (i<argc) && (result >= 0); i++)
	{
		if (argv[i] != NULL)
		{
			if (*argv[i] == '-')
			{
				if ((result = p(argv[i], argv[i + 1], userData)) > 0)
				{
					result++;
					i++;
				}
			}
			else
			{
				result = -3;
			}
		}
	}
	return result;
}

int parseCallback( char * key, char * value, void *user_data) {
	userData *pUserData = (userData*)user_data;
	int result = 0;
	if (!(caseInsensitive(key, "-robots")))
	{
		pUserData->amountOfRobots = atof(value);
		result = 1;
	}
	else if (!(caseInsensitive(key, "-height")))
	{
		if (atof(value) <= HLIMIT)
		{
			pUserData->height = atof(value);
			result = 1;
		}
		else
		{
			result = -1;
		}
	}
	else if (!(caseInsensitive(key, "-width")))
	{
		if (atof(value) <= WLIMIT)
		{
			pUserData->width = atof(value);
			result = 1;
		}
		else
		{
			result = -2;
		}
	}
	else if (!(caseInsensitive(key, "-mode")))
	{
		pUserData->mode = atoi(value);
		result = 1;
	}
	return result;
}

void how_to_use(int result) {
	if (result == 0)
	{
		cout << "ingresar de la forma: \n \t\t -Robots... - Mode... -Height... -Width... \n";
		cout << "Si usted eligio el modo 1, las opciones son las siguientes:\n \t\t -Robots -Height -Width \n";
		cout << "Si usted eliigio el modo 2, las opciones son las siguientes:\n \t\t -Height -Width \n";
	}
	else if (result == -1)
	{
		cout << "Recuerde que la altura maxima es 100 \n";
	}
	else if (result == -2)
	{
		cout << "Recuerde que el ancho maximo es 70 \n";
	}
	else if (result == -3)
	{
		cout << "Recuerde que no puede ingresar parametros";
	}
}

int caseInsensitive(const char * str1, const char * str2)
{
	char auxStr1[100];
	char auxStr2[100];
	strcpy_s(auxStr1, 100, str1);
	str_to_lwr(auxStr1);
	strcpy_s(auxStr2, 100, str2);				// Uso strcpy_s porque usando strcpy Visual me hacia saltar un error.
	str_to_lwr(auxStr2);

	return strcmp(auxStr1, auxStr2);
}

void str_to_lwr(char * str)
{
	int i = 0;
	while (*(str + i) != '\0')
	{
		if (isupper(*(str + i)))
		{
			*(str + i) = tolower(*(str + i));
		}
		i++;
	}
}