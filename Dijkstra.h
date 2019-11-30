#pragma once

#include "MatrixGraph.h"
#include "ListGraph.h"
#include <queue>
#include <vector>

class Dijkstra {
public:
	double dijkstra_matrix(Node, Node, MatrixGraph);
	double dijkstra_list(ListNode*, ListNode*, ListGraph);
};
