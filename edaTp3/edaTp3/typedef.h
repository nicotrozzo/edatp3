#ifndef TYPEDEF_H
#define TYPEDEF_H

#include <iostream>

typedef unsigned int uint;

typedef enum { NO_ERROR, NO_MEMORY }tErr;

typedef struct
{
	std::string detail;
	tErr errNum;
}errorType;

typedef struct
{
	double x;
	double y;
}tpos;


#endif

