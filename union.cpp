// asaf0604@gmail.com 325362457
class UnionFind
{
private:
    int *parent;
    int *rank;
    int size;

public:
    UnionFind(int n)
    {
        size = n;
        parent = new int[size];
        rank = new int[size];
        for (int i = 0; i < size; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    ~UnionFind()
    {
        delete[] parent;
        delete[] rank;
    }

    int find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionSets(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY)
            return;

        if (rank[rootX] < rank[rootY])
        {
            parent[rootX] = rootY;
        }
        else if (rank[rootX] > rank[rootY])
        {
            parent[rootY] = rootX;
        }
        else
        {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }

    bool connected(int x, int y)
    {
        return find(x) == find(y);
    }
};
