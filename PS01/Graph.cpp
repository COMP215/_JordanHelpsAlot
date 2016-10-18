//
//  Graph.cpp
//
//

#include "Graph.hpp"
#include <string>
#include <algorithm>
#include <fstream>


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
	
	//cout << "Node: " << vertex << " added." << endl;

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
	//cout << "loc_a: " << loc_a->vertex << endl << "loc_b: " << loc_b->vertex << endl;
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
			//cout << "found the node you wanted! Was it " << base_node->vertex << "?" << endl;
		}
	}
	//cout << base_node->vertex << " is connected to: ";

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

Graph* Graph::PrimMST(void){
	//vector<Node*> graph_vector;
	//vector<Edge*> master_edge_list;
	Graph* newGraph;
	Node* startPos = graph_vector.at(0);
	vector<Edge*> official_moves;
	vector<Edge*> potential_moves;
	vector<Node*> visited_vertices;
	Edge* temp_edge;
	Edge* temp_edge2;
	Node* temp_node;
	int temp_counter = 0;
	
	visited_vertices.push_back(startPos);
	
	for (vector<Edge*>::iterator i = master_edge_list.begin(); i != master_edge_list.end(); ++i)
	{
		temp_edge = *i;
		//If the node you wanted was in A position of an edge
		if (temp_edge->vertA_loc == startPos) { 
			potential_moves.push_back(temp_edge);
		}
		//If the node you wanted was in B position of an edge
		else if (temp_edge->vertB_loc == startPos) { 
			potential_moves.push_back(temp_edge);
		}
	}
	
	Edge* smallest_edge;
	if (!potential_moves.empty()){
		smallest_edge = potential_moves.at(0);
		for (vector<Edge*>::iterator i = potential_moves.begin(); i != potential_moves.end(); ++i)
		{
			temp_edge = *i;
			if (temp_edge->weight < smallest_edge->weight) { 
				smallest_edge = temp_edge; 
			}
		}
		official_moves.push_back(smallest_edge);
		
		if (find(visited_vertices.begin(), visited_vertices.end(), smallest_edge->vertA_loc) != visited_vertices.end()) { 
			visited_vertices.push_back(smallest_edge->vertB_loc); 
		}
		else {
			visited_vertices.push_back(smallest_edge->vertA_loc); 
		}

		while (visited_vertices.size() < graph_vector.size())
		{
			potential_moves.clear();

			//Update Potential Moves

			for (vector<Node*>::iterator i = visited_vertices.begin(); i != visited_vertices.end(); ++i)
			{ 
				temp_node = *i;
				for (vector<Edge*>::iterator j = master_edge_list.begin(); j != master_edge_list.end(); ++j)
				{
					temp_edge = *j;
					if (temp_edge->vertA_loc == temp_node) {
						if (find(visited_vertices.begin(), visited_vertices.end(), temp_edge->vertB_loc) != visited_vertices.end()) {
						}
						else
							potential_moves.push_back(temp_edge);
					}
					else if (temp_edge->vertB_loc == temp_node) {
						if (find(visited_vertices.begin(), visited_vertices.end(), temp_edge->vertA_loc) != visited_vertices.end()) {
						}
						else
							potential_moves.push_back(temp_edge);
					}

				}
						
			}
						
			//Remove redundancies from Potential Moves
			
			for (vector<Edge*>::iterator i = official_moves.begin(); i != official_moves.end(); ++i)
			{
				temp_edge = *i;

				for (vector<Edge*>::iterator j = potential_moves.begin(); j != potential_moves.end(); ++j)
				{
					temp_edge2 = *j;

					if (temp_edge == temp_edge2){
						potential_moves.erase(potential_moves.begin() + temp_counter);
					}
					temp_counter++;
				}

				temp_counter=0;
			}


			for (vector<Edge*>::iterator i = potential_moves.begin(); i != potential_moves.end(); ++i)
			{
				temp_edge = *i;
				cout << "potential_moves has: " << temp_edge->vertA << " - " << temp_edge->vertB << endl;
			}


			smallest_edge = potential_moves.at(0);
			for (vector<Edge*>::iterator i = potential_moves.begin(); i != potential_moves.end(); ++i)
			{
				temp_edge = *i;
				if (temp_edge->weight < smallest_edge->weight) { 
					smallest_edge = temp_edge; 
				}
			}

			official_moves.push_back(smallest_edge);

			if (find(visited_vertices.begin(), visited_vertices.end(), smallest_edge->vertA_loc) != visited_vertices.end()) { 
				visited_vertices.push_back(smallest_edge->vertB_loc); 
			}
			else {
				visited_vertices.push_back(smallest_edge->vertA_loc); 
			}
			
			cout << visited_vertices.size() << " - " << master_edge_list.size() << endl;

		}

	cout << "-- Graph is Finished --" << endl;
	
	}
	
	newGraph = new Graph();
	for (vector<Node*>::iterator i = visited_vertices.begin(); i != visited_vertices.end(); ++i)
	{
		temp_node = *i;
		newGraph->AddVertex(temp_node->vertex);
	}

	for (vector<Edge*>::iterator i = official_moves.begin(); i != official_moves.end(); ++i)
	{
		temp_edge = *i;
		newGraph->AddEdge(temp_edge->vertA, temp_edge->vertB, temp_edge->weight);
	}

	return newGraph;
}


Graph* Graph::Kruskal(void){
	Node* temp_node;
	Edge* smallest_edge;
	Edge* temp_edge;
	vector<Node*> visited_verts;
	vector<Node*> alien_verts;
	vector<Edge*> visited_edges;
	vector<Edge*> alien_edges;
	smallest_edge = master_edge_list.at(0);
	
	for (vector<Node*>::iterator i = graph_vector.begin(); i != graph_vector.end(); ++i)
	{
		temp_node = *i;
		alien_verts.push_back(temp_node);
	}
	
	for (vector<Edge*>::iterator i = master_edge_list.begin(); i != master_edge_list.end(); ++i)
	{
		temp_edge = *i;
		alien_edges.push_back(temp_edge);
	}
	
	for (vector<Edge*>::iterator i = alien_edges.begin(); i != alien_edges.end(); ++i)
	{
		temp_edge = *i;
		if (temp_edge->weight < smallest_edge->weight) { 
			smallest_edge = temp_edge; 
		}
	}	
	cout << "Smallest Edge: " << smallest_edge->vertA << smallest_edge->vertB << " of weight-" << smallest_edge->weight << endl;
	
	Graph* NewG;
	NewG = new Graph;
	return NewG;
}


void Graph::DisplayEdges(void){
	Edge* temp_edge;
	for (vector<Edge*>::iterator i = master_edge_list.begin(); i != master_edge_list.end(); ++i)
	{
		temp_edge = *i;
		cout << "Found Edge: Between " << temp_edge->vertA << " and " << temp_edge->vertB << " --> Weight = " << temp_edge->weight << endl;
	}
}

void Graph::ToGraphviz(string fileName)
// Reads in a graph and prints out the graph into a DOT file used to visualize the graph
// Needs a graph object for this method to be called, does not take anything in as an argument
// Creates a new DOT file in the same directory as this program is in.
{
	Edge* temp_edge;		// An Edge pointer used in the for loop
	ofstream file_write;	// A file stream used to write to a new file

	file_write.open(fileName);
	file_write << "digraph G {" << endl << "\trankdir=LR;" << endl;
	for (vector<Edge*>::iterator i = master_edge_list.begin(); i != master_edge_list.end(); ++i)
	{
		temp_edge = *i;

		file_write << "\t" << temp_edge->vertA << " -> " << temp_edge->vertB << " [label=" << temp_edge->weight << "]" << endl;

	}
	file_write << "}" << endl;
	file_write.close();

	cout << "Just made a new DOT file named: newGraph.dot" << endl;
}
