#include "ListGraph.h"
#include "ListNode.h"
#include "ListEdge.h"
#include <iostream>

using namespace std;

ListGraph::ListGraph(ListEdge edges[], int &n, int &N){
  this->v = N;
  this->head = new ListNode*[N];
  
  for(int i = 0; i < this->v; i++){
    this->head[i] = nullptr;
  }
  for(unsigned i = 0; i < n; i++){
    int s = edges[i].src;
    int d = edges[i].dest;
    int w = edges[i].weight;
    ListNode* node = newNode(d, w, head[s]); 
    head[s] = node;
  }
}
ListNode* ListGraph::newNode(int value, int weight, ListNode* head){
  ListNode* node = new ListNode;
  node->val = value;
  node->weight = weight;
  node->next = head;
  return node;
}
// void ListGraph::addEdge(int u, int v){
//     ListNode* node = new ListNode;
//     node->next = list[u].head;
//     list[u].head = node;
//     node = newNode(u);
//     node->next = list[v].head;
//     list[v].head = node;
// }
ListGraph::~ListGraph(){
  for (int i = 0; i < v; i++){
    delete[] head[i];
    delete head;
  }
}
//ListGraph::~ListGraph(){}
void ListGraph::printGraph(){
  for (int i = 0; i < v; ++i)
  {
      ListNode* pCrawl = head[i];
      cout<<"\n Adjacency list of vertex "<<i<<"\n head ";
      while (pCrawl){
          cout << "(" << i << ", " << pCrawl->val << ", " << pCrawl->weight << ") ";
          pCrawl = pCrawl->next;
      }
      cout<<endl;
  }
}
