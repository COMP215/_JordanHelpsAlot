#include "mushroom.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>

using namespace std;

int main() {
	ifstream myfile;
	myfile.open ("mushroomInput.txt");
	string token, tokenA, tokenB;
	int lineCount = 0, tokenCount = 0, tokenC, tokenD;
	Satchel mySatch(30);
	if (myfile.is_open()) {
		while ( getline (myfile,token, ',') )
		{
			if (token[0] == '\n') {
				token.erase(0,1);
			}
			if (tokenCount == 0){
				tokenA = token;
			}
			else if (tokenCount == 1){
				tokenB = token;
			}
			else if (tokenCount == 2){
				istringstream convert_string_to_int(token);
				convert_string_to_int >> tokenC;
			}
			else if (tokenCount == 3){
				istringstream convert_string_to_int(token);
				convert_string_to_int >> tokenD;
			}
			if (tokenCount == 3){
				mySatch.addMushroom(tokenA, tokenB, tokenC, tokenD);
				lineCount++;
				tokenCount = 0;
			}
			else { tokenCount++; }
		}
		cout << "lines: " << lineCount << endl;
	}
	//myfile << "Writing this to a file.\n";
	myfile.close();
	mySatch.displaySatchel();
	
	return 0;
}
