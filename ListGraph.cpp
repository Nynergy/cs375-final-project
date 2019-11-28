#include "ListGraph.h"
using namespace std;

ListGraph::ListGraph(int num){
  this->v = num;
  array = new AdjList[v];
  for(int i = 0; i < v; i++){
    array[i].head = NULL;
  }
}
ListGraph::newNode(int dest){
  ListNode* node = new ListNode;
  node->dest = dest;
  node->next = NULL;
  return node;
}
void ListGraph::addEdge(int u, int v){
    ListNode* node = newNode(v);
    node->next = list[u].head;
    list[u].head = node;
    node = newNode(u);
    node->next = list[v].head;
    list[v].head = node;
}
// ListGraph::~ListGraph(){
//   for (int i = 0; i < v; i++){
//     delete[] list[i];
//   }
//   delete list;
// }
ListGraph::~ListGraph(){}
void ListGraph::printGraph(){
  for (i = 0; i < V; ++i)
  {
      ListNode* pCrawl = list[i].head;
      cout<<"\n Adjacency list of vertex "<<v<<"\n head ";
      while (pCrawl){
          cout<<"-> "<<pCrawl->dest;
          pCrawl = pCrawl->next;
      }
      cout<<endl;
  }
}
