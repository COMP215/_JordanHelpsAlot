#include<stdio.h>

int main (int argc, char **argv) {

	char* 	fileName = argv[1];
	char 	charBuffer;
	int 	counter = 0;
	printf("%s\n", fileName);

	FILE *fp;
	fp = fopen(fileName, "r");
	
	if (!fp) { printf("couldn't find file: %s\n", fileName);}
	else{
		while (fscanf(fp, "%c", &charBuffer)==1){
			if (charBuffer == '\n') { charBuffer = 'N'; }
			if 		(counter == 10){ printf("\n%c", charBuffer); counter = 1; }
			else 	{ printf("%c", charBuffer); counter++; }
		}
	}
	fclose(fp);
	
	return 0;
}
