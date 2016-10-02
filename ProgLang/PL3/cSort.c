
#include<stdio.h>
#include<string.h>

int main (int argc, char **argv) {


	float new_value=0;
	int counter=0;
	FILE *fp;
	fp = fopen (argv[1], "r"); 
	if (fp) { 
		while (fscanf (fp, "%f\n", &new_value)!=EOF){
			counter++; 
			printf("%3.2f\n", new_value); 
		}
	}
	fcloseall();
	float va[counter];
	counter = 0;
	fp = fopen (argv[1], "r"); 
	if (fp) { 
		while (fscanf (fp, "%f\n", &new_value)!=EOF){
			va[counter] = new_value;
				printf("number: %3.2f\n", va[counter]);
		}
	}
	
	printf("3rd number: %3.2f\n", va[2]);
		
	

	

	return 0;
}
