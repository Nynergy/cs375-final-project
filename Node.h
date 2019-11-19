#pragma once

#include <utility>
#include <vector>

// Node struct implementation
struct Node {
	int id;
	std::vector<std::pair<Node, int>> adj;
		// Each pair represents an adjacent node
		// and the distance between them
};
