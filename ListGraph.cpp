#include "ListGraph.h"
#include "ListNode.h"
#include "ListEdge.h"
#include <iostream>

using namespace std;

ListGraph::ListGraph(int num, ListNode * v[]){
  this->numVertices = num;
  this->nodes = new ListNode *[num];
  for(int i = 0; i < num; i++){
	  nodes[i] = v[i];
  }
}

ListGraph::~ListGraph(){
    for(int i = 0; i < numVertices; i++){
	    delete nodes[i];
    }
    delete nodes[];
}
//ListGraph::~ListGraph(){}
void ListGraph::printGraph(ListNode* p, int i){
      while (p != nullptr){
          cout << "( i: " << i << " | id: " << p->id<< " | weight: " << p->nextWeight << ") " << endl;
          p = p->next;
      }
}
