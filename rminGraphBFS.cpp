//
// Created by kmathews on 5/24/18.
//



#ifdef NS3
namespace ns3 {
#endif

#include "rminGraphBFS.h"

template<class nodeType>
rminGraph<nodeType>::rminGraph(nodeType graphSize)  {
    edge.resize(graphSize);
    visited.resize(graphSize);
}

template<class nodeType>
void rminGraph<nodeType>::add_edge(nodeType u, nodeType v){
    edge[u].push_back(v);
}

template<class nodeType>
void rminGraph<nodeType>::searchRoute(nodeType v, int level) {
    int baseLevel = 1; //Starting with node at level 1
    int currentLevel = 1;
    for (auto i:visited) i = false;
    visited[v]= true;

    std::multiset<int,std::deque<nodeType>> tracker;

    std::deque<nodeType> temp;
    temp.push_back(v);
    tracker.insert(std::make_pair(currentLevel,temp));

    if(currentLevel<=level){
        for(std::deque<nodeType> i:tracker){
            nodeType searchNode = i.pop_back();

            for(auto  i:edge[searchNode]){
                if(!visited[i]){
                    std::deque<nodeType> newQueue;
                    newQueue = i;
                    newQueue.push_back(i);
                    tracker.insert(std::make_pair(currentLevel,newQueue));
                }
            }

        }
        currentLevel++;
    }

    /*
    for (auto i:visited) i = false;
    std::list<nodeType> q;
    visited[v] = true;

    q.push_back(v);

    while (!q.empty())
    {
        v = q.front();
        std::cout<<v<<" ";
        q.pop_front();
        for(auto i : edge[v])
        {
            if(!visited[i])
            {
                visited[i] = true;
                q.push_back(i);
            }
        }
    }*/

}


#ifdef NS3
}
#endif
