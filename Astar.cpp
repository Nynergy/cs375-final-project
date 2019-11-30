#include "Astar.h"
#include <unordered_map>
#include <math.h>
#include <iostream>
#include "PriorityQueue.h"

//To be used with a matrix

double Astar::aStar_matrix(Node start, Node dest, MatrixGraph MG){
	//<id1, id2>>
	std::unordered_map<int, int> came_from;
	//<id, value>
	std::unordered_map<int, double> cost_so_far;

	PriorityQueue frontier;
	frontier.put(0, start.id);
	
	came_from[start.id] = start.id;
	cost_so_far[start.id] = 0;
	Node current;
	Node next;
	double new_cost;
	double priority;

	while(!frontier.empty()){

		current = MG.nodes[frontier.get()];

		if(current.id == dest.id) break;

		for(auto i = 0; i < MG.num_nodes; i++){
			if(current.id != i && MG.matrix[current.id][i] > 0){
				//Node next = MG.nodes[i];
				int distance = MG.matrix[current.id][i];
				new_cost = cost_so_far[current.id] + distance;
				//If the Node is not in the unordered map OR if the new_cost is smaller than its current cost
				if(cost_so_far.find(i) == cost_so_far.end() || new_cost < cost_so_far[i]){
					cost_so_far[i] = new_cost;
					priority = new_cost + distance_heuristic(MG.nodes[i], dest);
					frontier.put(priority, i);
					came_from[i] = current.id;
				}
			}	
		}
	}	
	return cost_so_far[dest.id];

	}

//List Astar
double Astar::aStar_list(ListNode * start, ListNode * dest, ListGraph LG){
	
	//<id1, id2>>:
	std::unordered_map<int, int> came_from;
	//<id, value>
	std::unordered_map<int, double> cost_so_far;

	PriorityQueue frontier;
	frontier.put(0, start->id);
	
	came_from[start->id] = start->id;
	cost_so_far[start->id] = 0;
	ListNode * current;
	ListNode * next;
	double new_cost;
	double priority;

	while(!frontier.empty()){
		std::cout << "EXTRACTING FROM FRONTIER..." << std::endl;

		current = LG.head[frontier.get()];

		if(current->id == dest->id) break;
		/* TODO: Trying to find current->next segfaults */
		ListNode * temp = current->next;
		std::cout << "TEMP SET" << std::endl;
		if(temp == nullptr) {
			std::cout << "NULLPTR FOUND" << std::endl;
		}
		while(temp != nullptr){
			std::cout << "NEXT NODE..." << std::endl;
			int distance = temp->weight;
			new_cost = cost_so_far[current->id] + distance;
				//If the Node is not in the unordered map OR if the new_cost is smaller than its current cost
			if(cost_so_far.find(temp->id) == cost_so_far.end() || new_cost < cost_so_far[temp->id]){
				cost_so_far[temp->id] = new_cost;
				priority = new_cost + distance_heuristic(temp, dest);
							//MG.nodes[i], dest);
				frontier.put(priority, temp->id);
				came_from[temp->id] = current->id;
			}	
		}
	}	
	return cost_so_far[dest->id];

}

double Astar::distance_heuristic(ListNode * a, ListNode * b){
	double a_dis = pow( ( (a->x * a->x) + (a->y * a->y) ), .5);
	double b_dis = pow( ( (b->x * b->x) + (b->y * b->y) ), .5);

	return b_dis - a_dis;
	return 1;
}

double Astar::distance_heuristic(Node a, Node b){
	double a_dis = pow( ( (a.x * a.x) + (a.y * a.y) ), .5);
	double b_dis = pow( ( (b.x * b.x) + (b.y * b.y) ), .5);
	

	return b_dis - a_dis;

}

double Astar::Astar1(Node start, Node dest, MatrixGraph MG){
	//<id1, id2>>
	std::unordered_map<int, int> came_from;
	//<id, value>
	std::unordered_map<int, double> cost_so_far;

	PriorityQueue frontier;
	frontier.put(0, start.id);
	
	came_from[start.id] = start.id;
	cost_so_far[start.id] = 0;
	Node current;
	Node next;
	double new_cost;
	double priority;

	while(!frontier.empty()){

		current = MG.nodes[frontier.get()];

		if(current.id == dest.id) break;

		for(auto i = 0; i < MG.num_nodes; i++){
			if(current.id != i && MG.matrix[current.id][i] > 0){
				//Node next = MG.nodes[i];
				int distance = MG.matrix[current.id][i];
				new_cost = cost_so_far[current.id] + distance;
				//If the Node is not in the unordered map OR if the new_cost is smaller than its current cost
				if(cost_so_far.find(i) == cost_so_far.end() || new_cost < cost_so_far[i]){
					cost_so_far[i] = new_cost;
					priority = new_cost + distance_heuristic(MG.nodes[i], dest);
					frontier.put(priority, i);
					came_from[i] = current.id;
				}
			}	
		}
	}	
	return cost_so_far[dest.id];

}

double Astar::Astar2(Node start, Node dest, MatrixGraph MG){
	//<id1, id2>>
	std::unordered_map<int, int> came_from;
	//<id, value>
	std::unordered_map<int, double> cost_so_far;

	PriorityQueue frontier;
	frontier.put(0, start.id);
	
	came_from[start.id] = start.id;
	cost_so_far[start.id] = 0;
	Node current;
	Node next;
	double new_cost;
	double priority;

	while(!frontier.empty()){

		current = MG.nodes[frontier.get()];

		if(current.id == dest.id) break;

		for(auto i = 0; i < MG.num_nodes; i++){
			if(current.id != i && MG.matrix[current.id][i] > 0){
				//Node next = MG.nodes[i];
				int distance = MG.matrix[current.id][i];
				new_cost = cost_so_far[current.id] + distance;
				//If the Node is not in the unordered map OR if the new_cost is smaller than its current cost
				if(cost_so_far.find(i) == cost_so_far.end() || new_cost < cost_so_far[i]){
					cost_so_far[i] = new_cost;
					priority = new_cost + manhattan(MG.nodes[i], dest);
					frontier.put(priority, i);
					came_from[i] = current.id;
				}
			}	
		}
	}	
	return cost_so_far[dest.id];

	}

double Astar::Astar3(Node start, Node dest, MatrixGraph MG){
	//<id1, id2>>
	std::unordered_map<int, int> came_from;
	//<id, value>
	std::unordered_map<int, double> cost_so_far;

	PriorityQueue frontier;
	frontier.put(0, start.id);
	
	came_from[start.id] = start.id;
	cost_so_far[start.id] = 0;
	Node current;
	Node next;
	double new_cost;
	double priority;

	while(!frontier.empty()){

		current = MG.nodes[frontier.get()];

		if(current.id == dest.id) break;

		for(auto i = 0; i < MG.num_nodes; i++){
			if(current.id != i && MG.matrix[current.id][i] > 0){
				//Node next = MG.nodes[i];
				int distance = MG.matrix[current.id][i];
				new_cost = cost_so_far[current.id] + distance;
				//If the Node is not in the unordered map OR if the new_cost is smaller than its current cost
				if(cost_so_far.find(i) == cost_so_far.end() || new_cost < cost_so_far[i]){
					cost_so_far[i] = new_cost;
					priority = new_cost + distance_heuristic(MG.nodes[i], dest);
					frontier.put(priority, i);
					came_from[i] = current.id;
				}
			}	
		}
	}	
	return cost_so_far[dest.id];

}

double Astar::manhattan(Node a, Node b){
	double dx = abs(a.x - b.x);
	double dy = abs(a.y - b.y);
	return 2 * ( dx + dy);
}

double Astar::diagonal(Node a, Node b){
	double dx = abs(a.x - b.x);
	double dy = abs(a.y - b.y);
	return (dx + dy) - std::min(dx,dy);
}




