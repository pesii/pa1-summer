# pa1-summer
Programming Assignment 1 for CPTS 122 - Summer

The source code for pa1.c is fully functional. Tested several things and they seem to work like charm, no unexpected output./

However, I'm not done yet with setting things up. I still need to migrate code from main.c to pa1.c and tidy up the code a bit.
I'll do house cleaning after I'm done with all the PAs, but a functional pa1.c that does everything as instructed by the prompt is good enough for now.

<br>
<br>
<br>
<b>Original Prompt</b>:
```
In this assignment, you must define a C struct to store each of the Fitbit data fields as follows:
 
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
 
The type Sleep is enumerated and must be defined as follows:
 
typedef enum sleep
{
     NONE = 0, ASLEEP = 1, AWAKE = 2, REALLYAWAKE = 3
} Sleep;
 
You must also define an array of FitbitData that can store 24 hours of minute data. Hence, you must declare an array of size 1440. You have the freedom to decide on other data structures and variables that you need for the assignment.
 
What are the other requirements?
 
This program does not require any user input! However, you will need to display some results to the screen!
 
-      You must open “FitbitData.csv” for mode read; check for success
-      You must read each record in the file as a string, one line at a time using fgets()
-      You must parse each record using strtok() from <string.h> into the corresponding fields, and store into the FitbitData array; note: not all fields have values, some are “empty” or null
-      You must compute the total calories burned, distance walked in miles, floors walked, and steps taken
-      You must compute average heartrate over the 24 hour period
-      You must report the max steps taken in one minute over the 24 hour period; if there are multiple minutes throughout the day where the max is discovered, then report the one that is the latest in the 24 hour period
-      You must report the longest consecutive range of poor sleep; a range is defined as one or more consecutive minutes where the sleepLevel > 1; the poorest sleep is not based on the length of the range, but the sum of the sleep levels in the range; the max sum of the ranges is considered the poorest sleep (report the starting and ending minutes of range)
-      You must open “Results.csv” for mode write; this will either create a new .csv or overwrite an existing one
-      You must output two lines to “Results.csv” and to the screen in the following format:
o   Line 1: Total Calories,Total Distance,Total Floors,Total Steps,Avg Heartrate,Max Steps,Sleep
o   Line 2: valueCalories,valueDistance,valueFloors,valueSteps,valueHeartrate,valueMax,valueSleepStart:valueSleepEnd
-      You must close “FitbitData.csv” and “Results.csv”
```
