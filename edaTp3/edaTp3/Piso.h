#ifndef PISO_H
#define PISO_H

#include <iostream>

#define LIMPIO false
#define SUCIO true

typedef enum { NO_ERROR, NO_MEMORY }err;

typedef struct
{
	string detail;
	err errNum;
}errorType;

typedef unsigned int uint;

using namespace std;

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
	bool isDirty();
	bool isFloorClean();
	void cleanTile(uint x, uint y);
	void cleanTile(tpos pos);
	errorType getError();
	void destroy();
};

#endif