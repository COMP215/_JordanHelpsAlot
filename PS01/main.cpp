
#include <fstream>
#include "Graph.hpp"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	Graph N;	
	Graph* newN;
	Graph* newK;

	N.AddVertex('A');
	N.AddVertex('B');
	N.AddVertex('C');
	N.AddVertex('D');
	N.AddVertex('E');
	N.AddVertex('F');
	N.AddVertex('G');


	N.AddEdge('A', 'B', 2);
	N.AddEdge('A', 'C', 3);
	N.AddEdge('A', 'D', 4);
	N.AddEdge('B', 'C', 9);
	N.AddEdge('B', 'E', 3);
	N.AddEdge('C', 'E', 1);
	N.AddEdge('C', 'F', 6);
	N.AddEdge('E', 'F', 8);
	N.AddEdge('F', 'D', 7);
	N.AddEdge('F', 'G', 9);


	newK = N.Kruskal();
	/*
	newN = N.PrimMST();
	newN->DisplayEdges();
	N.ToGraphviz("graph1.dot");
	newN->ToGraphviz("graph2.dot");
	*/

	
	
	

	return 0;
}
