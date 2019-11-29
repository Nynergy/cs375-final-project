#include "ListGraph.h"
#include "ListNode.h"
#include "ListEdge.h"
#include <iostream>

using namespace std;

ListGraph::ListGraph(ListEdge edges[], int& edgeNum, int& N){
  this->v = N;
  this->head = new ListNode*[N];
  // initialize head pointer for all vertices
  for(int i = 0; i < N; i++){
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
    head[x] = node;
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
    delete[] head[i];
    //delete head;
  }
}
//ListGraph::~ListGraph(){}
void ListGraph::printGraph(ListNode* p, int i){
  for (int i = 0; i < v; ++i)
  {
      while (p != nullptr){
          cout << "(" << i << ", " << p->id<< ", " << p->weight << ") ";
          p = p->next;
      }
      cout<<endl;
  }
}
