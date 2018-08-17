#ifndef DIBUJATOR_H
#define DIBUJATOR_H

typedef struct
{
	double x;
	double y;
}tpos;

typedef unsigned int uint;

class Dibujator
{
	uint Hcount;
	uint Wcount;
	uint robotCount;
	ALLEGRO_DISPLAY *display;
	uint unidad;
	void setUnit();
public:
	Dibujator(uint h, uint w, uint nRobots);
	draw(tpos pos);
};

#endif