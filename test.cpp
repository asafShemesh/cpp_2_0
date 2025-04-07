// asaf0604@gmail.com 325362457
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Graph.hpp"
#include "Algorithms.hpp"

// Helper function to check edge existence in adjacency matrix
void checkEdge(const graph::Graph& g, int src, int dest, int expectedWeight) {
    CHECK(g.getAdjacencyList()[src][dest] == expectedWeight);
    CHECK(g.getAdjacencyList()[dest][src] == expectedWeight); // Since it's an undirected graph
}

TEST_CASE("Graph operations") {
    graph::Graph g(5);

    // Test adding edges
    g.addEdge(0, 1, 10);
    g.addEdge(1, 2, 20);
    g.addEdge(2, 3, 30);
    g.addEdge(3, 4, 40);

    // Check if edges were added correctly
    checkEdge(g, 0, 1, 10);
    checkEdge(g, 1, 2, 20);
    checkEdge(g, 2, 3, 30);
    checkEdge(g, 3, 4, 40);

    // Test edge removal
    g.removeEdge(1, 2);
    CHECK(g.getAdjacencyList()[1][2] == 0);
    CHECK(g.getAdjacencyList()[2][1] == 0); // Check symmetry

    // Try removing an edge that doesn't exist
    CHECK_THROWS_AS(g.removeEdge(1, 2), std::runtime_error);

    // Test adding an edge with out-of-range vertices
    CHECK_THROWS_AS(g.addEdge(5, 1, 10), std::out_of_range);
}

TEST_CASE("BFS Algorithm") {
    graph::Graph g(5);
    g.addEdge(0, 1, 10);
    g.addEdge(1, 2, 20);
    g.addEdge(2, 3, 30);
    g.addEdge(3, 4, 40);

    graph::Graph bfsTree = graph::Algorithms::bfs(g, 0);

    // Check if BFS Tree edges are correct
    checkEdge(bfsTree, 0, 1, 10);
    checkEdge(bfsTree, 1, 2, 20);
    checkEdge(bfsTree, 2, 3, 30);
    checkEdge(bfsTree, 3, 4, 40);
}

TEST_CASE("DFS Algorithm") {
    graph::Graph g(5);
    g.addEdge(0, 1, 10);
    g.addEdge(1, 2, 20);
    g.addEdge(2, 3, 30);
    g.addEdge(3, 4, 40);

    graph::Graph dfsTree = graph::Algorithms::dfs(g, 0);

    // Check if DFS Tree edges are correct
    checkEdge(dfsTree, 0, 1, 10);
    checkEdge(dfsTree, 1, 2, 20);
    checkEdge(dfsTree, 2, 3, 30);
    checkEdge(dfsTree, 3, 4, 40);
}

TEST_CASE("Dijkstra Algorithm") {
    graph::Graph g(5);
    g.addEdge(0, 1, 10);
    g.addEdge(1, 2, 20);
    g.addEdge(2, 3, 30);
    g.addEdge(3, 4, 40);

    graph::Graph dijkstraTree = graph::Algorithms::dijkstra(g, 0);

    // Check if Dijkstra Tree edges are correct
    checkEdge(dijkstraTree, 0, 1, 10);
    checkEdge(dijkstraTree, 1, 2, 20);
    checkEdge(dijkstraTree, 2, 3, 30);
    checkEdge(dijkstraTree, 3, 4, 40);
}

TEST_CASE("Prim's Algorithm") {
    graph::Graph g(5);
    g.addEdge(0, 1, 10);
    g.addEdge(1, 2, 20);
    g.addEdge(2, 3, 30);
    g.addEdge(3, 4, 40);
    g.addEdge(0, 2, 50);
    g.addEdge(1, 3, 60);

    graph::Graph mst = graph::Algorithms::prim(g);

    // Check if Prim's MST edges are correct (The exact MST may vary based on algorithm specifics)
    checkEdge(mst, 0, 1, 10);
    checkEdge(mst, 1, 2, 20);
    checkEdge(mst, 2, 3, 30);
    checkEdge(mst, 3, 4, 40);
}

TEST_CASE("Kruskal's Algorithm") {
    graph::Graph g(5);
    g.addEdge(0, 1, 10);
    g.addEdge(1, 2, 20);
    g.addEdge(2, 3, 30);
    g.addEdge(3, 4, 40);
    g.addEdge(0, 2, 50);
    g.addEdge(1, 3, 60);

    graph::Graph mst = graph::Algorithms::kruskal(g);

    checkEdge(mst, 0, 1, 10);
    checkEdge(mst, 1, 2, 20);
    checkEdge(mst, 2, 3, 30);
    checkEdge(mst, 3, 4, 40);
}

TEST_CASE("Edge Cases") {
    // Test an empty graph
    graph::Graph emptyGraph(0);
    CHECK(emptyGraph.getNumVertices() == 0);
    
    // Test a graph with a single node
    graph::Graph singleNodeGraph(1);
    CHECK(singleNodeGraph.getNumVertices() == 1);
    
    // Test disconnected graph
    graph::Graph disconnectedGraph(5);
    CHECK(disconnectedGraph.getNumVertices() == 5);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            CHECK(disconnectedGraph.getAdjacencyList()[i][j] == 0);
        }
    }
}
