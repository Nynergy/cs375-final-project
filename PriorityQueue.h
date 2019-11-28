#ifndef GALAXY_HF
#define GALAXY_HF

#include<cfloat>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <utility>
#include <unordered_map>
#include <memory>


class PriorityQueue{
	private:
		//Define Element for Queue
		typedef std::pair<double, int> PQElement;

		//Create Priority Queue
		std::priority_queue<PQElement, std::vector<PQElement>, std::greater<PQElement>> elements;

	public:
		//Getter
		auto getQueue(){ return elements;}
		
		//Methods

		bool empty(){ return elements.empty(); }

		//Insert a new PQElement
		void put(double d, int p){ elements.push(PQElement(d,p));}
		
		//Get top Element of the queue and remove it
		int get(){ int ret = elements.top().second; elements.pop(); return ret;}
};
#endif
