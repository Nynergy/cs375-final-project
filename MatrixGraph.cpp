#include "MatrixGraph.h"
#include <iostream>

MatrixGraph::MatrixGraph(std::vector<Node> new_nodes) {
	this->nodes = new_nodes;
	this->num_nodes = this->nodes.size();
	this->sortNodes();

	// Create new matrix of size num_nodes
	for(int i = 0; i < this->num_nodes; i++) {
		std::vector<int> new_row;
		for(int j = 0; j < this->num_nodes; j++) {
			new_row.push_back(0);
		}

		this->matrix.push_back(new_row);
	}

	// Populate the matrix
	this->setAdjacents();
}

MatrixGraph::~MatrixGraph() {}

void MatrixGraph::sortNodes() {
	// Sort nodes by increasing id
	this->quickSort(0, this->num_nodes - 1);
}

void MatrixGraph::quickSort(int left, int right) {
	int orig_left = left;
	int orig_right = right;
	Node temp;
	Node pivot = this->nodes[(left + right) / 2];

	// Partition
	while(left <= right) {
		while(this->nodes[left].id < pivot.id) {
			left++;
		}
		
		while(this->nodes[right].id > pivot.id) {
			right--;
		}

		if(left <= right) {
			temp = this->nodes[left];
			this->nodes[left] = this->nodes[right];
			this->nodes[right] = temp;
			left++;
			right--;
		}
	}

	// Recursion Cases
	if(orig_left < right) {
		this->quickSort(orig_left, right);
	}

	if(left < orig_right) {
		this->quickSort(left, orig_right);
	}
}

void MatrixGraph::setAdjacents() {
	// Iterate through each node and their adjacencies
	for(auto i : this->nodes) {
		for(auto j : i.adj) {
			this->matrix[i.id][j.first.id] = j.second;
		}
	}
}
