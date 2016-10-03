#include<stdio.h>

int main (int argc, char **argv) {
	float subtotal,
		 sum = 0,
		 average = 0;
	short counter = 0;
	FILE *fp;
	fp = fopen (argv[1], "r"); 
	
	if (fp) {
		while (fscanf (fp, "%f", &subtotal) != EOF){ 
			sum=sum+subtotal;
			counter++;
		}
		fclose (fp);
	} else { printf("error, filestream failed to open\n"); }
	
	average = sum/counter;
	printf("Average: %5.2f\n", average);
	return 0;
}
