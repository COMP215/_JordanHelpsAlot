
//
//  Graph.hpp
//
//
/*
#ifndef mushroom_hpp
#define mushroom_hpp
*/
#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

/*-------------------------------------------*/

class Node {
public:
    string 	common_name, 
			scientific_name;
			
    int 	weight, 
			total_value;
			
	double	value_per_ounce;
	
    
public:
    Node();
    Node(string common_name_input, string scientific_name_input, int weight_input, int total_value_input);
};

/*-------------------------------------------*/

class Satchel {
public:
	int max_capacity;
	vector<Node*> mushrooms_in_satchel;
	
public:
	Satchel(int size_oz);
	void addMushroom(string common_name_input, string scientific_name_input, int weight_input, int total_value_input);
	void displaySatchel(void);
	void optimizeSatchel(void);

};
