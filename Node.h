#pragma once

#include <utility>
#include <vector>

class Node{
	public:

		Node(): x(0), y(0), id(-1), adj(std::vector<std::pair<Node,int>>()) { }
		Node(int xx, int yy, int idd): x(xx), y(yy), id(idd), adj(std::vector<std::pair<Node,int>>()) { }
		
		int id;
		int x;
		int y;
		std::vector<std::pair<Node,int>> adj;
		void addEdge(Node n , int i){ adj.push_back(std::pair<Node,int>(n,i));}

};
