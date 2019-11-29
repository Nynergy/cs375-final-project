#pragma once

#include "ListEdge.h"
#include "ListNode.h"

class ListGraph{
public:
  int v; // number of vertices
  ListNode ** head;
public:
  ListGraph(ListEdge[], int&, int&);
  ListNode* newNode(int, int, ListNode*);
  ~ListGraph();
  //void addEdge(int, int);
  void printGraph();
};
