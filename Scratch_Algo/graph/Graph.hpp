//
//  Graph.hpp
//
//

#ifndef Graph_hpp
#define Graph_hpp

#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    std::string data_;
    std::vector<Node*> node_vector;
    int vect_counter;
    Node* pointer_one;		
    Node* pointer_two;		
    
public:
    Node();

};

class Graph {

public:
	Graph();
	std::vector<Node*> graph_vector;
	int array_counter;
	void AddToGraph(std::string data_);
	void LinkNodes(string target_node_a, string target_node_b);
	void isLinkedWith(string base_node_data);
	bool isBipartite(void);
	
};



#endif /* graph_hpp */
