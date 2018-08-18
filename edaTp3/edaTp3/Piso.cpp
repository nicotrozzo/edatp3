#include "Piso.h"
#include "Robot.h"

Piso::Piso(uint h, uint w)
{
	Hcount = h;
	Wcount = w;
	baldosas = (bool*)malloc(h*w * sizeof(bool));
	if (baldosas != NULL)
	{
		for (int i = 0; i < h*w; h++)
		{
			baldosas[i] = SUCIO;
		}
		err.errNum = NO_ERROR;
	}
	else
	{
		err.errNum = NO_MEMORY;
		err.detail = "No memory in Piso Constructor";
	}
}

uint Piso::getHeight()
{
	return Hcount;
}

uint Piso::getWidth()
{
	return Wcount;
}

/*1 si esta sucio, 0 si esta limpio*/
bool Piso::isDirty(uint x, uint y)
{
	return baldosas[x + y * Wcount];
}

bool Piso::isFloorClean()
{
	bool ret = LIMPIO;
	for (int i = 0; (i < Hcount*Wcount) && !ret; i++)
	{
		ret = baldosas[i];
	}
	return ret;
}

void Piso::cleanTile(uint x, uint y)
{
	if ((x < Wcount) && (y < Hcount))
	{
		baldosas[x + y * Wcount] = LIMPIO;
	}
}

void Piso::cleanTile(tpos pos)
{
	cleanTile((uint)floor(pos.x), (uint)floor(pos.y));
}

void Piso::destroy()
{
	free(baldosas);
}

bool Piso::isDirty(uint x, uint y)
{
	return baldosas[y*Wcount + x];
}

errorType Piso::getError()
{
	return err;
}