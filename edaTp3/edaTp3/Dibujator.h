#ifndef DIBUJATOR_H
#define DIBUJATOR_H

#include <allegro5/allegro.h>
#include "typedef.h"

class Dibujator
{
	uint Hcount;
	uint Wcount;
	uint robotCount;
	ALLEGRO_DISPLAY *display;
	ALLEGRO_BITMAP *baldosaLimpia;
	ALLEGRO_BITMAP *baldosaSucia;
	ALLEGRO_BITMAP *robot;
	uint unidad;				//pixeles de cada lado de baldosas
	void setUnit();
	errorType error;
	void initializeAllegro();
public:
	Dibujator(uint h, uint w, uint nRobots, uint mode);
	void drawTile(double x, double y, bool state);
	void drawRobot(tpos pos, double angle);
	errorType getError();
	void destroy();
};

#endif