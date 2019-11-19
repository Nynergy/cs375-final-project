#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(std::vector<Node> new_nodes) {
	this->nodes = new_nodes;
	this->num_nodes = this->nodes.size()
	this->sortNodes();

	// TODO: Create new matrix of size num_nodes

	// Populate the matrix
	this->setAdjacents();
}

MatrixGraph::~MatrixGraph() {
	// TODO: Free each row

	// TODO: Free the initial column
}

void MatrixGraph::sortNodes() {
	// TODO: Sort nodes by increasing id
}

void MatrixGraph::setAdjacents() {
	// TODO: Iterate through each node and their adjacencies
}
