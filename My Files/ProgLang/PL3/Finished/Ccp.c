/* Program:		Ccp.c
 * Author:		Jordan Hamilton
 * Function:	Duplicate the contents of a file into a new target destination
 * Input:		Any file may be chosen to replicate. Command line arguments are written as (executable, source file, target file)
 * Output:		Outputs perfect copy of file to user-defined destination
 */ 

#include<stdio.h>

int main (int argc, char **argv) {

	char new_character;
	FILE *read_fp, *write_fp;
	read_fp = fopen (argv[1], "r"); 
	write_fp = fopen (argv[2], "w");
	if (read_fp) {
		while (fscanf (read_fp, "%c", &new_character)!=EOF){
			fprintf(write_fp, "%c", new_character);
		}
	}
	
	return 0;
}

