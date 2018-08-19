#ifndef HEADER_H
#define HEADER_H

#include <iostream>

typedef unsigned int uint;

typedef struct {
	uint amountOfRobots;
	uint height;
	uint width;
	int mode;
}userData;

typedef int(*pCallback) (const char *, const char *, void *);


int parseCmdLine(int argc, const char *argv[], pCallback p, void * userData);
int parseCallback(const char * key, const char * value, void *user_data);
void how_to_use(void);

#endif
