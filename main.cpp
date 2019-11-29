#include "MatrixGraph.h"
#include "ListGraph.h"
#include "ListEdge.h"
#include "Astar.h"
#include <iostream>

int main() {
	Node one(1,1, 0);
       	Node two(3,4, 1);
	Node three(3,3, 2);

	one.addEdge(three, 10);
	one.addEdge(two, 2);
	two.addEdge(three,1);
	std::vector<Node> nodes;
	nodes.push_back(one);
	nodes.push_back(two);
	nodes.push_back(three);
	MatrixGraph * mat_graph = new MatrixGraph(nodes);
	for(int k = 0; k < nodes.size(); k++){
		std::cout << k << " id " << nodes[k].id << std::endl;
	}

	Astar a;
	double d = a.aStar_matrix(one, three, *mat_graph);
	std::cout << d << std::endl;

	delete mat_graph;

	ListEdge edges[] = {{0,1,2},{0,2,4},{1,4,3},{2,3,2},{3,1,4},{4,3,3}};
	int N = sizeof(edges);
	int n = sizeof(edges)/sizeof(edges[0]);
	ListGraph adjList(edges, n, N);
	adjList.printGraph();

	return 0;
}
