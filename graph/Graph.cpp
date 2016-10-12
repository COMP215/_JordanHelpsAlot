//
//  Graph.cpp
//
//

#include "Graph.hpp"
#include <string>


Node::Node()
{
}

Edge::Edge()
{
}

Edge::Edge( Node* A, Node* B )
{
	weight = 0;
	vertA_loc = A;
	vertB_loc = B;
	vertA = vertA_loc->vertex;
	vertB = vertB_loc->vertex;
	//cout << "New Edge created between " << vertA << " and " << vertB << " (weightless)" << endl;
	
}	

Edge::Edge( Node* A, Node* B, int weight_value_passed )
{
	weight = weight_value_passed;
	vertA_loc = A;
	vertB_loc = B;
	vertA = vertA_loc->vertex;
	vertB = vertB_loc->vertex;
	//cout << "New Edge created between " << vertA << " and " << vertB << " --> Weight = " << weight << endl;
	
}	

Graph::Graph()
{
}

void Graph::AddVertex(char vertex)
{
	Node* new_node = new Node();
	// Eventually need a way to check if vertex already exists
	new_node->vertex = vertex;

	//graph_vector.insert(graph_vector.begin() + array_counter, new_node);
	graph_vector.push_back(new_node);
	
	cout << "Node: " << vertex << " added." << endl;

}

void Graph::LinkNodes(char target_node_a, char target_node_b)
{
	
	Node* loc_a;
	Node* loc_b;
	Node* temp_node;
	Node* temp_node2;
	
	for (vector<Node*>::iterator i = graph_vector.begin(); i != graph_vector.end(); ++i)
	{
		temp_node = *i;
		if (temp_node->vertex == target_node_a){
			loc_a = temp_node;
		}
	}
	for (vector<Node*>::iterator i = graph_vector.begin(); i != graph_vector.end(); ++i)
	{
		temp_node2 = *i;
		if (temp_node2->vertex == target_node_b){
			loc_b = temp_node2;
		}
	}
	cout << "loc_a: " << loc_a->vertex << endl << "loc_b: " << loc_b->vertex << endl;
	loc_a->node_vector.push_back(loc_b);	//adds location of b to a's node_vector
	loc_b->node_vector.push_back(loc_a);	//adds location of a to b's node_vector
}

void Graph::isLinkedWith(char base_node_vertex){
	Node* base_node = NULL;
	Node* temp_node = new Node();
	
	for (vector<Node*>::iterator i = graph_vector.begin(); i != graph_vector.end(); ++i)
	{
		temp_node = *i; // here, i represents the value stored at location i in the vector
		if (temp_node->vertex == base_node_vertex){
			base_node = temp_node;
			cout << "found the node you wanted! Was it " << base_node->vertex << "?" << endl;
		}
	}
	cout << base_node->vertex << " is connected to: ";

	for (vector<Node*>::iterator i = base_node->node_vector.begin(); i != base_node->node_vector.end(); ++i)
	{
		temp_node = *i;
		cout << temp_node->vertex << " ";
	}
	cout << endl;
}

void Graph::AddEdge(char source, char target){
	Node* loc_a;
	Node* loc_b;
	Node* temp_node;
	Node* temp_node2;
	Edge* new_edge_loc;
	for (vector<Node*>::iterator i = graph_vector.begin(); i != graph_vector.end(); ++i)
	{
		temp_node = *i;
		if (temp_node->vertex == source){
			loc_a = temp_node;
		}
	}
	for (vector<Node*>::iterator i = graph_vector.begin(); i != graph_vector.end(); ++i)
	{
		temp_node2 = *i;
		if (temp_node2->vertex == target){
			loc_b = temp_node2;
		}
	}
	new_edge_loc = new Edge(loc_a, loc_b);
	master_edge_list.push_back(new_edge_loc);
}

void Graph::AddEdge(char source, char target, int weight){
	Node* loc_a;
	Node* loc_b;
	Node* temp_node;
	Node* temp_node2;
	Edge* new_edge_loc;
	for (vector<Node*>::iterator i = graph_vector.begin(); i != graph_vector.end(); ++i)
	{
		temp_node = *i;
		if (temp_node->vertex == source){
			loc_a = temp_node;
		}
	}
	for (vector<Node*>::iterator i = graph_vector.begin(); i != graph_vector.end(); ++i)
	{
		temp_node2 = *i;
		if (temp_node2->vertex == target){
			loc_b = temp_node2;
		}
	}
	new_edge_loc = new Edge(loc_a, loc_b, weight);
	master_edge_list.push_back(new_edge_loc);
}


void Graph::DisplayEdges(void){
	Edge* temp_edge;
	for (vector<Edge*>::iterator i = master_edge_list.begin(); i != master_edge_list.end(); ++i)
	{
		temp_edge = *i;
		cout << "Found Edge: Between " << temp_edge->vertA << " and " << temp_edge->vertB << " --> Weight = " << temp_edge->weight << endl;
	}
}
