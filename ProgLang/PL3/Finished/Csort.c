/* Program:		Csort.c
 * Author:		Jordan Hamilton
 * Function:	Sort values or strings from within a file
 * Input:		Input file may be either A) a list of strings, or B) a list of floats/integers 
 * 				-> Input file type must correspond with flag chosen
 * 					-A) Flags: file is list of strings
 * 						-r: Reverse alphabetical sort
 * 						-u: Alphabetical sort of unique elements
 * 						(none): basic alphabetical sort
 * 					-B) Flags: file is list of floats/integers
 * 						-n: numeric sort
 * 						-nr: reverse numeric sort
 * Output:		Displays sorted file data to std out
 */ 

#include<stdio.h>
#include<string.h>
const int MAX_STR_LEN = 30;		/* Maximum potential length of a string */
const int MAX_STR_AMT = 100;	/* Maximum potential number of lines in string */

int  getLineCount	(char *fileName);
void basicSort		(char *fileName, char stringArray[][MAX_STR_LEN], int lineCount);
void numericSort	(char *fileName, float floatArray[], int lineCount);
void num_arr_rev	(float floatArray[], int lineCount);
void string_arr_rev	(char stringArray[][MAX_STR_LEN], int lineCount);

int getLineCount(char *fileName) {
/*	PRE:  fileName string assigned
 *  POST: NA
 * 		->fileName: string containing the name of the file for sort	*/
	FILE *fp;
	fp = fopen(fileName, "r");
	char bufferString[MAX_STR_AMT][MAX_STR_LEN];
	int lineCount = 0;
	if (!fp) { printf("couldn't find file: %s\n", fileName);}
	else {
		while (fscanf(fp, "%s", bufferString[lineCount])!=EOF){
			lineCount++;
	}	}
	fclose(fp);
	return lineCount;
}

void basicSort(char *fileName, char stringArray[][MAX_STR_LEN], int lineCount) {	
/*	PRE:  fileName string assigned, stringArray is empty, lineCount is assigned
 *  POST: stringArray is a sorted array containing the strings from source file
 * 		->fileName: string containing the name of the file for sort	
 * 		->lineCount: number of lines detected in the file	*/

	int i = 0, j = 0, cmp = 0;
	char swap[MAX_STR_LEN];
	
	FILE *fp;
	fp = fopen(fileName, "r");

	if (!fp) { printf("couldn't find file: %s\n", fileName);}
	else {
		while (fscanf(fp, "%s", stringArray[i])!=EOF){
			i++;
	}	}
	
	/*Bubble Sort -> http://www.programmingsimplified.com/c/source-code/c-program-bubble-sort*/
	for ( i = 0; i < ( lineCount ); i++) {
		for ( j = 0 ; j < lineCount-1; j++) {
			cmp=strcmp(stringArray[j],stringArray[j+1]);

			if(cmp>0){
				strcpy(swap,stringArray[j+1]);
				strcpy(stringArray[j+1],stringArray[j]);
				strcpy(stringArray[j],swap);
	}	}	}
	fclose(fp);
}

void numericSort(char *fileName, float floatArray[], int lineCount) {	
/*	PRE:  fileName string assigned, floatArray created but empty, lineCount assigned
 *  POST: floatArray is a sorted array containing the values from source file
 * 		->fileName: string containing the name of the file for sort	
 * 		->lineCount: number of lines detected in the file	*/

	int i = 0, j = 0;
	float swap = 0;
	
	FILE *fp;
	fp = fopen(fileName, "r");

	if (!fp) { printf("couldn't find file: %s\n", fileName);}
	else {
		for(i = 0; i < lineCount; i++){
			fscanf(fp,"%f", &floatArray[i]);
		}
	}
	
	/*Bubble Sort -> http://www.programmingsimplified.com/c/source-code/c-program-bubble-sort*/
	for ( i = 0; i < ( lineCount ); i++) {
		for ( j = 0 ; j < lineCount-1; j++) {
			if (floatArray[j] > floatArray[j+1]) {
				swap		= floatArray[j];
				floatArray[j]	= floatArray[j+1];
				floatArray[j+1]	= swap;
            } 
		}
	}
	fclose(fp);
}

void num_arr_rev(float floatArray[], int lineCount){
/*	PRE:  floatArray contains sorted values stored in increasing order
 *  POST: floatArray contains sorted values in decreasing order	*/
	int start = 0,
		end = lineCount - 1,
		temp;
    while (start < end){
		temp = floatArray[start];   
		floatArray[start] = floatArray[end];
		floatArray[end] = temp;
		start++;
		end--;
    }   
}     

void string_arr_rev(char stringArray[][MAX_STR_LEN], int lineCount)
/*	PRE:  stringArray contains sorted strings in alph. order
 *  POST: stringArray contains sorted strings in reverse alph. order	*/
{
	int start = 0,
		end = lineCount - 1;
	char temp[MAX_STR_LEN];

    while (start < end){
		strcpy(temp, stringArray[start]);
		strcpy(stringArray[start], stringArray[end]);
		strcpy(stringArray[end], temp);
		start++;
		end--;
    }   
}  

int main (int argc, char **argv) {
	
	char *fileName = argv[1];
	char *flag;
	char stringBuffer[MAX_STR_LEN];
	
	if (argc == 3) {flag = argv[1]; fileName = argv[2];}
	
	const int 	lineCount = getLineCount(fileName);
	float 		floatArray[lineCount];
	int			i;
	char 		stringArray[lineCount][MAX_STR_LEN];
		
	if (flag == '\0' || strcmp(flag, "-u") == 0) {
		basicSort(fileName, stringArray, lineCount);
	} else if (strcmp(flag, "-n") == 0) {
		numericSort(fileName, floatArray, lineCount);
	} else if (strcmp(flag, "-r") == 0) {
		basicSort(fileName, stringArray, lineCount);
		string_arr_rev(stringArray, lineCount);
	} else if (strcmp(flag, "-nr") == 0) {
		numericSort(fileName, floatArray, lineCount);
		num_arr_rev(floatArray, lineCount);
	}
	
	if ( flag == '\0' || strcmp(flag, "-r") == 0 ){
		for ( i = 0; i < lineCount; i++) {
			printf("%s\n", stringArray[i]);
		}
	}
	else if ( strcmp(flag, "-u") == 0 ){
		for ( i = 0; i < lineCount; i++) {
			if ( strcmp( stringBuffer, stringArray[i] ) != 0 ){
				printf("%s\n", stringArray[i]);
			}
			strcpy(stringBuffer, stringArray[i]);
		}
	}
	else if ( strcmp(flag, "-n") == 0 || strcmp(flag, "-nr") == 0 ){
		for ( i = 0; i < lineCount; i++) {
			printf("%15.3f\n", floatArray[i]);
		}
	}
	
	return 0;
}
