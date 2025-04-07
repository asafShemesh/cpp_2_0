#include "Graph.hpp"
//asaf0604@gmail.com 325362457
#include <stdexcept>

namespace graph {

Graph::Graph(int vertices) : numVertices(vertices) {
    adjacencyList = new int*[numVertices];
    for (int i = 0; i < numVertices; i++) {
        adjacencyList[i] = new int[numVertices]();
    }
}

Graph::~Graph() {
    for (int i = 0; i < numVertices; i++) {
        delete[] adjacencyList[i];
    }
    delete[] adjacencyList;
}

void Graph::addEdge(int src, int dest, int weight = 1) {
    if (src < 0 || src >= numVertices || dest < 0 || dest >= numVertices || src==dest) {
        throw std::out_of_range("Vertex index out of range.");
    }
    
    if (adjacencyList[src][dest] != 0 && adjacencyList[dest][src]!=0 ) {
        throw std::logic_error("Edge already exists between these vertices.");
    }

    adjacencyList[src][dest] = weight;
    adjacencyList[dest][src] = weight; 
}


void Graph::removeEdge(int src, int dest) {
    if (src >= numVertices || dest >= numVertices || adjacencyList[src][dest] == 0) {
        throw std::runtime_error("Edge does not exist.");
    }
    adjacencyList[src][dest] = 0;
    adjacencyList[dest][src] = 0;
}


void Graph::print_graph() const {
    int numVertices = getNumVertices();
    int** adjacencyList = getAdjacencyList();
    
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            std::cout << adjacencyList[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
}


int Graph::getNumVertices() const {
    return numVertices;
}

int** Graph::getAdjacencyList() const {
    return adjacencyList;
}

}
