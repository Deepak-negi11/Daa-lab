/*
 * Program: Kruskal's Minimum Spanning Tree Algorithm
 * Week: 8
 * Problem: 2
 * Algorithm: Kruskal's Algorithm (Greedy) with Union-Find
 * Time Complexity: O(E log E) for sorting + O(E * alpha(V)) for union-find
 *                  where alpha is inverse Ackermann (nearly constant)
 * Space Complexity: O(V^2) for adjacency matrix + O(E) for edge list
 *
 * Description:
 *   Finds the Minimum Spanning Tree (MST) of an undirected weighted graph.
 *   Sorts all edges by weight and greedily adds edges that don't form cycles.
 *   Uses Union-Find (Disjoint Set Union) with path compression and union by rank.
 */

#include <stdio.h>

#define MAX 100
#define MAX_EDGES (MAX * MAX / 2)

/* Edge structure */
typedef struct {
    int u, v, weight;
} Edge;

int parent[MAX]; // Parent array for Union-Find
int rank_arr[MAX]; // Rank array for Union-Find
int V;           // Number of vertices

/* Initialize Union-Find */
void makeSet(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank_arr[i] = 0;
    }
}

/* Find with path compression */
int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]); // Path compression
    return parent[x];
}

/* Union by rank */
void unionSets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX == rootY) return;

    // Attach smaller tree under root of larger tree
    if (rank_arr[rootX] < rank_arr[rootY])
        parent[rootX] = rootY;
    else if (rank_arr[rootX] > rank_arr[rootY])
        parent[rootY] = rootX;
    else {
        parent[rootY] = rootX;
        rank_arr[rootX]++;
    }
}

/* Comparison function for sorting edges by weight (ascending) */
void sortEdges(Edge edges[], int n) {
    // Simple selection sort (sufficient for lab-sized inputs)
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (edges[j].weight < edges[minIdx].weight)
                minIdx = j;
        }
        if (minIdx != i) {
            Edge temp = edges[i];
            edges[i] = edges[minIdx];
            edges[minIdx] = temp;
        }
    }
}

int main() {
    int graph[MAX][MAX];
    Edge edges[MAX_EDGES];
    int edgeCount = 0;

    // Read number of vertices
    scanf("%d", &V);

    // Read adjacency matrix and extract edges (upper triangle for undirected graph)
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
            // Only take upper triangle to avoid duplicate edges
            if (j > i && graph[i][j] != 0) {
                edges[edgeCount].u = i;
                edges[edgeCount].v = j;
                edges[edgeCount].weight = graph[i][j];
                edgeCount++;
            }
        }
    }

    // Sort edges by weight in ascending order
    sortEdges(edges, edgeCount);

    // Initialize Union-Find
    makeSet(V);

    int mstWeight = 0;
    int mstEdges = 0;

    // Process edges in order of increasing weight
    for (int i = 0; i < edgeCount && mstEdges < V - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;

        // Check if adding this edge creates a cycle
        if (find(u) != find(v)) {
            unionSets(u, v);
            mstWeight += edges[i].weight;
            mstEdges++;
        }
    }

    printf("Minimum Spanning Weight: %d\n", mstWeight);

    return 0;
}
