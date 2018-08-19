#ifndef TYPEDEF_H
#define TYPEDEF_H

#include <iostream>

using namespace std;

typedef unsigned int uint;

typedef enum { NO_ERROR, NO_MEMORY , BITMAP_ERR , DISPLAY_ERR }tErr;

typedef struct
{
	string detail;
	tErr errNum;
}errorType;

typedef struct
{
	double x;
	double y;
}tpos;

#define LIMPIO false
#define SUCIO true

#endif

