#ifndef PISO_H
#define PISO_H

#include <iostream>
#include <allegro5/allegro.h>
#include <cstdlib>
#include <math.h>
#include "typedef.h"

class Piso
{
	bool* baldosas;
	uint Wcount;
	uint Hcount;
	errorType err;
public:
	Piso(uint h, uint w);
	uint getHeight();
	uint getWidth();
	bool isDirty(uint x, uint y);
	bool isFloorClean();
	void cleanTile(uint x, uint y);
	void cleanTile(tpos pos);
	errorType getError();
	void destroy();
};

#endif