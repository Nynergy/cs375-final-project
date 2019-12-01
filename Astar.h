#pragma once

#include <vector>
#include "MatrixGraph.h"
#include "ListGraph.h"
#include <queue>

class Astar{

	public:
		double aStar_matrix(Node,Node,MatrixGraph);
		double distance_heuristic(Node, Node);
		double aStar_list(ListNode *, ListNode *, ListGraph*);
		
		//Euclidean
		double distance_heuristic(ListNode *, ListNode*);
		double Astar1(Node,Node,MatrixGraph);
		double Astar2(Node,Node,MatrixGraph);
		double Astar3(Node,Node,MatrixGraph);
		double manhattan(Node, Node);
		double diagonal(Node, Node);

};
