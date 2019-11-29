#include "MatrixGraph.h"
#include "Astar.h"
#include <iostream>
#include <random>
#include <chrono>

#define NUM_NODES	10
#define ITERS	10

int main() {
	
	//Create DenseGraph test
	
	//Create Nodes
	
	std::vector<Node> nodes;
	for(int i = 0; i < (NUM_NODES/2); i++){
		int x = rand() % 500 + 500;
		int y = rand() % 500 + 500;
		nodes.push_back(Node(x,y, i));
	}
	for(int i = (NUM_NODES/2); i < NUM_NODES; i++){
		int x = rand() % 500 + 100;
		int y = rand() % 500 + 100;
		nodes.push_back(Node(x,y,i));
	}

	//Nodes Created
	//
	//Set Every Node to have an edge to every other node
	
	for(int i = 0; i < NUM_NODES; i++){
		for(int j = 0; j < NUM_NODES; j++){
			if(j != i){
				int weight = rand() % 100 + 1;
				nodes[i].addEdge(nodes[j], weight);
			}
		}
	}

	//Edges set
	//
	//Make Graph
	
	MatrixGraph * MG = new MatrixGraph(nodes);

	//Test Algorithms
	
	Astar a;
	auto start = std::chrono::high_resolution_clock::now();

	for(int i = 0; i < ITERS; i++){
		int begin = rand() % NUM_NODES;
		int end = rand() % NUM_NODES;
		while(begin == end){
			end = rand() % NUM_NODES;
		}
		a.aStar_matrix(MG->nodes[begin], MG->nodes[end] ,*MG);
	}

	auto stop = std::chrono::high_resolution_clock::now();
	auto exec_time = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

	auto time = exec_time.count()/ ITERS;
	
	std::cout << time << std::endl;

	delete MG;

	return 0;

}
