#include "MatrixGraph.h"

int main() {
	Node one, two, three;
	one.id = 0;
	two.id = 1;
	three.id = 2;
	std::pair<Node, int> edge_1;
	std::pair<Node, int> edge_2;
	std::pair<Node, int> edge_3;
	edge_1.first = two;
	edge_1.second = 10;
	edge_2.first = three;
	edge_2.second = 5;
	edge_3.first = one;
	edge_3.second = 25;
	std::vector<std::pair<Node, int>> adj_1;
	adj_1.push_back(edge_1);
	std::vector<std::pair<Node, int>> adj_2;
	adj_2.push_back(edge_2);
	std::vector<std::pair<Node, int>> adj_3;
	adj_3.push_back(edge_3);
	one.adj = adj_1;
	two.adj = adj_2;
	three.adj = adj_3;
	std::vector<Node> nodes;
	nodes.push_back(one);
	nodes.push_back(two);
	nodes.push_back(three);
	MatrixGraph mat_graph(nodes);
	return 0;
}
