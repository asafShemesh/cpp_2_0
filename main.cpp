#include "Graph.hpp"
#include "Algorithms.hpp"
#include <iostream>
//asaf0604@gmail.com 325362457


using namespace graph;

void printGraph(const Graph& g) {
    int numVertices = g.getNumVertices();
    int** adj = g.getAdjacencyList();

    std::cout << "Adjacency Matrix:" << std::endl;
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            std::cout << adj[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void printSeparator(const std::string& title) {
    std::cout << "\n=== " << title << " ===\n";
}

int main() {
    int V = 8;
    Graph g(V);

    g.addEdge(0, 1, 3);
    g.addEdge(0, 2, 1);
    g.addEdge(1, 2, 7);
    g.addEdge(1, 3, 5);
    g.addEdge(2, 3, 2);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 2);
    g.addEdge(3, 5, 3);
    g.addEdge(4, 5, 4);
    g.addEdge(4, 6, 6);
    g.addEdge(5, 6, 1);
    g.addEdge(5, 7, 8);
    g.addEdge(6, 7, 9);

    // Print the original graph
    printSeparator("Original Graph");
    printGraph(g);

    // === BFS ===
    Graph bfsTree = Algorithms::bfs(g, 0);
    printSeparator("BFS Tree from vertex 0");
    printGraph(bfsTree);

    // === DFS ===
    Graph dfsTree = Algorithms::dfs(g, 0);
    printSeparator("DFS Tree from vertex 0");
    printGraph(dfsTree);

    // === Dijkstra ===
    Graph dijkstraTree = Algorithms::dijkstra(g, 0);
    printSeparator("Dijkstra's Shortest Path Tree from vertex 0");
    printGraph(dijkstraTree);

    // === Prim ===
    Graph primTree = Algorithms::prim(g);
    printSeparator("Prim's Minimum Spanning Tree");
    printGraph(primTree);

    // === Kruskal ===
    Graph kruskalTree = Algorithms::kruskal(g);
    printSeparator("Kruskal's Minimum Spanning Tree");
    printGraph(kruskalTree);

    return 0;
}
