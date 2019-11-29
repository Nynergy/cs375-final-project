#pragma once

#include "ListEdge.h"
#include "ListNode.h"

class ListGraph{
public:
  int v; // number of vertices
<<<<<<< HEAD
  ListNode ** head;
public:
=======
  struct AdjList* list;

>>>>>>> dd2d48b9d422377116c795405caadf8a419d7dd0
  ListGraph(int);
  ListNode* newNode(int);
  ~ListGraph();
  void addEdge(int, int);
  void printGraph();
};
