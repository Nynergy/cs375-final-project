#pragma once

#include "MatrixGraph.h"
#include <queue>
#include <vector>

class Dijkstra {
public:
	double dijkstra_matrix(Node, Node, MatrixGraph);
	double dijkstra_list(Node, Node);
};
