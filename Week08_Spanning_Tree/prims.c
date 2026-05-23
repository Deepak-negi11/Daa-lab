/*
 * Program: Prim's Minimum Spanning Tree Algorithm
 * Week: 8
 * Problem: 1
 * Algorithm: Prim's Algorithm (Greedy)
 * Time Complexity: O(V^2) using adjacency matrix
 * Space Complexity: O(V^2) for adjacency matrix + O(V) for key/inMST
 *
 * Description:
 *   Finds the Minimum Spanning Tree (MST) of an undirected weighted graph.
 *   Starts from vertex 0 and greedily adds the minimum weight edge
 *   that connects a vertex in the MST to one outside it.
 */

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 100
#define INF INT_MAX

int graph[MAX][MAX]; // Adjacency matrix
int key[MAX];        // Key values used to pick minimum weight edge
bool inMST[MAX];     // Track vertices included in MST
int V;               // Number of vertices

/* Find the vertex with minimum key value not yet in MST */
int minKeyVertex() {
    int min = INF, minIdx = -1;
    for (int v = 0; v < V; v++) {
        if (!inMST[v] && key[v] < min) {
            min = key[v];
            minIdx = v;
        }
    }
    return minIdx;
}

/* Prim's algorithm - returns total MST weight */
int primMST() {
    int totalWeight = 0;

    // Initialize all keys as INF, none in MST
    for (int i = 0; i < V; i++) {
        key[i] = INF;
        inMST[i] = false;
    }

    key[0] = 0; // Start from vertex 0

    // MST has V vertices, so we need V iterations
    for (int count = 0; count < V; count++) {
        int u = minKeyVertex(); // Pick vertex with minimum key
        if (u == -1) break;

        inMST[u] = true;       // Include vertex in MST
        totalWeight += key[u];  // Add edge weight to total

        // Update keys of adjacent vertices
        for (int v = 0; v < V; v++) {
            // graph[u][v] != 0 means edge exists
            // v not in MST and edge weight < current key
            if (graph[u][v] != 0 && !inMST[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
            }
        }
    }

    return totalWeight;
}

int main() {
    // Read number of vertices
    scanf("%d", &V);

    // Read adjacency matrix (0 means no edge)
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &graph[i][j]);

    // Run Prim's algorithm and print result
    int mstWeight = primMST();
    printf("Minimum Spanning Weight: %d\n", mstWeight);

    return 0;
}
