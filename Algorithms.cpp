// asaf0604@gmail.com 325362457
#include "Algorithms.hpp"
#include "QUEUE.cpp"
#include "PRIORITY.cpp"
#include "union.cpp"
#include <iostream>
#include <limits>

namespace graph
{

    void printAdjacencyMatrix(int **matrix, int numVertices)
    {
        for (int i = 0; i < numVertices; i++)
        {
            for (int j = 0; j < numVertices; j++)
            {
                std::cout << matrix[i][j] << "\t";
            }
            std::cout << std::endl;
        }
    }

    // DFS Helper - Fix to fully traverse the graph, covering disconnected components or cycles
    void dfsHelper(const Graph &g, int vertex, bool *visited, Graph &dfsTree)
    {
        visited[vertex] = true;
        int numVertices = g.getNumVertices();
        int **adjacencyList = g.getAdjacencyList();

        for (int i = 0; i < numVertices; i++)
        {
            if (adjacencyList[vertex][i] != 0 && !visited[i]) 
            {
                dfsTree.addEdge(vertex, i, adjacencyList[vertex][i]);
                std::cout << "DFS Adding edge: " << vertex << " - " << i << " with weight " << adjacencyList[vertex][i] << std::endl;  // Debugging output
                dfsHelper(g, i, visited, dfsTree);
            }
        }

        // Start DFS from unvisited nodes to cover all disconnected components
        for (int i = 0; i < numVertices; i++) {
            if (!visited[i]) {
                dfsHelper(g, i, visited, dfsTree);
            }
        }
    }

    // BFS Algorithm
    Graph Algorithms::bfs(const Graph &g, int start)
    {
        int numVertices = g.getNumVertices();
        int **adjacencyList = g.getAdjacencyList();
        Graph bfsTree(numVertices);

        bool *visited = new bool[numVertices]();
        Queue q(numVertices);

        visited[start] = true;
        q.enqueue(start);

        while (!q.isEmpty())
        {
            int vertex = q.dequeue();

            for (int i = 0; i < numVertices; i++)
            {
                if (adjacencyList[vertex][i] != 0 && !visited[i])
                {
                    visited[i] = true;
                    q.enqueue(i);
                    bfsTree.addEdge(vertex, i, adjacencyList[vertex][i]);
                }
            }
        }

        delete[] visited;
        return bfsTree;
    }

    // DFS Algorithm
    Graph Algorithms::dfs(const Graph &g, int start)
    {
        int numVertices = g.getNumVertices();
        Graph dfsForest(numVertices);
        bool *visited = new bool[numVertices]();

        dfsHelper(g, start, visited, dfsForest);

        // Start DFS from unvisited nodes to cover all disconnected components
        for (int i = 0; i < numVertices; i++)
        {
            if (!visited[i])
            {
                dfsHelper(g, i, visited, dfsForest);
            }
        }

        delete[] visited;
        return dfsForest;
    }

    // Check for negative weights in the graph (for Dijkstra)
    bool Algorithms::hasNegativeWeight(const Graph &g)
    {
        for (int i = 0; i < g.getNumVertices(); ++i)
        {
            for (int j = 0; j < g.getNumVertices(); ++j)
            {
                if (g.getAdjacencyList()[i][j] < 0)
                {
                    return true;
                }
            }
        }
        return false;
    }

    // Dijkstra Algorithm
    Graph Algorithms::dijkstra(const Graph &g, int start)
    {
        if (hasNegativeWeight(g))
        {
            throw std::invalid_argument("Graph contains negative edge weights, which Dijkstra cannot handle.");
        }

        int numVertices = g.getNumVertices();
        int **adjacencyList = g.getAdjacencyList();
        int *dist = new int[numVertices];
        int *parent = new int[numVertices];
        bool *visited = new bool[numVertices]();

        for (int i = 0; i < numVertices; i++)
        {
            dist[i] = std::numeric_limits<int>::max();
            parent[i] = -1;
        }

        dist[start] = 0;

        PriorityQueue pq(numVertices * numVertices);
        pq.enqueue({start, 0});

        while (!pq.isEmpty())
        {
            Pair current = pq.dequeue();
            int u = current.vertex;
            if (visited[u])
                continue;
            visited[u] = true;

            for (int v = 0; v < numVertices; v++)
            {
                if (adjacencyList[u][v] != 0 && !visited[v] &&
                    dist[u] + adjacencyList[u][v] < dist[v])
                {
                    dist[v] = dist[u] + adjacencyList[u][v];
                    parent[v] = u;
                    pq.enqueue({v, dist[v]});
                }
            }
        }

        Graph shortestTree(numVertices);
        for (int i = 0; i < numVertices; i++)
        {
            if (parent[i] != -1)
            {
                shortestTree.addEdge(parent[i], i, adjacencyList[parent[i]][i]);
            }
        }

        delete[] dist;
        delete[] parent;
        delete[] visited;
        return shortestTree;
    }

    // Prim's Algorithm
    Graph Algorithms::prim(const Graph &g)
    {
        int numVertices = g.getNumVertices();
        int **adjMatrix = g.getAdjacencyList();

        int *parent = new int[numVertices];
        int *key = new int[numVertices];
        bool *inMST = new bool[numVertices]();

        for (int i = 0; i < numVertices; i++)
        {
            key[i] = std::numeric_limits<int>::max();
            parent[i] = -1;
        }

        key[0] = 0;
        PriorityQueue pq(numVertices * numVertices);
        pq.enqueue({0, 0});

        while (!pq.isEmpty())
        {
            Pair current = pq.dequeue();
            int u = current.vertex;

            if (inMST[u])
                continue;
            inMST[u] = true;

            for (int v = 0; v < numVertices; v++)
            {
                if (adjMatrix[u][v] != 0 && !inMST[v] && adjMatrix[u][v] < key[v])
                {
                    key[v] = adjMatrix[u][v];
                    parent[v] = u;
                    pq.enqueue({v, key[v]});
                    std::cout << "Prim Adding edge: " << u << " - " << v << " with weight " << adjMatrix[u][v] << std::endl;  // Debugging output
                }
            }
        }

        Graph mst(numVertices);
        for (int i = 1; i < numVertices; i++)
        {
            if (parent[i] != -1)
            {
                mst.addEdge(parent[i], i, adjMatrix[parent[i]][i]);
            }
        }

        delete[] parent;
        delete[] key;
        delete[] inMST;

        return mst;
    }

    Graph Algorithms::kruskal(const Graph &g)
    {
        int numVertices = g.getNumVertices();
        int **adjMatrix = g.getAdjacencyList();

        struct Edge
        {
            int src, dest, weight;
        };

        Edge *edges = new Edge[numVertices * numVertices];
        int edgeCount = 0;

        for (int i = 0; i < numVertices; i++)
        {
            for (int j = i + 1; j < numVertices; j++)
            {
                if (adjMatrix[i][j] != 0)
                {
                    edges[edgeCount++] = {i, j, adjMatrix[i][j]};
                }
            }
        }

        for (int i = 0; i < edgeCount - 1; i++)
        {
            for (int j = 0; j < edgeCount - i - 1; j++)
            {
                if (edges[j].weight > edges[j + 1].weight)
                {
                    Edge temp = edges[j];
                    edges[j] = edges[j + 1];
                    edges[j + 1] = temp;
                }
            }
        }

        UnionFind uf(numVertices);
        Graph mst(numVertices);
        int edgeAdded = 0;

        for (int i = 0; i < edgeCount && edgeAdded < numVertices - 1; i++)
        {
            int u = edges[i].src;
            int v = edges[i].dest;

            if (!uf.connected(u, v))
            {
                uf.unionSets(u, v);
                mst.addEdge(u, v, edges[i].weight);
                edgeAdded++;
                std::cout << "Kruskal Adding edge: " << u << " - " << v << " with weight " << edges[i].weight << std::endl;  // Debugging output
            }
        }

        delete[] edges;
        return mst;
    }

}
