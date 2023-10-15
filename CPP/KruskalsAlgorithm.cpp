#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int src, dest, weight;
};

class Graph {
private:
    int V;
    vector<Edge> edges;

public:
    Graph(int vertices) : V(vertices) {}

    void addEdge(int src, int dest, int weight) {
        edges.push_back({src, dest, weight});
    }

    int findParent(vector<int>& parent, int vertex) {
        if (parent[vertex] == -1)
            return vertex;
        return findParent(parent, parent[vertex]);
    }

    void unionVertices(vector<int>& parent, int x, int y) {
        int rootX = findParent(parent, x);
        int rootY = findParent(parent, y);
        parent[rootX] = rootY;
    }

    void kruskalMST() {
        // Sort edges by weight
        sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
            return a.weight < b.weight;
        });

        vector<int> parent(V, -1);
        vector<Edge> mst;

        for (const Edge& edge : edges) {
            int rootSrc = findParent(parent, edge.src);
            int rootDest = findParent(parent, edge.dest);

            if (rootSrc != rootDest) {
                mst.push_back(edge);
                unionVertices(parent, rootSrc, rootDest);
            }
        }

        cout << "Minimum Spanning Tree (Kruskal's Algorithm):\n";
        for (const Edge& edge : mst) {
            cout << edge.src << " - " << edge.dest << " : " << edge.weight << "\n";
        }
    }
};

int main() {
    Graph g(6); // Number of vertices

    // Adding edges with weights
    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 5);
    g.addEdge(2, 3, 1);
    g.addEdge(2, 4, 3);
    g.addEdge(3, 4, 7);

    g.kruskalMST();

    return 0;
}
