#include<stdio.h>
#include<string.h>

int main (int argc, char **argv) {


	char new_line;
	float counter=0;
	FILE *fp;
	if ( argc < 3 ){
		fp = fopen (argv[1], "r"); 
			if (fp) { 
				while (fscanf (fp, "%s", &new_line)!=EOF){
					counter++; 
					printf("%s\n", &new_line); }
			}
	}

	else if ( argc == 3 ){
		fp = fopen (argv[2], "r"); 
		if (fp) {
			if (strcmp(argv[1],"-n")==0){
				while (fscanf (fp, "%s", &new_line)!=EOF){
					counter++;
					printf("%2.0f|%s\n", counter, &new_line);
				}
			}
			else if (strcmp(argv[1],"-b")==0){
				while (fscanf (fp, "%s", &new_line)!=EOF){
					if (strcmp(new_line,"\n")==0){
						counter++;
						printf("%2.0f|%s\n", counter, &new_line);
					}
				}		
			}
		}	
	}
	
	else if ( argc == 3 ){
		double duh;
	}
	
	return 0;
}
