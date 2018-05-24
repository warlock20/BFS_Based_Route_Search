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

}


#ifdef NS3
}
#endif
