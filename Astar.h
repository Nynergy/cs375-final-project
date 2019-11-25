#pragma once

#include <vector>
#include "MatrixGraph.h"
#include <queue>

class Astar{

	public:
		double aStar_matrix(Node,Node,MatrixGraph);
		double aStar_list(Node,Node);
		double distance_heuristic(Node, Node);

};
