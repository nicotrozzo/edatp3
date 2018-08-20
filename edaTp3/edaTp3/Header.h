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
#define HLIMIT 100
#define WLIMIT 70

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

typedef int(*pCallback) ( char *, char *, void *);


int parseCmdLine(int argc, char *argv[], pCallback p, void * userData);
int parseCallback( char * key, char * value, void *user_data);
void how_to_use(int result);
void drawAxis(void);
void drawHistogram(double tickCount, int n);
bool init_allegro(alData_t *al_data);
int caseInsensitive(const char * str1, const char * str2);
void str_to_lwr(char * str);

#endif
