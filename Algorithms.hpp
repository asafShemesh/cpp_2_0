#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP
// asaf0604@gmail.com 325362457

#include "Graph.hpp"

namespace graph
{

    class Algorithms
    {
    public:
        static Graph bfs(const Graph &g, int start);
        static Graph dfs(const Graph &g, int start);
        static Graph dijkstra(const Graph &g, int start);
        static Graph prim(const Graph &g);
        static Graph kruskal(const Graph &g);
        static bool hasNegativeWeight(const Graph &g);
    };

}

#endif
