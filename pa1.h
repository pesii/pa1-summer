#ifndef ASSIGNMENT1
#define ASSIGNMENT1

#define ARRAY_SIZE 1441
#define SLEEP_LEVEL 1
#define IO_ERROR NULL

#include <stdio.h> // printf()
#include <string.h> // strtok()
#include <stdlib.h>

/* Function prototypes */
FILE * openFile();
void parseString();
double computeCaloriesBurned();
double computeDistanceWalked();
unsigned int computeAverageHeartRate();
unsigned int computeFloorsWalked();
unsigned int computeStepsTaken();
unsigned int maxSteps();
unsigned int poorSleepRange();


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
