#include "pa1.h"

int main(void) 
{
	FILE * infile = NULL;
	char line[100], *token;
	infile = openFile();
    
	FitbitData records[1440];
	
	int i = 0;		
	while(!feof(infile)) {
		fgets(line, 100, infile);

		// Load minutes
		token = strtok(line, ",");
		if (token != NULL) {
			strcpy(records[i].minute, token);
			//printf("%d| %s", i, line);
		}
		
		// Load calories
		token = strtok(NULL, ",");
		if (token != NULL) {
			records[i].calories = atof(token);
//			printf("Token: %f \n", records[i].calories);  // enable this line for debugging
		}
		
		// Load distance
		token = strtok(NULL, ",");
	      	if (token != NULL) {
			records[i].distance = atof(token);
		}

		// Load floors
		token = strtok(NULL, ",");
		if (token != NULL) {
			records[i].floors = atoi(token);
		}
		// Load heartRate
		token = strtok(NULL, ",");
		if (token != NULL) {
			records[i].heartRate = atoi(token);
			//printf("%s\n", token);
		}

		// Load steps
		token = strtok(NULL, ",");
		if (token != NULL) {
			records[i].steps = atoi(token);
		}

		i++;
	}	
	//printf("Minutes: %d\n", records[1440].heartRate);
	
	/*
	for(int j=0; j<1441; j++) {
		printf("Minutes: %d\n", records[j].heartRate); 
	}*/
	maxSteps(records);
	
}
