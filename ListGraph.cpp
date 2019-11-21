#include "ListGraph.h"
using namespace std;

ListGraph::ListGraph(vector<int> list, int num){
  this->v = num;
  this->list = list;
}
void ListGraph::addEdge(int u, int v){
    this->list[u].push_back(v);
    this->list[v].push_back(u);
}
ListGraph::~ListGraph(){}