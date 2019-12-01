#pragma once

#include "ListEdge.h"
#include "ListNode.h"

class ListGraph{
public:
  int numVertices; // number of vertices
  ListNode ** nodes;
  ListGraph(int numVertices, ListNode * v[]);
  ~ListGraph();
  //void addEdge(int, int);
  void printGraph(ListNode*, int);
};
