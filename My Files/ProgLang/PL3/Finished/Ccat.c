/* Program:		Ccat.c
 * Author:		Jordan Hamilton
 * Function:	Display the contents of a file with various forms of line numbering
 * Input:		Any file. Flags: -n = numbered lines | -b = numbered non-blank lines. Command Line: (exe, flags, filename)
 * Output:		Displays file contents to std out
 */ 

#include<stdio.h>
#include<string.h>
const int MAX_STR_LEN = 200;
const int MAX_STR_AMT = 1000;

int  getLineCount	(char *fileName);

int getLineCount(char *fileName) {
/*	PRE:  fileName string assigned
 *  POST: NA
 * 		->fileName: string containing the name of the file for display	*/
	FILE *fp;
	fp = fopen(fileName, "r");
	char tempChar;
	int lineCount = 0;
	if (!fp) { printf("couldn't find file: %s\n", fileName);}
	else {
		while (fscanf(fp, "%c", &tempChar)!=EOF){
			if (tempChar == '\n'){ lineCount++; }
	}	}
	fclose(fp);
	return lineCount;
}

int main (int argc, char **argv) {

	int	i = 0, 
		j = 0, 			/* j used as alternative counter within non-empty line counting loop */
		lineCount = 0; 
	char fileName[30];
	
	if ( argc < 3 ){ strcpy(fileName, argv[1]); }
	else if ( argc == 3 ){ strcpy(fileName, argv[2]); }
	else { printf("error reading arguments\n"); }
	
	lineCount = getLineCount(fileName);
	char full_line[lineCount][MAX_STR_LEN];
	
	FILE *fp;
	fp = fopen(fileName, "r");

	if (!fp) { printf("couldn't find file: %s\n", fileName);}
	else {
		for (i=0; i<lineCount; i++){
			fgets(full_line[i], MAX_STR_LEN, fp); /* add strings from source to full_line string array */
		}	
	}
	
	fclose(fp);
	
	if ( argc < 3 ){
		for (i=0; i<lineCount; i++){
			printf("%s", full_line[i]);
		}
	}
	else if ( argc == 3 ){
		if (strcmp(argv[1],"-n")==0){
			for (i=0; i<lineCount; i++){
				printf("%2i| %s", i+1, full_line[i]);
			}
		}
		else if (strcmp(argv[1],"-b")==0){
			for (i=0; i<lineCount; i++){
				if ( full_line[i][0] != '\n' ){ 
					printf("%2i| %s", j+1, full_line[i]); 
					j++; 
				}
				else {
					printf("  | %s", full_line[i]);
				}
			}
		}
	}
	return 0;
}
