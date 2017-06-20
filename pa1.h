#ifndef ASSIGNMENT1
#define ASSIGNMENT1

#include <stdio.h> // printf()
#include <string.h> // strtok()
#include <stdlib.h>

/* Function prototypes */
FILE* openFile();
void parseString();



/* Types */
typedef enum sleep
{
	NONE=0, ASLEEP=1, AWAKE=2, REALLYAWAKE=3
} Sleep;

typedef struct fitbit
{
	char minute[9];
	double calories;
	double distance;
	unsigned int floors;
	unsigned int heartRate;
	unsigned int steps;
	Sleep sleepLevel;
} FitbitData;

#endif
