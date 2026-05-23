/*
 * Program: Shortest Path with Exactly K Edges
 * Week: 7
 * Problem: 3
 * Algorithm: Dynamic Programming
 * Time Complexity: O(V^3 * K)
 * Space Complexity: O(V^2 * K) for DP table
 *
 * Description:
 *   Given a directed weighted graph, finds the shortest path weight from
 *   source to destination using exactly k edges.
 *   Uses DP where dp[e][u] = shortest path from source to u using exactly e edges.
 */

#include <stdio.h>
#include <limits.h>

#define MAX 100
#define INF INT_MAX

int graph[MAX][MAX]; // Adjacency matrix
int V;               // Number of vertices

/*
 * Find shortest path from src to dst with exactly k edges.
 * dp[e][v] = minimum weight path from src to v using exactly e edges.
 */
int shortestPathKEdges(int src, int dst, int k) {
    // dp[e][v]: min weight to reach v from src using exactly e edges
    int dp[MAX + 1][MAX];

    // Base case: 0 edges
    for (int v = 0; v < V; v++)
        dp[0][v] = INF;
    dp[0][src] = 0; // Source to itself with 0 edges = 0

    // Fill DP table for 1 to k edges
    for (int e = 1; e <= k; e++) {
        for (int v = 0; v < V; v++) {
            dp[e][v] = INF;
            // Try all possible predecessors u
            for (int u = 0; u < V; u++) {
                if (graph[u][v] != 0 && dp[e - 1][u] != INF) {
                    int newDist = dp[e - 1][u] + graph[u][v];
                    if (newDist < dp[e][v]) {
                        dp[e][v] = newDist;
                    }
                }
            }
        }
    }

    return dp[k][dst];
}

int main() {
    int src, dst, k;

    // Read number of vertices
    scanf("%d", &V);

    // Read adjacency matrix (0 means no edge)
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &graph[i][j]);

    // Read source and destination (1-indexed input)
    scanf("%d %d", &src, &dst);
    src--; dst--; // Convert to 0-indexed

    // Read number of edges
    scanf("%d", &k);

    // Find shortest path with exactly k edges
    int result = shortestPathKEdges(src, dst, k);

    if (result == INF) {
        printf("no path of length %d is available\n", k);
    } else {
        // Output uses 1-indexed vertices
        printf("Weight of shortest path from (%d,%d) with %d edges : %d\n",
               src + 1, dst + 1, k, result);
    }

    return 0;
}
