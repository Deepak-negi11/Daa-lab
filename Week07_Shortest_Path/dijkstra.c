/*
 * Program: Dijkstra's Shortest Path Algorithm
 * Week: 7
 * Problem: 1
 * Algorithm: Dijkstra's Algorithm (Greedy)
 * Time Complexity: O(V^2) using adjacency matrix
 * Space Complexity: O(V^2) for adjacency matrix + O(V) for dist/visited/parent
 *
 * Description:
 *   Finds shortest path and distance from a source vertex to all other vertices
 *   in a weighted directed graph (non-negative weights).
 *   Paths are printed from destination back to source.
 */

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 100
#define INF INT_MAX

int graph[MAX][MAX]; // Adjacency matrix
int dist[MAX];       // Shortest distance from source
int parent[MAX];     // Parent array to reconstruct path
bool visited[MAX];   // Visited set
int V;               // Number of vertices

/* Find the unvisited vertex with minimum distance */
int minDistVertex() {
    int min = INF, minIdx = -1;
    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] < min) {
            min = dist[v];
            minIdx = v;
        }
    }
    return minIdx;
}

/* Print path from source to vertex v (destination to source order, 1-indexed) */
void printPath(int v) {
    if (parent[v] == -1) {
        printf("%d", v + 1); // 1-indexed output
        return;
    }
    printf("%d ", v + 1);
    printPath(parent[v]);
}

/* Dijkstra's algorithm */
void dijkstra(int src) {
    // Initialize distances as INF, all unvisited, no parent
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = false;
        parent[i] = -1;
    }
    dist[src] = 0; // Distance to source is 0

    // Process all vertices
    for (int count = 0; count < V; count++) {
        int u = minDistVertex(); // Pick vertex with minimum distance
        if (u == -1) break;      // All remaining are unreachable

        visited[u] = true;

        // Update distances of adjacent vertices
        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] != 0 &&
                dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
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

    // Run Dijkstra's algorithm
    dijkstra(src);

    // Print results: path from destination to source with distance
    for (int i = 0; i < V; i++) {
        printPath(i);
        printf(" : %d\n", dist[i]);
    }

    return 0;
}
