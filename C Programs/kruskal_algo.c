#include <stdio.h>
#include <stdlib.h>

struct Edge {
    int src, dest, weight;
};

struct Graph {
    int V, E;
    struct Edge* edges;
};

struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edges = (struct Edge*)malloc(E * sizeof(struct Edge));
    return graph;
}

int compareEdges(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

int find(int parent[], int i) {
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

void unionSets(int parent[], int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}

void kruskalMST(struct Graph* graph) {
    int V = graph->V;
    struct Edge result[V];
    int e = 0;

    qsort(graph->edges, graph->E, sizeof(graph->edges[0]), compareEdges);

    int* parent = (int*)malloc(V * sizeof(int));
    for (int i = 0; i < V; i++)
        parent[i] = -1;

    for (int i = 0; e < V - 1 && i < graph->E; i++) {
        struct Edge next_edge = graph->edges[i];
        int x = find(parent, next_edge.src);
        int y = find(parent, next_edge.dest);
        if (x != y) {
            result[e++] = next_edge;
            unionSets(parent, x, y);
        }
    }

    printf("Edges in the Minimum Spanning Tree:\n");
    for (int i = 0; i < e; i++)
        printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);
}

int main() {
    int V, E;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the number of edges: ");
    scanf("%d", &E);

    struct Graph* graph = createGraph(V, E);

    printf("Enter the edges (src dest weight):\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &graph->edges[i].src, &graph->edges[i].dest, &graph->edges[i].weight);
    }

    kruskalMST(graph);

    return 0;
}
