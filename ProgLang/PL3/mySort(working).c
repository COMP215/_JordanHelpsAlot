#include<stdio.h>
#include<string.h>
const int MAX_STR_LEN = 30;
const int MAX_STR_AMT = 100;

int  getLineCount	(char *fileName);
void basicSort		(char *fileName, char sArray[][MAX_STR_LEN], int lineCount);
void numericSort	(char *fileName, float floatArray[], int lineCount);
void num_arr_rev	(float floatArray[], int lineCount);
void string_arr_rev	(char stringArray[][MAX_STR_LEN], int lineCount);


int getLineCount(char *fileName) {
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

	int i = 0, j = 0, cmp = 0;
	char swap[MAX_STR_LEN];
	
	FILE *fp;
	fp = fopen(fileName, "r");

	if (!fp) { printf("couldn't find file: %s\n", fileName);}
	else {
		while (fscanf(fp, "%s", stringArray[i])!=EOF){
			i++;
	}	}
	
	for ( i = 0; i < ( lineCount ); i++) {
		for ( j = 0 ; j < lineCount-1; j++) {
			cmp=strcmp(stringArray[j],stringArray[j+1]);

			if(cmp>0){
				strcpy(swap,stringArray[j+1]);
				strcpy(stringArray[j+1],stringArray[j]);
				strcpy(stringArray[j],swap);
	}	}	}

}

void numericSort(char *fileName, float floatArray[], int lineCount) {	

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
	
	for ( i = 0; i < ( lineCount ); i++) {
		for ( j = 0 ; j < lineCount-1; j++) {
			if (floatArray[j] > floatArray[j+1]) {
				swap		= floatArray[j];
				floatArray[j]	= floatArray[j+1];
				floatArray[j+1]	= swap;
            } 
		}
	}
}

void num_arr_rev(float floatArray[], int lineCount)
{
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
{
	int start = 0,
		end = lineCount - 1;
	char temp[MAX_STR_LEN];

    while (start < end){
		strcpy(temp, stringArray[start]);
		strcpy(stringArray[start], stringArray[end]);
		strcpy(stringArray[end], temp);
		/*
		strcpy(stringArray[start], temp);
		strcpy(stringArray[end], stringArray[start]);
		strcpy(temp, stringArray[end]);
		*/
		start++;
		end--;
    }   
}  

int main (int argc, char **argv) {
	
	char *fileName = argv[1];
	char *flag;
	
	if (argc == 3) {flag = argv[1]; fileName = argv[2];}
	
	const int lineCount = getLineCount(fileName);
	float floatArray[lineCount];
	int i;
	char stringArray[lineCount][MAX_STR_LEN];
	if (flag == '\0') {
		basicSort(fileName, stringArray, lineCount);
	} else if (strcmp(flag, "-n") == 0) {
		numericSort(fileName, floatArray, lineCount);
	} else if (strcmp(flag, "-r") == 0) {
		basicSort(fileName, stringArray, lineCount);
		string_arr_rev(stringArray, lineCount);
	}/* else if (strcmp(flag, "-u") == 0) {
		basicSort();
		removeDuplicates();
	} */else if (strcmp(flag, "-nr") == 0) {
		numericSort(fileName, floatArray, lineCount);
		num_arr_rev(floatArray, lineCount);
	}
	

	if ( flag == '\0' || strcmp(flag, "-r") == 0 || strcmp(flag, "-u") == 0 ){
		for ( i = 0; i < lineCount; i++) {
			printf("%s\n", stringArray[i]);
		}
	}
	else if ( strcmp(flag, "-n") == 0 || strcmp(flag, "-nr") == 0 ){
		for ( i = 0; i < lineCount; i++) {
			/*printf("%10.5f\n", floatArray[i]);*/
			printf("%.3f\n", floatArray[i]);
		}
	}
	
	return 0;
}
