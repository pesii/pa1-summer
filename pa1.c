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

void parseString(char *str, FitbitData data[1440])
{
	char *token; // used in strtok()

	token = strtok(str, ","); // "," is the delimiter of the csv
	

	token = strtok(NULL, ",");
	printf("%s \n",token);
	

}
