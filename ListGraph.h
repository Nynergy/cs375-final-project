#pragma once

#include "ListEdge.h"
#include "ListNode.h"

class ListGraph{
private:
  int v; // number of vertices
  ListNode ** head;
public:
  ListGraph(int);
  ListNode* newNode(int);
  ~ListGraph();
  void addEdge(int, int);
  void printGraph();
};