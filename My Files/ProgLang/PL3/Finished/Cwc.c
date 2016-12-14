/* Program:		Cwc.c
 * Author:		Jordan Hamilton
 * Function:	Display the number of words, lines, and bytes which exist in a given file
 * Input:		Any file containing whitespace delineated words (Most often a plain text file)
 * Output:		Outputs file information to std out (typically output is displayed in terminal)
 */ 

#include<stdio.h>
const int MAX_STR_LEN=60; /* Declare the maximum length any strings may be which are  */

void countCharsLines( int *char_count, int *line_count,  char* fileName );
void countWords( int *word_count, char* fileName );

void countCharsLines( int *char_count, int *line_count,  char* fileName ) {
/*	PRE:  fileName string assigned, char_count and line_count exist but are empty
 *  POST: Accurate values within char_count and line_count
 * 		->fileName: string containing the name of the file for sort	
 * 		->char_count: number of characters in file
 * 		->line_count: number of lines in file	*/
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
/*	PRE:  fileName string assigned, word_count exists but is empty
 *  POST: Accurate value within word_count
 * 		->fileName: string containing the name of the file for sort	
 * 		->word_count: number of words in file	*/
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
	
	
