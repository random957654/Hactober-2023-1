#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// Define a structure to represent an edge
struct Edge {
    int from, to, weight;
};

// Define a function to compare edges for sorting
bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

class KruskalAlgorithm {
public:
    KruskalAlgorithm(int n) : numVertices(n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    void addEdge(int from, int to, int weight) {
        edges.push({from, to, weight});
    }

    int find(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find(parent[v]);
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            parent[a] = b;
            return true; // The vertices were in different sets
        }
        return false; // The vertices were already in the same set
    }

    void findMinimumSpanningTree() {
        int totalWeight = 0;
        while (!edges.empty()) {
            Edge currentEdge = edges.top();
            edges.pop();

            if (unite(currentEdge.from, currentEdge.to)) {
                cout << "Edge: " << currentEdge.from << " - " << currentEdge.to << " (Weight: " << currentEdge.weight << ")" << endl;
                totalWeight += currentEdge.weight;
            }
        }
        cout << "Total Weight of Minimum Spanning Tree: " << totalWeight << endl;
    }

private:
    int numVertices;
    priority_queue<Edge, vector<Edge>, function<bool(Edge, Edge)>> edges{compareEdges};
    vector<int> parent;
};

int main() {
    int numVertices = 6;
    KruskalAlgorithm kruskal(numVertices);

    // Add edges to the graph
    kruskal.addEdge(0, 1, 4);
    kruskal.addEdge(0, 2, 4);
    kruskal.addEdge(1, 2, 2);
    kruskal.addEdge(1, 3, 3);
    kruskal.addEdge(1, 4, 4);
    kruskal.addEdge(2, 3, 5);
    kruskal.addEdge(3, 4, 7);
    kruskal.addEdge(3, 5, 2);
    kruskal.addEdge(4, 5, 5);

    cout << "Edges in Minimum Spanning Tree:" << endl;
    kruskal.findMinimumSpanningTree();

    return 0;
}
