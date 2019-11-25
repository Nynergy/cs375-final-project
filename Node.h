#pragma once

#include <utility>
#include <vector>

// Node struct implementation
class Node {
	public:
		static int nextID;
		Node(): x(0), y(0), adj(std::vector<std::pair<Node, int>>()) { }
		Node(int xx, int yy): x(xx), y(yy), adj(std::vector<std::pair<Node,int>>()) { }
		int id;
		int x;
		int y;
		std::vector<std::pair<Node, int>> adj;
		// Each pair represents an adjacent node
		// and the distance between them
};
