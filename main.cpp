#include "MatrixGraph.h"
#include "ListGraph.h"
#include "ListEdge.h"
#include "Astar.h"
#include <iostream>

using namespace std;

int main() {

	ListEdge edges[] = {{2,1,2,3,3},{1,2,3,1,1},{1,3,3,2,2},{2,3,2,3,4},{3,1,4,1,1},{2,3,3,5,5}};
	int N = sizeof(edges)/ sizeof(ListEdge);
	cout << N << endl;
	//ListGraph adjList(edges, N);
	for (int i = 0; i < N; i++){
	//	adjList.printGraph(adjList.head[i], i);
	}
	return 0;
}
