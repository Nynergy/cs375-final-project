#pragma once

#include <vector>
#include "MatrixGraph.h"
#include "ListGraph.h"
#include <queue>

class Astar{

	public:
		double aStar_matrix(Node,Node,MatrixGraph);
		double aStar_list(Node,Node, ListGraph);
		double distance_heuristic(Node, Node);
		double aStar_list(ListNode *, ListNode *, ListGraph);
		double distance_heuristic(ListNode *, ListNode*);
};
