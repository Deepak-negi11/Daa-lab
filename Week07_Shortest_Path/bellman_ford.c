/*
 * Program: Bellman-Ford's Shortest Path Algorithm
 * Week: 7
 * Problem: 2
 * Algorithm: Bellman-Ford Algorithm (Dynamic Programming)
 * Time Complexity: O(V * E) = O(V^3) with adjacency matrix
 * Space Complexity: O(V^2) for adjacency matrix + O(V) for dist/parent
 *
 * Description:
 *   Finds shortest path and distance from a source vertex to all other vertices.
 *   Works with negative weight edges (unlike Dijkstra).
 *   Relaxes all edges V-1 times.
 *   Paths are printed from destination back to source.
 */

#include <stdio.h>
#include <limits.h>

#define MAX 100
#define INF INT_MAX

int graph[MAX][MAX]; // Adjacency matrix
int dist[MAX];       // Shortest distance from source
int parent[MAX];     // Parent array to reconstruct path
int V;               // Number of vertices

/* Print path from source to vertex v (destination to source order, 1-indexed) */
void printPath(int v) {
    if (parent[v] == -1) {
        printf("%d", v + 1); // 1-indexed output
        return;
    }
    printf("%d ", v + 1);
    printPath(parent[v]);
}

/* Bellman-Ford algorithm */
void bellmanFord(int src) {
    // Initialize distances as INF, no parent
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }
    dist[src] = 0; // Distance to source is 0

    // Relax all edges V-1 times
    for (int iter = 0; iter < V - 1; iter++) {
        // For each edge (u, v) with weight graph[u][v]
        for (int u = 0; u < V; u++) {
            for (int v = 0; v < V; v++) {
                // Check if edge exists and relaxation is possible
                if (graph[u][v] != 0 && dist[u] != INF &&
                    dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                    parent[v] = u;
                }
            }
        }
    }

    // Check for negative weight cycles (optional but good practice)
    for (int u = 0; u < V; u++) {
        for (int v = 0; v < V; v++) {
            if (graph[u][v] != 0 && dist[u] != INF &&
                dist[u] + graph[u][v] < dist[v]) {
                printf("Graph contains a negative weight cycle!\n");
                return;
            }
        }
    }
}

int main() {
    int src;

    // Read number of vertices
    scanf("%d", &V);

    // Read adjacency matrix (0 means no edge)
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &graph[i][j]);

    // Read source vertex (1-indexed input)
    scanf("%d", &src);
    src--; // Convert to 0-indexed

    // Run Bellman-Ford algorithm
    bellmanFord(src);

    // Print results: path from destination to source with distance
    for (int i = 0; i < V; i++) {
        printPath(i);
        printf(" : %d\n", dist[i]);
    }

    return 0;
}
