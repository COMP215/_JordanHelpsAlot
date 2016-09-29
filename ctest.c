#include<stdio.h>
#include<stdlib.h>

/*PROTOTYPES*/
int func(void);


int main (int argc, char **argv) {
/*IMPORTANT:
	-argc = number of arguments given
	-argv = array of strings, each value represents a different argument given	*/
	
	char ch;

	float number,
		 sum = 0,
		 average = 0;
	double counter = 0;
	FILE *source, *target; /* fp is Gousie's standard file pointer */

	source = fopen (argv[1], "r");
	target  = fopen (argv[2], "w");
	
	if (source && target) {
		while ((ch = fgetc(source)) != EOF){
			if (counter > 40){break;}
			else{
				printf("character: %c, number: %2.0f\n", ch, counter);}
				counter++;
			}

/*
		while( ( ch = fgetc(source) ) != EOF ) {
			fputc(ch, target);
			printf("counter: %d", counter);
			counter++;
		}*/
		fclose (source);
		fclose (target);
	} else { printf("error, filestream failed to open\n"); }

	return 0;
}

int func(void){
	printf("the function worked\n");
}
