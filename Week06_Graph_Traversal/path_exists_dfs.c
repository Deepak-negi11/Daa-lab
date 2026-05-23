/*
 * Program: Path Existence using DFS
 * Week: 06
 * Problem: 1
 * Algorithm: Depth-First Search (DFS)
 * Time Complexity: O(V^2) - adjacency matrix representation
 * Space Complexity: O(V) - visited array + recursion stack
 *
 * Description:
 *   Given a graph represented as an adjacency matrix, determine if
 *   a path exists between a given source and destination vertex using DFS.
 *
 * Input Format:
 *   First line: V (number of vertices)
 *   Next V lines: V x V adjacency matrix
 *   Last line: source and destination vertices (0-indexed)
 *
 * Sample Input:
 *   5
 *   0 1 0 0 0
 *   1 0 1 0 0
 *   0 1 0 1 0
 *   0 0 1 0 1
 *   0 0 0 1 0
 *   0 4
 *
 * Sample Output:
 *   Yes Path Exists
 *
 * Compile: gcc path_exists_dfs.c -o path_exists_dfs
 */

#include <stdio.h>

#define MAX_V 100

int adj[MAX_V][MAX_V]; // Adjacency matrix
int visited[MAX_V];     // Visited array for DFS
int V;                  // Number of vertices

/*
 * DFS traversal from vertex u.
 * Marks all reachable vertices as visited.
 */
void dfs(int u) {
    visited[u] = 1; // Mark current vertex as visited

    // Explore all adjacent vertices
    for (int v = 0; v < V; v++) {
        // If there's an edge and vertex not yet visited
        if (adj[u][v] == 1 && !visited[v]) {
            dfs(v); // Recursively visit
        }
    }
}

int main() {
    scanf("%d", &V); // Read number of vertices

    // Read adjacency matrix
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    int src, dest;
    scanf("%d %d", &src, &dest); // Read source and destination

    // Initialize visited array to 0
    for (int i = 0; i < V; i++) {
        visited[i] = 0;
    }

    // Perform DFS from source vertex
    dfs(src);

    // Check if destination was reached during DFS
    if (visited[dest]) {
        printf("Yes Path Exists\n");
    } else {
        printf("No Such Path Exists\n");
    }

    return 0;
}
