#include "MatrixGraph.h"
#include "Astar.h"
#include "Dijkstra.h"
#include "ListGraph.h"
#include <iostream>
#include <random>
#include <chrono>

#define NUM_NODES	10
#define ITERS	5

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
	std::cout << " ---------------------------------- TEST 1: ASTAR DENSE GRAPH WITH ADJACENCY MATRIX ----------------------------------" << std::endl;
	std::cout << "Created " << NUM_NODES << " Nodes.\n" <<  "Running Astar with a dense adjacency matrix-based graph " << ITERS << " times..." << std::endl;
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
	
	std::cout << "Completed testing in a time of " << time << " Milliseconds." << std::endl;
	std::cout << "----------------------------------  END TEST 1 ----------------------------------\n" << std::endl;

	Dijkstra d;

	std::cout << " ---------------------------------- TEST 2: DIJKSTRA DENSE GRAPH WITH ADJACENCY MATRIX ----------------------------------" << std::endl;
	std::cout << "Created " << NUM_NODES << " Nodes.\n" <<  "Running Dijkstra with a dense adjacency matrix-based graph " << ITERS << " times..." << std::endl;
	start = std::chrono::high_resolution_clock::now();

	for(int i = 0; i < ITERS; i++){
		int begin = rand() % NUM_NODES;
		int end = rand() % NUM_NODES;
		while(begin == end){
			end = rand() % NUM_NODES;
		}
		d.dijkstra_matrix(MG->nodes[begin], MG->nodes[end] ,*MG);
	}

	stop = std::chrono::high_resolution_clock::now();
	exec_time = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);


	time = exec_time.count()/ ITERS;
	
	std::cout << "Completed testing in a time of " << time << " Milliseconds." << std::endl;
	std::cout << "----------------------------------  END TEST 2 ----------------------------------\n" << std::endl;


	delete MG;

	ListEdge edges[] = { {0,1,2,10,17}, {0,2,5,8,1}, {0,3,9, 10, 3}, {0,4,3,20,30},{0,5,3,4,1},{0,6,17,10,10},
		{1,0,5,10,17},{1,2,13,9,18},{1,3,12,10,4},{1,4,18,4,2},{1,5,11,16,16},{1,6,20,14,13},
		{2,0,7,8,8},{2,1,3,4,1},{2,3,16,8,1},{2,4,14,3,6},{2,5,19,18,13},{2,6,14,16,2},
		{3,0,2,16,13},{3,1,7,8,1},{3,2,4,1,2},{3,4,10,15,16},{3,5,3,3,13},{3,6,8,10,12},
		{4,0,9,10,11},{4,1,5,10,3},{4,2,8,1,3},{4,3,9,1,4},{4,5,8,19,11},{4,6,20,1,18},
		{5,0,3,4,1},{5,1,9,3,2},{5,2,5,3,5},{5,3,6,6,5},{5,4,8,2,4},{5,6,8,10,2},
		{6,0,7,1,6},{6,1,8,9,9},{6,2,8,8,1},{6,3,4,1,8},{6,4,10,11,18},{6,5,3,4,10}
	};
	int size = 36;
	ListGraph * LG =  new ListGraph(edges, 7, size);

	
	std::cout << " ---------------------------------- TEST 3: ASTAR DENSE GRAPH WITH ADJACENCY LIST ----------------------------------" << std::endl;
	std::cout << "Created " << size << " Nodes.\n" <<  "Running Astar with a dense adjacency list-based graph " << ITERS << " times..." << std::endl;

	start = std::chrono::high_resolution_clock::now();

	a.aStar_list(LG->head[2], LG->head[3], *LG);
	
	stop = std::chrono::high_resolution_clock::now();
	exec_time = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);


	time = exec_time.count()/ ITERS;

	std::cout << "Completed testing in a time of " << time << " Milliseconds." << std::endl;
	std::cout << "----------------------------------  END TEST 3 ----------------------------------\n" << std::endl;


	std::cout << " ---------------------------------- TEST 4: DIJKSTRA DENSE GRAPH WITH ADJACENCY LIST ----------------------------------" << std::endl;
	std::cout << "Created " << size << " Nodes.\n" <<  "Running Dijkstra with a dense adjacency list-based graph " << ITERS << " times..." << std::endl;


	
	start = std::chrono::high_resolution_clock::now();

/*	for(int i = 0; i < ITERS; i++){
		int begin = 0;
		int end = 5;
*/

	d.dijkstra_list(LG->head[0], LG->head[1], *LG);
//	}

	stop = std::chrono::high_resolution_clock::now();
	exec_time = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);


	time = exec_time.count()/ ITERS;

	std::cout << "Completed testing in a time of " << time << " Milliseconds." << std::endl;
	std::cout << "----------------------------------  END TEST 4 ----------------------------------\n" << std::endl;





	return 0;

}
