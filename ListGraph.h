#pragma once

#include "AdjList.h"
#include "ListNode.h"

class ListGraph{
private:
  int v; // number of vertices
  struct AdjList* list;
public:
  std::vector<int> list;
  ListGraph(int);
  ListNode* newNode(int);
  ~ListGraph();
  void addEdge(int, int);
  void printGraph();
};