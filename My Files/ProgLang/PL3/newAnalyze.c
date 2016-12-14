#include<stdio.h>
const int MAX_STR_LEN=60;

void countCharsLines( int *char_count, int *line_count,  char* fileName ) {
	char charBuffer;
	*char_count = 0;

	FILE *fp;
	fp = fopen(fileName, "r");
	
	if (!fp) { printf("couldn't find file: %s\n", fileName);}
	else{
		while (fscanf(fp, "%c", &charBuffer)==1){
			if (charBuffer == '\n'){ (*line_count = *line_count + 1);}
			*char_count = *char_count + 1;
		}
	}
	fclose(fp);
}

void countWords( int *word_count, char* fileName ) {
	char wordBuffer[MAX_STR_LEN];
	*word_count = 0;

	FILE *fp;
	fp = fopen(fileName, "r");
	
	if (!fp) { printf("couldn't find file: %s\n", fileName);}
	else{
		while (fscanf(fp, "%s", wordBuffer)!=EOF){
			*word_count = *word_count + 1;
		}
	}
	fclose(fp);
}

int main (int argc, char **argv) {

	int char_count = 0,
		line_count = 0,
		word_count = 0;
		
	int *char_ptr = &char_count,
		*line_ptr = &line_count,
		*word_ptr = &word_count;
	
	countCharsLines(char_ptr, line_ptr, argv[1]);
	countWords(word_ptr, argv[1]);
	printf("Lines: %i, Words: %i, Bytes: %i\n", line_count, word_count, char_count);
		
	return 0;
}
	
	
