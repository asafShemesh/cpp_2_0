# Graph Algorithms Project

This project implements various graph algorithms using a custom-built graph data structure. The goal is to demonstrate the working of different graph traversal and optimization algorithms, utilizing an adjacency matrix to represent graphs. The project includes both basic traversal methods and advanced optimization techniques.

## Project Structure

The project is organized into the following files, each contributing to different components of the graph and its algorithms:

1. **Graph.hpp** and **Graph.cpp**:
   - Defines and implements the `Graph` class, which represents a graph using an adjacency matrix. 
   - Provides methods for adding and removing edges, printing the adjacency matrix, and accessing graph data.

2. **Algorithms.hpp** and **Algorithms.cpp**:
   - Implements key graph algorithms including DFS, BFS, Dijkstra's Shortest Path, Prim’s Minimum Spanning Tree (MST), and Kruskal’s MST.
   - These algorithms operate on a `Graph` object to perform various graph operations like traversal and optimization.

3. **main.cpp**:
   - Contains an example of creating and manipulating graphs using the `Graph` class and applying different algorithms.
   - Serves as the entry point for running the project, showcasing the working of the algorithms with a sample graph.

4. **QUEUE.cpp**:
   - Implements a custom queue class that is used for the BFS algorithm.

5. **test.cpp**:
   - Contains unit tests for graph operations and algorithm functionality, ensuring correctness by performing checks and assertions.

6. **test_doctest.cpp**:
   - A file using the Doctest framework to validate graph operations and algorithm correctness.
   - Helps in testing different graph functions and algorithms in a modular way, ensuring their functionality in various scenarios.

## Implemented Graph Algorithms

### 1. **Depth-First Search (DFS)**
   - DFS is a graph traversal algorithm that explores as far as possible along each branch before backtracking.
   - **Usage**: Call `Algorithms::dfs()` on a `Graph` object to get the DFS traversal tree starting from a specific vertex.
   
### 2. **Breadth-First Search (BFS)**
   - BFS explores the graph level by level, using a queue to ensure vertices are explored in the order they are discovered.
   - **Usage**: Call `Algorithms::bfs()` on a `Graph` object to get the BFS traversal tree starting from a specific vertex.

### 3. **Dijkstra’s Algorithm (Shortest Path)**
   - Dijkstra's algorithm finds the shortest paths from a source vertex to all other vertices in a weighted graph with non-negative edge weights.
   - **Usage**: Call `Algorithms::dijkstra()` on a `Graph` object to compute the shortest paths from a specified source vertex.

### 4. **Prim’s Algorithm (Minimum Spanning Tree)**
   - Prim's algorithm computes the minimum spanning tree (MST) of a connected, weighted graph by progressively adding the minimum-weight edges.
   - **Usage**: Call `Algorithms::prim()` on a `Graph` object to compute the MST using Prim’s algorithm.

### 5. **Kruskal’s Algorithm (Minimum Spanning Tree)**
   - Kruskal's algorithm computes the MST by sorting all edges by weight and adding edges to the MST while avoiding cycles.
   - **Usage**: Call `Algorithms::kruskal()` on a `Graph` object to compute the MST using Kruskal’s algorithm.

## How to Run the Project

Follow these steps to build and run the project:

1. **run the project**:
   make
   make test
   clear
   ./test
   ./Main
    make clean
    make valgrind

