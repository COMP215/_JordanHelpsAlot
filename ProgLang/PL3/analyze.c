#include<stdio.h>
const int MAX_STR_LEN=100;

int main (int argc, char **argv) {

	char *fullLine[40][MAX_STR_LEN];
	char placeHolder;
	int loop_counter = 0,
		line_counter = 0;

	FILE *fp;
	fp = fopen ( argv[1], "r"); 
	
	if (!fp) { printf("couldn't find file: %s\n", argv[1]);}
	else{
		while (fscanf(fp, "%c", &placeHolder)==1){
			if (placeHolder == '\n'){ line_counter++;}
			loop_counter++;
		}
		printf("Loop Count = %i, lines = %i\n", loop_counter, line_counter);
		
		rewind(fp);		//resets fp back to start of file
		loop_counter = 0;
		
		while (fscanf(fp, "%s", fullLine[loop_counter])!=EOF){
			printf("line reads: %s\n", fullLine[loop_counter]);
			loop_counter++;
		}
		printf("Loop Count = %i, lines = %i\n", loop_counter, line_counter);
	}
	fclose(fp);
	
	return 0;
}

