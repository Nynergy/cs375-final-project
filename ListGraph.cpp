#include "ListGraph.h"
#include "ListNode.h"
#include "ListEdge.h"
#include <iostream>

using namespace std;

ListGraph::ListGraph(ListEdge edges[], int vertices, int edgeNum){
  this->v = vertices;
  this->head = new ListNode*[vertices];
  // initialize head pointer for all vertices
  for(int i = 0; i < vertices; i++){
    this->head[i] = nullptr;
  }
  // adding edges
  for(unsigned i = 0; i < edgeNum; i++){
    int s = edges[i].src;
    int d = edges[i].dest;
    int weight = edges[i].weight;
    int x = edges[i].x;
    int y = edges[i].y;
    ListNode* node = newNode(d, weight, head[s], x, y);
    // point head pointer to new node
    head[s] = node;
  }
}
ListNode* ListGraph::newNode(int value, int w, ListNode* head, int x, int y){
  ListNode* node = new ListNode(x, y);
  node->id = value;
  node->weight = w;
  node->next = head;
  // if(head == nullptr) return node;


  // ListNode* nextN = head->next;
  // if(nextN == nullptr) {head->next = node; return node;}
  // ListNode* prev = nullptr;
  // while(nextN != nullptr){
	//   prev = nextN;
	//   nextN = nextN->next;
  // }
  // prev->next = node;
  return node;
}
ListGraph::~ListGraph(){
  for (int i = 0; i < v; i++){
    delete[] head;
    //delete head;
  }
}
//ListGraph::~ListGraph(){}
void ListGraph::printGraph(ListNode* p, int i){
      while (p != nullptr){
          cout << "( i: " << i << " | id: " << p->id<< " | weight: " << p->weight << ") " << endl;
          p = p->next;
      }
}
