#include "pa1.h"

int main(void) 
{
	FILE * infile = NULL;
	char line[100], *token, rangeBegin[10], rangeEnd[10];
	infile = openFile("FitbitData.csv", "r");
	if(infile == IO_ERROR) {
		return 1;
	}
	
    // There are 1441 lines including the header, array of size 1441 is therefore needed
	FitbitData records[1441]; 
	
	
	int i = 0;		
	while(!feof(infile)) {
		fgets(line, 100, infile);

		// Tokenize string from line... load minute
		token = strtok(line, ",");
		if (token != NULL) {
			strcpy(records[i].minute, token);
			//printf("%d| %s", i, line);
		}
		
		// Continue tokenizing to calories
		token = strtok(NULL, ",");
		if (token != NULL) {
			records[i].calories = atof(token);
//			printf("Token: %f \n", records[i].calories);  // enable this line for debugging
		}
		
		// Continue tokenizing to distance
		token = strtok(NULL, ",");
	      	if (token != NULL) {
			records[i].distance = atof(token);
		}

		// Continue tokenizing to floors
		token = strtok(NULL, ",");
		if (token != NULL) {
			records[i].floors = atoi(token);
		}
		// Continue tokenizing to heartRate
		token = strtok(NULL, ",");
		if (token != NULL) {
			records[i].heartRate = atoi(token);
			//printf("%s\n", token);
		}

		// Continue tokenizing to steps
		token = strtok(NULL, ",");
		if (token != NULL) {
			records[i].steps = atoi(token);
		}
		
		// Continue tokenizing to sleepLevel
		token = strtok(NULL, ",");
		if (token != NULL) {
			records[i].sleepLevel = atoi(token);
		}

		i++;
	}	
	//printf("Minutes: %d\n", records[1440].heartRate);
	
	/*
	for(int j=0; j<1441; j++) {
		printf("Minutes: %d\n", records[j].heartRate); 
	}*/
	poorSleepRange(records, rangeBegin, rangeEnd);
	
	puts(rangeBegin);
	puts(rangeEnd);
	
	FILE * outfile = NULL;
	outfile = openFile("Result.csv", "w");
	
	fprintf(outfile, "Total Calories,Total Distance,Total Floors,Total Steps,Avg Heart Rate,Max Steps,Sleep\n");
	//fprintf(outfile, "Total Calories,Total Distance,Total Floors,Total Steps,Avg Heartrate,Max Steps,Sleep\n");
	fprintf(outfile,"%f,%f,%d,%d,%d,%d,",computeCaloriesBurned(records), computeDistanceWalked(records), 
												computeFloorsWalked(records), computeStepsTaken(records), 
													computeAverageHeartRate(records), maxSteps(records)
													
													);
	fprintf(outfile,"%s:%s\n", rangeBegin, rangeEnd);
	
	
}
