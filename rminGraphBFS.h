//
// Created by kmathews on 5/24/18.
//

#ifndef STOCHASTIC_ROUTING_TEST_RMINGRAPH_H
#define STOCHASTIC_ROUTING_TEST_RMINGRAPH_H

#ifdef NS3
namespace ns3 {
#endif

#include <list>
#include <vector>
#include <deque>
#include <iostream>
#include <set>
#include <boost/range/irange.hpp>


template<class nodeType>
class rminGraph{
private:

    std::vector<std::vector<int> > edge; //Total edges
    std::vector<unsigned char> visited; // Check whether its visited or not

public:
    rminGraph(int graphSize);
    rminGraph(const rminGraph &) = default;

    virtual ~rminGraph() = default;

    void add_edge(nodeType u,nodeType v);

    void searchRoute(nodeType v, int level);
};

#ifdef NS3
}
#endif
#endif //STOCHASTIC_ROUTING_TEST_RMINGRAPH_H
