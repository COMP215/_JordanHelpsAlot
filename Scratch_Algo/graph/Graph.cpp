//
//  Graph.cpp
//
//

#include "Graph.hpp"
#include <string>


Node::Node()
{
	data_ = "";
	vect_counter = 0;
	pointer_one = NULL;		
    pointer_two = NULL;
}

Graph::Graph()
{
	array_counter = 0;

}

void Graph::AddToGraph(std:: string data_)
{
	Node* new_node = new Node();

	new_node->data_ = data_;

	graph_vector.insert(graph_vector.begin() + array_counter, new_node);

	array_counter++;
	
	cout << "Node: " << data_ << " added." << endl;

}

void Graph::LinkNodes(string target_node_a, string target_node_b)
{
	
	Node* loc_a;// = new Node();
	Node* loc_b;// = new Node();
	
	for (vector<Node*>::iterator i = graph_vector.begin(); i != graph_vector.end(); ++i)
	{
		Node* temp_node = new Node();
		temp_node = *i;
		if (temp_node->data_ == target_node_a){
			loc_a = temp_node;
		}
	}
	for (vector<Node*>::iterator i = graph_vector.begin(); i != graph_vector.end(); ++i)
	{
		Node* temp_node2 = new Node();
		temp_node2 = *i;
		if (temp_node2->data_ == target_node_b){
			loc_b = temp_node2;
		}
	}
	cout << "loc_a: " << loc_a->data_ << endl << "loc_b: " << loc_b->data_ << endl;
	loc_a->node_vector.push_back(loc_b);	//adds location of b to a's node_vector
	loc_b->node_vector.push_back(loc_a);	//adds location of a to b's node_vector
}

void Graph::isLinkedWith(string base_node_data){
	Node* base_node = NULL;
	Node* temp_node = new Node();
	
	for (vector<Node*>::iterator i = graph_vector.begin(); i != graph_vector.end(); ++i)
	{
		temp_node = *i; // here, i represents the value stored at location i in the vector
		if (temp_node->data_ == base_node_data){
			base_node = temp_node;
			cout << "found the node you wanted! Was it " << base_node->data_ << "?" << endl;
		}
	}
	cout << base_node->data_ << " is connected to: ";

	for (vector<Node*>::iterator i = base_node->node_vector.begin(); i != base_node->node_vector.end(); ++i)
	{
		temp_node = *i;
		cout << temp_node->data_ << " ";
	}
	cout << endl;
}

bool Graph::isBipartite(void){
	vector<Node*> groupA;
	vector<Node*> groupB;
	Node* temp_node = new Node();
	vector<Node*> masterList(graph_vector);

	for (vector<Node*>::iterator i = masterList.begin(); i != masterList.end(); ++i) {
		temp_node = *i;
		groupA.push_back(&temp_node);
		//for (vector<Node*>::iterator i = temp_node->node_vector.begin(); i != temp_node->node_vector.end(); ++i) {
		cout << "heyhey" << endl;
	}
	return true;
}

