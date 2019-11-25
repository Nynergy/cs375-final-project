#pragma once

#include <vector>
#include "MatrixGraph.cpp"
#include <queue>

class Astar{

	public:
		auto aStar_matrix(Node,Node,MatrixGraph);
		auto aStar_list(Node,Node);
		double distance_heuristic(Node, Node);

};
