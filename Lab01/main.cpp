#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <algorithm>
#include <sstream>
#include <time.h>
using namespace std;

const int MAX_STRINGS = 50;

string string_generator(void);
char character_generator(void);
void sorter(string string_to_print);
int singleRound();

int main()
{
    cout << endl << "Data Set #1:" << endl;
    singleRound();
    cout << endl << "Data Set #2:" << endl;
    singleRound();
    cout << endl << "Data Set #3:" << endl;
    singleRound();
}

int singleRound()
{
    string full_string;
    full_string = string_generator(); // generates the data
    cout << "original data: " << full_string << endl;      // test the data
    sorter(full_string);

    return 0;
}

char character_generator()
{
    short  character = 0;
    character = rand() % 26 + 1;
    switch(character)
    {
        case 1 : return 'A';
        case 2 : return 'B';
        case 3 : return 'C';
        case 4 : return 'D';
        case 5 : return 'E';
        case 6 : return 'F';
        case 7 : return 'G';
        case 8 : return 'H';
        case 9 : return 'I';
        case 10: return 'J';
        case 11: return 'K';
        case 12: return 'L';
        case 13: return 'M';
        case 14: return 'N';
        case 15: return 'O';
        case 16: return 'P';
        case 17: return 'Q';
        case 18: return 'R';
        case 19: return 'S';
        case 20: return 'T';
        case 21: return 'U';
        case 22: return 'V';
        case 23: return 'W';
        case 24: return 'X';
        case 25: return 'Y';
        case 26: return 'Z';
    }
}

string string_generator()
{
    srand (time(NULL));
    double string_length = 0,
           string_number = 0;
    string return_string = "";
    string_length = rand() % 30 + 1;
    //string_number = rand() % MAX_STRINGS + 1;
    string_number = 30;
    for (short i=0; i < string_number; i++)
    {
        string_length = rand() % 30 + 1;
        for (short i=0; i < string_length; i++)
        {
            return_string += character_generator();
        }
        return_string += ' ';
    }
    return return_string;
}

void sorter(string string_to_print)
{
    string string_list[MAX_STRINGS+1];
    int i = 0;
    stringstream ssin(string_to_print);
    while (ssin.good() && i < MAX_STRINGS)
    {
        ssin >> string_list[i];
        ++i;
    }

    for (short i=0; i < 25; i++)
    {
        for (short x = 0; x < 30; x++)
        {
            short y = x++,
                  xLength = 0,
                  yLength = 0;
            string temp = "";

            xLength = string_list[x].length();
            yLength = string_list[y].length();

            if (xLength < yLength)
            {
                temp = string_list[x];
                string_list[x] = string_list[y];
                string_list[y] = temp;
            }
        }
    }

    for (short i=0; i<30; i++)
    {
        cout << string_list[i] << " ";
    }
    cout << endl;

}
