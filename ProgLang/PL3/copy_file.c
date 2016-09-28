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

