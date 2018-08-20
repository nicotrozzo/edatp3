#ifndef HEADER_H
#define HEADER_H


#include <iostream>
#include <string>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>

#define DIS_X 800
#define DIS_Y 100
#define M2_DIS_HEIGHT 300
#define M2_DIS_WIDTH 300
#define INIT_SEPARATION 10
#define SCALE 2
#define FONT_SIZE 20

using namespace ::std;

typedef unsigned int uint;

typedef enum { NO_AL_ERR, AL_INIT, INIT_PRIM, INIT_FONT, INIT_TTF, INIT_IMAGE }alError_t;

typedef struct
{
	alError_t error;
	string errDetail;
}alData_t;

typedef struct {
	uint amountOfRobots;
	uint height;
	uint width;
	int mode;
}userData;

typedef int(*pCallback) (const char *, const char *, void *);


int parseCmdLine(int argc, char *argv[], pCallback p, void * userData);
int parseCallback( char * key, char * value, void *user_data);
void how_to_use(void);
void drawAxis(void);
void drawHistogram(double tickCount, int n);
bool init_allegro(alData_t *al_data);

#endif
