#include "pa1.h"


FILE* openFile(void) 
{
	FILE *infile;
	infile = fopen("FitbitData.csv", "r");
	if (infile == NULL) {
		printf("Error: File was not found");
		return 0;
	}

	return infile;
}

double computeCaloriesBurned(FitbitData arr[])
{
	double totalCaloriesBurned = 0.0;
	// sizeof(array)/sizeof(array[0]) = size of array
	for(int i=0; i<ARRAY_SIZE; i++) {
		totalCaloriesBurned += arr[i].calories;
	}
	
	return totalCaloriesBurned;
}

double computeDistanceWalked(FitbitData arr[])
{
	// Distance in miles
	double totalDistanceWalked = 0.0;
	
	for(int i=0; i<ARRAY_SIZE; i++){
		totalDistanceWalked += arr[i].distance;
	}

	return totalDistanceWalked;
}	

unsigned int computeAverageHeartRate(FitbitData arr[])
{
	int sum = 0, average = 0;
	
	for(int i=0; i<ARRAY_SIZE; i++){
		sum += arr[i].heartRate;
	}
	
	average = sum / ARRAY_SIZE;

	return average;
}

unsigned int computeFloorsWalked(FitbitData arr[])
{
	unsigned int totalFloorsWalked = 0;
	
	for(int i=0; i<ARRAY_SIZE; i++){
		totalFloorsWalked += arr[i].floors;
	}

	return totalFloorsWalked;
}

unsigned int computeStepsTaken(FitbitData arr[])
{
	unsigned int totalStepsTaken = 0;
	
	for(int i=0; i<ARRAY_SIZE; i++){
		totalStepsTaken += arr[i].steps;
	}

	return totalStepsTaken;
}

unsigned int maxSteps(FitbitData arr[])
{
	int max = 0, duplicate_max = 0;
	
	for(int i=0; i<ARRAY_SIZE; i++){
		if (arr[i].steps > max) {
			max = arr[i].steps;
		}
		// The FitbitData array was populated sequentially by time, so the first max is
		// the latest in the 24-hour period
	}
	
	return max;
}

void parseString(char *str, FitbitData data[1440])
{
	char *token; // used in strtok()

	token = strtok(str, ","); // "," is the delimiter of the csv
	

	token = strtok(NULL, ",");
	printf("%s \n",token);
	

}
