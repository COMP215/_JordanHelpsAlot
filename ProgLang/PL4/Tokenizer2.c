/*Changes I've Made:
 *		-changed first counter to "sB_size"
 * 		-Added continue statement to first while loop
 * 		-changed realBuffer to "stringBuffer"
 * 		-temporarily reduced size of stringBuffer for testing
 * 
 * 
 * 
 */

#include<stdbool.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
bool isPunct(char charB);
bool isDefToken(char stringBuffer[],int counter);
int main (int argc, char **argv) {

	char* 	fileName = argv[1];
	char 	charBuffer, lookAhead;
	char    stringBuffer[100]; memset(stringBuffer, 0, sizeof(stringBuffer)); /*initialize string to '\0'*/
    int 	sB_size = 0;
    int		inComment = 0;
    
	FILE *fp, *fp2;
	fp = fopen(fileName, "r");
	fp2 = fopen(fileName, "r");
	if (!fp) { printf("couldn't find file: %s\n", fileName);}
	else{
		fscanf(fp2, "%c", &lookAhead);
		while (fscanf(fp, "%c", &charBuffer)!=EOF)
        {
			fscanf(fp2, "%c", &lookAhead);			/* keeps lookAhead one step beyond charBuffer */
			if (charBuffer == '\n'){continue;}		/* skips new line characters alltogether */
			strncat(stringBuffer,&charBuffer,1);	/* adds new char to string */
			sB_size++;
			
			if (isspace(stringBuffer[0])){ /*check if strbuff has a leading space*/
				memset(stringBuffer, 0, sizeof(stringBuffer)); 
				sB_size = 0; 
				continue;
			}
            
            if (isPunct(charBuffer)==1) { /* check if charbuffer is punctuation (AKA a token) */
                printf("Token:%s \n", stringBuffer);
                memset(stringBuffer, 0, sizeof(stringBuffer));
                sB_size = 0;
                continue;
			}
            
            if(isPunct(lookAhead)==1) { /*check if next char will be a closer or punctuation*/
				printf("Token:%s \n", stringBuffer);
				memset(stringBuffer, 0, sizeof(stringBuffer));
				sB_size = 0;
				continue;
			}
			
			if (isDefToken(stringBuffer, sB_size)==1){ /* check if strbuff is already a defined token */
                printf("Token:%s \n", stringBuffer);
                memset(stringBuffer, 0, sizeof(stringBuffer));
                sB_size = 0;
                continue;
            }
		}
	}
            
	fclose(fp);
	printf("\n");
	return 0;
}

bool isPunct(char charB) {
	int i = 0;
	char punctList[12] = {'[',']','(',')','{','}','*',',',':','=',';','"'}; 
	for (i = 0; i < 12; i++){
		if (punctList[i] == charB) { return true; }
		else { return false; }
	}
}
		

bool isDefToken(char stringBuffer[], int counter)
{
    char theTokens[3][10] = {"if","else"};
    int i;/*
    int x;
    char emptyChar = " "; */
    /*printf("isDefToken:::::%s \n", stringBuffer);*/
    for (i = 0; i < 2; i++)
    {
        if (strcmp(theTokens[i],stringBuffer) == 0)
        {
            return true;
        }
        else if(counter == 0)
        {
            return false;
        }
        else if(isspace(stringBuffer[counter-1]))
        {
            return true;
        }

        else{

        }

    }
    return false;
}
