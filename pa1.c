#include "pa1.h"


/* 
 * writeFile() is takes two arguments, (1) output filename, (2) write mode
 * IO_ERROR (macro for NULL) is returned if a file does not exist
 * otherwise, returns a file open for read/write
 */
FILE * openFile(char *filename, char *mode)
{
	FILE * file = NULL;
	file = fopen(filename, mode); // mode = "w" would suffice for this program
	
	if(file == NULL) {
		printf("Error: File was not found... check the filename\n");
		return IO_ERROR;
	}
	
	return file;
	
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

/*
Instruction:
You must report the longest consecutive range of poor sleep; a range is defined as one or more consecutive minutes where the sleepLevel > 1; the poorest sleep is not based on the length of the range, but the sum of the sleep levels in the range; the max sum of the ranges is considered the poorest sleep (report the starting and ending minutes of range)
*/

unsigned int poorSleepRange(FitbitData arr[], char *start, char *end) 
{
	unsigned int sumRange = 0, max = 0, lastIndex = 0;
	unsigned int firstRange = 0, lastRange = 0;
	
	for(int i=0; i<ARRAY_SIZE; i++){
		if(arr[i].sleepLevel > SLEEP_LEVEL) {
			// only true when the data is not consecutive
			if ( (lastIndex+1) != i ) {
				//printf("%d  %d\n", sumRange, max);
				sumRange = 0;
				firstRange = i;
			}
			
			sumRange += arr[i].sleepLevel;
			//printf("%d: %d\n", i, arr[i].sleepLevel);
			
			if (sumRange > max){
				max = sumRange;
				lastRange = i;
			}
			
			// lastIndex checks if the sleepLevel are consecutive
			lastIndex = i;
		}
	}
	
	// lastRange is only less than firstRange if the first and last Range is the same
	if (lastRange < firstRange) {
		firstRange = lastRange;
	}
	
	// Sets the timestamp of poor sleep level
	strcpy(start, arr[firstRange].minute);
	strcpy(end, arr[lastRange].minute);
	
	return max;
}



void parseString(char *str, FitbitData data[1440])
{
	char *token; // used in strtok()

	token = strtok(str, ","); // "," is the delimiter of the csv
	

	token = strtok(NULL, ",");
	printf("%s \n",token);
	

}
