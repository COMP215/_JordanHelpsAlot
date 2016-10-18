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

/*-------------------------------------------*/

class Node {
public:
    char vertex;
    vector<Node*> node_vector;		
    
public:
    Node();
};
/*-------------------------------------------*/

class Edge {
public:
	char vertA, vertB;
	int weight;
	Node* vertA_loc;
	Node* vertB_loc;
	
public:
	Edge();
	Edge( Node* loc_a, Node* loc_b );
	Edge( Node* loc_a, Node* loc_b, int weight_value_passed );
};
/*-------------------------------------------*/

class Graph {
public:
	vector<Node*> graph_vector;
	vector<Edge*> master_edge_list;

public:
	Graph();
	void AddVertex(char vertex);
	void LinkNodes(char target_node_a, char target_node_b);
	void isLinkedWith(char base_node_vertex);
	bool isBipartite(void);
	void AddEdge(char source, char target);
	void AddEdge(char source, char target, int weight);
	Graph* PrimMST(void);
	Graph* Kruskal(void);
	void DisplayEdges(void);
	void ToGraphviz(string fileName);
};
/*-------------------------------------------*/


#endif /* graph_hpp */
