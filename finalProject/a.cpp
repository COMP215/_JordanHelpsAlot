#include<iostream>
#include <fstream>
#include <string>
#include <vector>
#include"b.cpp"
#include"c.h"
using namespace std;

string sender(string input);
void hipHop(void);

void hipHop(void){
	cout << "function worked!" << endl;
}

int main(){
	short counter = 0;
	string token;
	vector<string> x_vals;
	vector<string> y_vals;
	
	ifstream myfile;
	bool flip = true;
	myfile.open ("inputFile.txt");
	if (myfile.is_open()) {
		cout << "yoyo" << endl;
		while ( getline (myfile,token, ',') ){
			cout << "TOKEN(" << counter << "): " << token << endl;
			if (flip) {
				x_vals.push_back(token);
				flip = false;
			}
			else{
				y_vals.push_back(token);
				flip = true;
			}
			counter++;
		}
	}
	myfile.close();
	cout << "finished reading in from file..." << endl;
	cout << x_vals.size() << endl;
	cout << y_vals.size() << endl;
	for (short i=0; i<3; i++){
		//cout << x_vals[i] << endl;
		cout << x_vals[i] << ", " << y_vals[i] << endl;
	}
	
	hipHop();
	
	string test;
	test = "supppp";
	cout << sender(test) << endl;
	
	return 0;
	
	}
	
