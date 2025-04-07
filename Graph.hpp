#ifndef GRAPH_HPP
#define GRAPH_HPP
//asaf0604@gmail.com 325362457

#include <iostream>

namespace graph {

class Graph {
private:
    const int numVertices;
    int** adjacencyList;

public:
    Graph(int vertices);
    ~Graph();

    void addEdge(int src, int dest, int weight);
    void removeEdge(int src, int dest);
    void print_graph() const;

    int getNumVertices() const;
    int** getAdjacencyList() const;
};

}

#endif
