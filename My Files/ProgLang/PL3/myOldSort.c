#include<stdio.h>
#include<string.h>
const int MAX_STR_LEN = 30;
const int MAX_STR_AMT = 100;

void basicSort(char *fileName, char sArray[][MAX_STR_LEN], int lineCount);
void numericSort(char *fileName, int intArray[], int lineCount);


int getLineCount(char *fileName) {
	FILE *fp;
	fp = fopen(fileName, "r");
	char bufferString[MAX_STR_AMT][MAX_STR_LEN];
	int lineCount = 0;
	if (!fp) { printf("couldn't find file: %s\n", fileName);}
	else {
		while (fscanf(fp, "%s", bufferString[lineCount])!=EOF){
			lineCount++;
		}
	}
	return lineCount;
}

int main (int argc, char **argv) {
	
	char *fileName = argv[1];
	
	printf ("here\n");
	char *flag = NULL;
	if (argc == 3) {flag = argv[1]; fileName = argv[2];}
	printf("Flag Entry: %s\n", flag);
	int  lineCount = getLineCount(fileName),
		 intArray[lineCount];
	printf("lines in file: %i\n", lineCount);
	char stringArray[lineCount][MAX_STR_LEN];
			 
	if (flag == '\0') {
		basicSort(fileName, stringArray, lineCount);
	} else if (strcmp(flag, "-n") == 0) {
		numericSort(fileName, intArray, lineCount);
	} /*else if (strcmp(flag, "-r") == 0) {
		basicSort();
		arrayReverser();
	} else if (strcmp(flag, "-u") == 0) {
		basicSort();
		removeDuplicates();
	} else if (strcmp(flag, "-nr") == 0) {
		numericSort();
		arrayReverser();
	}
	*/
	
	return 0;
}

void numericSort(char *fileName, int intArray[], int lineCount) {	

	int i = 0, j = 0, swap = 0;
	
	FILE *fp;
	fp = fopen(fileName, "r");

	if (!fp) { printf("couldn't find file: %s\n", fileName);}
	else {
		while (fscanf(fp, "%i", &intArray[i])!=EOF){
			i++;
		}
	}
	
	for ( i = 0; i < ( lineCount ); i++) {
		for ( j = 0 ; j < lineCount-1; j++) {
			if (intArray[j] > intArray[j+1]) /* For decreasing order use < */{
				swap		= intArray[j];
				intArray[j]	= intArray[j+1];
				intArray[j+1]	= swap;
            } 
		}
	}
	
	
	for ( i = 0; i < lineCount; i++) {
		printf("line %i= %i\n", i+1, intArray[i]);
	}
}

void basicSort(char *fileName, char stringArray[][MAX_STR_LEN], int lineCount) {	

	int i = 0, j = 0, cmp = 0;
	char swap[MAX_STR_LEN];
	
	FILE *fp;
	fp = fopen(fileName, "r");

	if (!fp) { printf("couldn't find file: %s\n", fileName);}
	else {
		while (fscanf(fp, "%s", stringArray[i])!=EOF){
			printf("line %i= %s\n", i+1, stringArray[i]);
			i++;
		}
	}
	for ( i = 0; i < ( lineCount ); i++) {
		for ( j = 0 ; j < lineCount-1; j++) {
			cmp=strcmp(stringArray[j],stringArray[j+1]);

			if(cmp>0){
				strcpy(swap,stringArray[j+1]);
				strcpy(stringArray[j+1],stringArray[j]);
				strcpy(stringArray[j],swap);
            } 
		}
	}
	
	for ( i = 0; i < lineCount; i++) {
		printf("line %i= %s\n", i+1, stringArray[i]);
	}
}
