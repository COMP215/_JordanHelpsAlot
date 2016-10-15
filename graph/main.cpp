
#include <fstream>
#include "Graph.hpp"
#include <iostream>
#include <string>

int main()
{

	
	Graph g;
	Graph* newG;

	g.AddVertex('1');
	g.AddVertex('2');
	g.AddVertex('3');
	g.AddVertex('4');
	g.AddVertex('5');
	g.AddVertex('6');
	g.AddVertex('7');
	g.AddVertex('8');
	g.AddVertex('9');
	
	g.AddEdge('7', '4');
	g.AddEdge('3', '6', 8);
	g.AddEdge('1', '9', 2);
	g.AddEdge('8', '9');
	g.AddEdge('2', '7', 4);
	
	g.DisplayEdges();
	
	newG = g.PrimMST();
	
	
	

	return 0;
}
