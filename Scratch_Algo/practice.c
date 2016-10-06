#include<stdio.h>
#include<string.h>

int main(){
	char str[] = "sample string here.123456789";
	char * pch;
	printf ("Looking for the 's' character in \"%s\"...\n",str);
	int i = 0;

	for (pch = strchr(str,'.'); *pch != '\0'; pch++){
		i++;
	}
	printf("characters after (.) : %i\n", i-1);
	return 0;

}
