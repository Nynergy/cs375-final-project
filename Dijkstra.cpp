#include "Dijkstra.h"
#include "PriorityQueue.h"
#include <unordered_map>

// To be used with a matrix graph
// MatrixGraph implementation will run in O(k*n), where:
// 	k = # of nodes extracted from the frontier, and
// 	n = # of nodes in the MatrixGraph
// Keep in mind that worst case runtime occurs when either:
// 	The destination node is not connected to the source node, or
// 	the shortest path between start and dest traverses every node
// In this case, k = n, so runtime complexity is O(n^2)

double Dijkstra::dijkstra_matrix(Node start, Node dest, MatrixGraph MG) {
	// <id_1, id_2>
	std::unordered_map<int, int> came_from;
	// <id, value>
	std::unordered_map<int, double> cost_so_far;

	// Create a fontier queue and insert start node
	PriorityQueue frontier;
	frontier.put(0, start.id);

	// Initialize rotating variables
	came_from[start.id] = start.id;
	cost_so_far[start.id] = 0;
	Node current;
	Node next;
	int distance;
	double new_cost;
	double priority;

	// Enter search loop
	while(!frontier.empty()) {
		// Extract priority node
		current = MG.nodes[frontier.get()];
		
		// Check if destination has been reached
		if(current.id == dest.id) { break; }

		// Loop through all nodes and update nodes adjacent to current
		for(int i = 0; i < MG.num_nodes; i++) {
			// If node with id 'i' is adjacent to current
			if(current.id != i && MG.matrix[current.id][i] > 0) {
				distance = MG.matrix[current.id][i];
				new_cost = cost_so_far[current.id] + distance;
				// If Node not in map OR new_cost < current cost
				if(cost_so_far.find(i) == cost_so_far.end() || new_cost < cost_so_far[i]) {
					// Update rotating variables
					cost_so_far[i] = new_cost;
					priority = new_cost;
					frontier.put(priority, i);
					came_from[i] = current.id;
				}
			}
		}
	}

	return cost_so_far[dest.id];
}

// To be used with a list graph

double Dijkstra::dijkstra_list(Node start, Node dest) {
	return 0;
}
