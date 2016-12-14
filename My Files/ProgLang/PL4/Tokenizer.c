/*Changes I've Made:
 *		-changed first counter to "sB_size"
 * 		-Added continue statement to first while loop
 * 		-changed realBuffer to "stringBuffer"
 * 		-temporarily reduced size of stringBuffer for testing
 * 
 * 
 * 
 */

#include <stdbool.h>
#include<stdio.h>
#include<string.h>
bool aToken(char stringBuffer[],int counter);
int main (int argc, char **argv) {

	char* 	fileName = argv[1];
	char 	charBuffer[1];
	char    stringBuffer[1000];
    int 	sB_size = 0;


	FILE *fp;
	fp = fopen(fileName, "r");
	if (!fp) { printf("couldn't find file: %s\n", fileName);}
	else{
		while (fscanf(fp, "%c", &charBuffer)!=EOF)
        {
            /*printf("yaaa %c\n",*charBuffer);*/
			if(isspace(*charBuffer))
			{
                if(sB_size != 0) /*checking if we're starting a string with a space*/
                {
                    strncat(stringBuffer,charBuffer,1);
                    sB_size++;
                }
                else /*true if we're starting string with space, skips the appending process */
                {
					continue;
                }
                
                if (aToken(stringBuffer, sB_size)==1)
                {
                    printf("t%s ", stringBuffer);
                    memset(stringBuffer, 0, sizeof(stringBuffer));
                    sB_size = 0;
				}

            }
            else /*if charBuffer isn't a space*/
            {
                strncat(stringBuffer,charBuffer,1);
                sB_size++;
            }
            
            if (aToken(stringBuffer, sB_size)==1)
            {
                /*printf("token found! \n");*/
                printf("%s ", stringBuffer);
                memset(stringBuffer, 0, sizeof(stringBuffer));
                sB_size = 0;
            }
            else{
				continue;
            }


		}
	}
	fclose(fp);

	return 0;
}

bool aToken(char stringBuffer[], int counter)
{
    char theTokens[3][10] = {"if","else","("};
    int i;
    int x;
    char emptyChar = " ";
    /*printf("aToken:::::%s \n", stringBuffer);*/
    for (i = 0; i < 4; i++)
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
