#pragma once

#include "Node.h"

// Graph Implemented with Adjacency Matrix
// This requires a pre-made vector of Nodes, each with a vector of adjacent Nodes
class MatrixGraph {
public:
	int num_nodes;
	std::vector<Node> nodes;
	std::vector<std::vector<int>> matrix;
		// Each element will be 0 (non-adjacent) or > 0 (adjacent)
		// Matrix will be formatted like matrix[a][b], where
		// a = the id of the initial node and
		// b = the id of the node being checked for adjacency/weight
	MatrixGraph(std::vector<Node> new_nodes);
	~MatrixGraph();
private:
	void sortNodes();
	void quickSort(int left, int right);
	void setAdjacents();
};
