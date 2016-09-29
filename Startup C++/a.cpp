#include<iostream>
#include"b.cpp"
#include"c.h"
using namespace std;

string sender(string input);
void hipHop(void);

void hipHop(void){
	cout << "function worked!" << endl;
}

int main(){

	cout << "hey there" << endl;
	cout << "Hey Jord... I think this is a bit better then code blocks ;)" << endl;
	
	hipHop();
	
	string test;
	test = "supppp";
	cout << sender(test) << endl;
	
	return 0;
	
	}
	
