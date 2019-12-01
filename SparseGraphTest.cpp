#include "MatrixGraph.h"
#include "Astar.h"
#include "Dijkstra.h"
#include <iostream>
#include <random>
#include <chrono>

#define NUM_NODES	20
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
			j++;
		}
	}

	//Edges set
	//
	//Make Graph
	
	MatrixGraph * MG = new MatrixGraph(nodes);

	//Test Algorithms
	
	Astar a;
	std::cout << " ---------------------------------- TEST 5: ASTAR SPARSE GRAPH WITH ADJACENCY MATRIX ----------------------------------" << std::endl;
	std::cout << "Created " << NUM_NODES << " Nodes.\n" <<  "Running Astar with a sparse adjacency matrix-based graph " << ITERS << " times..." << std::endl;

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
	std::cout << "----------------------------------  END TEST 5 ----------------------------------\n" << std::endl;

	
	Dijkstra d;

	std::cout << " ---------------------------------- TEST 6: DIJKSTRA SPARSE GRAPH WITH ADJACENCY MATRIX ----------------------------------" << std::endl;
	std::cout << "Created " << NUM_NODES << " Nodes.\n" <<  "Running Dijkstra with a sparse adjacency matrix-based graph " << ITERS << " times..." << std::endl;
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
	std::cout << "----------------------------------  END TEST 6 ----------------------------------\n" << std::endl;

	ListNode * arr[NUM_NODES];

	for(int i = 0; i < NUM_NODES; i++){
		int x = rand() % 100;
		int y = rand() % 100;
		arr[i] = new ListNode(i,x,y);
	}

	for(int i = 0; i < NUM_NODES; i++){
		ListNode * n = arr[i];
		for(int j = 0; j < NUM_NODES; j++){
			if(i != j){
				n->next = new ListNode(arr[j]->id, arr[j]->x, arr[j]->y);
				n->nextWeight = rand() % 100;
				n = n->next;
			}
		}
	}
	ListGraph * LG = new ListGraph(NUM_NODES, arr);

	

	std::cout << " ---------------------------------- TEST 7: ASTAR SPARSE GRAPH WITH ADJACENCY LIST ----------------------------------" << std::endl;
	std::cout << "Created " << NUM_NODES << " Nodes.\n" <<  "Running Astar with a sparse adjacency list-based graph " << (ITERS * 10) << " times..." << std::endl;
	
	start = std::chrono::high_resolution_clock::now();
	for(int i = 0; i < (ITERS * 10); i++){
		int start = rand() % NUM_NODES;
		int end = rand() % NUM_NODES;
		a.aStar_list(LG->nodes[start], LG->nodes[end], LG);
	}
	
	stop = std::chrono::high_resolution_clock::now();
	exec_time = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);


	time = exec_time.count()/ ITERS;



	std::cout << "Completed testing in a time of " << time << " Milliseconds." << std::endl;
	std::cout << "----------------------------------  END TEST 7 ----------------------------------\n" << std::endl;

	std::cout << " ---------------------------------- TEST 8: DIJKSTRA SPARSE GRAPH WITH ADJACENCY LIST ----------------------------------" << std::endl;
	std::cout << "Created " << NUM_NODES << " Nodes.\n" <<  "Running Dijkstra with a sparse adjacency list-based graph " << (ITERS *10) << " times..." << std::endl;

	
	start = std::chrono::high_resolution_clock::now();
	for(int i = 0; i<( ITERS * 10); i++){
		int start = rand() % NUM_NODES;
		int end = rand() % NUM_NODES;
		d.dijkstra_list(LG->nodes[start], LG->nodes[end], LG);
	}
	stop = std::chrono::high_resolution_clock::now();
	exec_time = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);


	time = exec_time.count()/ ITERS;


	
	std::cout << "Completed testing in a time of " << time << " Milliseconds." << std::endl;
	std::cout << "----------------------------------  END TEST 8 ----------------------------------\n" << std::endl;


	std::cout << " ---------------------------------- TEST 9: ASTAR EUCLIDEAN DISTANCE HEURISTIC ----------------------------------" << std::endl;
	std::cout << "Created " << NUM_NODES << " Nodes.\n" <<  "Running Astar using Euclidean distance as a heuristic " << ITERS << " times..." << std::endl;
	start = std::chrono::high_resolution_clock::now();

	for(int i = 0; i < ITERS; i++){
		int begin = rand() % NUM_NODES;
		int end = rand() % NUM_NODES;
		while(begin == end){
			end = rand() % NUM_NODES;
		}
		a.Astar1(MG->nodes[begin], MG->nodes[end] ,*MG);
	}

	stop = std::chrono::high_resolution_clock::now();
	exec_time = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);


	time = exec_time.count()/ ITERS;
	
	std::cout << "Completed testing in a time of " << time << " Milliseconds." << std::endl;
	std::cout << "----------------------------------  END TEST 9 ----------------------------------\n" << std::endl;


	std::cout << " ---------------------------------- TEST 10: ASTAR MANHATTAN DISTANCE HEURISTIC ----------------------------------" << std::endl;
	std::cout << "Created " << NUM_NODES << " Nodes.\n" <<  "Running Astar using Manhattan distance as a heuristic " << ITERS << " times..." << std::endl;
	start = std::chrono::high_resolution_clock::now();

	for(int i = 0; i < ITERS; i++){
		int begin = rand() % NUM_NODES;
		int end = rand() % NUM_NODES;
		while(begin == end){
			end = rand() % NUM_NODES;
		}
		a.Astar2(MG->nodes[begin], MG->nodes[end] ,*MG);
	}

	stop = std::chrono::high_resolution_clock::now();
	exec_time = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);


	time = exec_time.count()/ ITERS;
	
	std::cout << "Completed testing in a time of " << time << " Milliseconds." << std::endl;
	std::cout << "----------------------------------  END TEST 10 ----------------------------------\n" << std::endl;


	std::cout << " ---------------------------------- TEST 11: ASTAR DIAGONAL DISTANCE HEURISTIC ----------------------------------" << std::endl;
	std::cout << "Created " << NUM_NODES << " Nodes.\n" <<  "Running Astar using Diagonal distance as a heuristic " << ITERS << " times..." << std::endl;
	start = std::chrono::high_resolution_clock::now();

	for(int i = 0; i < ITERS; i++){
		int begin = rand() % NUM_NODES;
		int end = rand() % NUM_NODES;
		while(begin == end){
			end = rand() % NUM_NODES;
		}
		a.Astar1(MG->nodes[begin], MG->nodes[end] ,*MG);
	}

	stop = std::chrono::high_resolution_clock::now();
	exec_time = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);


	time = exec_time.count()/ ITERS;
	
	std::cout << "Completed testing in a time of " << time << " Milliseconds." << std::endl;
	std::cout << "----------------------------------  END TEST 11 ----------------------------------\n" << std::endl;




	delete MG;

	return 0;

}
