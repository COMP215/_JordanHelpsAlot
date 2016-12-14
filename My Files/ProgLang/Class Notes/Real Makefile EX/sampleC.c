#include<stdio.h>
int main (int argc, char **argv) {

	float number;
	FILE *fp; /* fp is Gousie's standard file pointer */

	fp = fopen (argv[1], "r"); /* r is for "read" */
	if (fp) {
		while (fscanf (fp, "%f", &number) != EOF){ /* fscanf is scanf for files */
			printf ("%8.2f\n",number);
		}
		fclose (fp);
	} else
	printf("error");

	return 0;
}
