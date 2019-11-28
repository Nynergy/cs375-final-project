#pragma once

#include "AdjList.h"
#include "ListNode.h"

class ListGraph{
public:
  int v; // number of vertices
  struct AdjList* list;

  ListGraph(int);
  ListNode* newNode(int);
  ~ListGraph();
  void addEdge(int, int);
  void printGraph();
};
