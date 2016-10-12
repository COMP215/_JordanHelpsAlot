
#include <fstream>
#include "Graph.hpp"
#include <iostream>
#include <string>

int main()
{

	Graph g;

	g.AddToGraph("Node1");
	g.AddToGraph("Node2");
	g.AddToGraph("Node3");
	g.AddToGraph("Node4");
	g.AddToGraph("Node5");
	g.AddToGraph("Node6");
	g.AddToGraph("Node7");
	g.AddToGraph("Node8");
	g.AddToGraph("Node9");


	g.LinkNodes("Node5", "Node3");

	return 0;
}