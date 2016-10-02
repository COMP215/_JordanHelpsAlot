#include<stdio.h>

int main (int argc, char **argv) {
	
	char *fileName = argv[1];
	FILE *fp;
	fp = fopen(fileName, "r");
	
	if (!fp) { printf("couldn't find file: %s\n", fileName);}


	return 0;
}
