//
//  mushroom.cpp
//
//

#include "mushroom.hpp"
#include <string>
#include <algorithm>


Node::Node()
{
}

Node::Node(string common_name_input, string scientific_name_input, int weight_input, int total_value_input) {
	common_name = common_name_input;
	scientific_name = scientific_name_input;
	weight = weight_input;
	total_value = total_value_input;
	value_per_ounce = total_value / (double)weight;
	cout << "V/Oz. = " << value_per_ounce << endl;
	//cout << "Adding Node: A->" << common_name << ", B->" << scientific_name << ", C->" << weight << ", D->" << total_value << endl;
	
}

Satchel::Satchel(int size_oz)
{
	max_capacity = size_oz;
}

void Satchel::addMushroom(string common_name_input, string scientific_name_input, int weight_input, int total_value_input)
{
	Node* new_shroom;
	new_shroom = new Node(common_name_input, scientific_name_input, weight_input, total_value_input);
	mushrooms_in_satchel.push_back(new_shroom);
	//cout << "Mushrooms in bag: " << mushrooms_in_satchel.size() << endl;
	
	//cout << "Node: " << new_shroom->common_name << " added." << endl;
}

void Satchel::displaySatchel(void){
	Node* temp_node;
	for (vector<Node*>::iterator i = mushrooms_in_satchel.begin(); i != mushrooms_in_satchel.end(); ++i)
	{
		temp_node = *i;
		cout << "Found Mushroom: " << temp_node->common_name << endl;
	}
}

/*
void Satchel::optimizeSatchel(void){
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
			visited_vertices.push_back(smallest_edge->vertB_loc); }
		else {
			visited_vertices.push_back(smallest_edge->vertA_loc); }
	}
*/
