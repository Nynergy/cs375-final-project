#pragma once

#include <vector>

class ListGraph{
private:
  int v; // number of vertices
public:
  std::vector<int> list;
  ListGraph(std::vector<int>, int);
  ~ListGraph();
  void addEdge(int, int);
};