/*
 * Program: Bipartite Check using BFS
 * Week: 06
 * Problem: 2
 * Algorithm: Breadth-First Search (BFS) with 2-Coloring
 * Time Complexity: O(V^2) - adjacency matrix representation
 * Space Complexity: O(V) - color array + BFS queue
 *
 * Description:
 *   Given a graph represented as an adjacency matrix, check if it is bipartite
 *   using BFS. A graph is bipartite if its vertices can be divided into two
 *   disjoint sets such that every edge connects a vertex in one set to a
 *   vertex in the other set. This is equivalent to 2-colorability.
 *
 * Input Format:
 *   First line: V (number of vertices)
 *   Next V lines: V x V adjacency matrix
 *
 * Sample Input (Bipartite - a simple path 0-1-2-3):
 *   4
 *   0 1 0 0
 *   1 0 1 0
 *   0 1 0 1
 *   0 0 1 0
 *
 * Sample Output:
 *   Yes Bipartite
 *
 * Sample Input (Not Bipartite - triangle 0-1-2):
 *   3
 *   0 1 1
 *   1 0 1
 *   1 1 0
 *
 * Sample Output:
 *   Not Bipartite
 *
 * Compile: gcc bipartite_bfs.c -o bipartite_bfs
 */

#include <stdio.h>

#define MAX_V 100

int adj[MAX_V][MAX_V]; // Adjacency matrix
int color[MAX_V];       // Color array: -1 = uncolored, 0 = color A, 1 = color B
int V;                  // Number of vertices

/*
 * BFS-based bipartite check starting from vertex src.
 * Attempts to 2-color the component containing src.
 * Returns 1 if the component is bipartite, 0 otherwise.
 */
int bfsBipartiteCheck(int src) {
    // Simple queue implementation using array
    int queue[MAX_V];
    int front = 0, rear = 0;

    color[src] = 0;          // Color source with color 0
    queue[rear++] = src;     // Enqueue source

    while (front < rear) {
        int u = queue[front++]; // Dequeue

        // Check all adjacent vertices
        for (int v = 0; v < V; v++) {
            if (adj[u][v] == 1) { // Edge exists between u and v
                if (color[v] == -1) {
                    // Not yet colored: assign opposite color
                    color[v] = 1 - color[u];
                    queue[rear++] = v; // Enqueue
                } else if (color[v] == color[u]) {
                    // Adjacent vertex has same color: NOT bipartite
                    return 0;
                }
                // If color[v] != color[u], it's fine, continue
            }
        }
    }

    return 1; // This component is bipartite
}

int main() {
    scanf("%d", &V); // Read number of vertices

    // Read adjacency matrix
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    // Initialize all vertices as uncolored
    for (int i = 0; i < V; i++) {
        color[i] = -1;
    }

    /*
     * Check bipartiteness for each connected component.
     * A graph is bipartite only if ALL components are bipartite.
     */
    int isBipartite = 1;
    for (int i = 0; i < V; i++) {
        if (color[i] == -1) { // Unvisited component
            if (!bfsBipartiteCheck(i)) {
                isBipartite = 0;
                break;
            }
        }
    }

    if (isBipartite) {
        printf("Yes Bipartite\n");
    } else {
        printf("Not Bipartite\n");
    }

    return 0;
}
