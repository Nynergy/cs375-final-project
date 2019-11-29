#include "MatrixGraph.h"
#include "ListGraph.h"
#include "ListEdge.h"
#include "Astar.h"
#include <iostream>

int main() {
	
	ListEdge edges[] = {{2,1,2},{1,2,3},{1,3,3},{2,3,2},{3,1,4},{2,3,3}};
	int N = sizeof(edges);
	int edgeNum = 2;
	ListGraph adjList(edges, edgeNum, N);
	for (int i = 0; i < N; i++){
		adjList.printGraph(adjList.head[i], i);
	}
	return 0;
}
