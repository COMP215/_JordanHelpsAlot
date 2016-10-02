#include<stdio.h>
const int MAX_STR_LEN=100;

void countCharsLines( int *char_count, int *line_count,  char** fileName ) {
	/*
	assert(char_count);
	assert(line_count);
	*/
	char charBuffer;
	*char_count = 0;
	printf("charBuffer= %i\n", char_count);

	FILE *fp;
	fp = fopen(fileName, "r");
	
	if (!fp) { printf("couldn't find file: %s\n", fileName);}
	else{
		while (fscanf(fp, "%c", &charBuffer)==1){
			printf("charBuffer= %c\n", charBuffer);
			if (charBuffer == '\n'){ (line_count++);}
			char_count = char_count + 1;
			
		}

		printf("Loop Count = %i, lines = %i\n", *char_count, *line_count);
	}

}

int main (int argc, char **argv) {

	int char_count = 0,
		line_count = 0,
		word_count = 0;
		
	int *char_ptr = &char_count,
		*line_ptr = &line_count;
	
	printf("charcount= %i\n", *char_ptr);

	countCharsLines(char_ptr, line_ptr, argv[1]);
	
	return 0;
}
	
	
