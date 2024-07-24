// Implmenting a CLI utility that does conversions
// Seconds to Minutes and Minutes to Seconds
// Minutes to Hours and Hours to Minutes
// Hours to Days and Days to Hours


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void help(void);
void convertHours(int);
void convertDays(int);
void convertMinutes(int);
void convertSeconds(int);

void help(void) {
	printf("-d [integer]: Show conversions of days to seconds, minutes, hours, etc.\n");
	printf("-h [integer]: Show conversions of hours to seconds, minutes, days, etc.\n");
	printf("-m [integer]: Show conversions of minutes to seconds, hours, days, etc.\n");
	printf("-s [integer]: Show conversions of seconds to minutes, hours, days, etc.\n");
}

void convertHours(int hours) {
	int seconds = hours*3600;
	int minutes = hours*60;
	float days = (float)hours/24;
	printf("\n-- %d HOURS TO --\n", hours);
	printf("seconds: %d\n", seconds);
	printf("minutes: %d\n", minutes);
	printf("days: %f\n", days);
}

void convertDays(int days) {
	int seconds = days*86400;
	int minutes = days*1440;
	int hours = days*24;
	printf("\n-- %d DAYS TO --\n", days);
	printf("seconds: %d\n", seconds);
	printf("minutes: %d\n", minutes);
	printf("hours: %d\n", hours);
}

void convertMinutes(int minutes) {
	int seconds = minutes*60;
	float hours = (float)minutes/60;
	float days = (float)minutes/1440;
	printf("\n-- %d MINUTES TO --\n", minutes);
	printf("seconds: %d\n", seconds);
	printf("hours: %f\n", hours);
	printf("days: %f\n", days);
}

void convertSeconds(int seconds) {
	float minutes = (float)seconds/60;
	float hours = (float)seconds/3600;
	float days = (float)seconds/86400;
	printf("\n-- %d SECONDS TO --\n", seconds);
	printf("minutes: %f\n", minutes);
	printf("hours: %f\n", hours);
	printf("days: %f\n", days);
}

int main(int argc, char* argv[]) {
	if(argc == 1) {
		printf("Nothing inputted, do --help for help.");
	} else if(argc == 2) {
		if(strcmp(*argv, "--help")) {
			help();
		}
	} else if(argc == 3) {
		if(!strcmp(argv[1], "-h")) {
			int hours = atoi(argv[2]);	
			convertHours(hours);
		} else if(!strcmp(argv[1], "-d")) {
			int days = atoi(argv[2]);
			convertDays(days);
		} else if(!strcmp(argv[1], "-m")) {
			int minutes = atoi(argv[2]);
			convertMinutes(minutes);
		} else if(!strcmp(argv[1], "-s")) {
			int seconds = atoi(argv[2]);
			convertSeconds(seconds);
		} else {
			printf("NOT AN OPTION\n");
		}
	}
}
