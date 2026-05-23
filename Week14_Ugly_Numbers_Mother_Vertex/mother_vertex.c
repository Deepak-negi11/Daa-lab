/*
 * Program    : Mother Vertex in a Directed Graph
 * Week       : 14
 * Problem    : 2
 * Algorithm  : Kosaraju's Approach (DFS-based)
 * Time Complexity  : O(V^2) using adjacency matrix (O(V + E) with adjacency list)
 * Space Complexity : O(V) for visited array and recursion stack
 *
 * Description:
 *   A mother vertex in a directed graph G = (V, E) is a vertex v such that
 *   all other vertices in G can be reached by a path from v.
 *
 *   Algorithm (Kosaraju's approach):
 *     Step 1: Perform DFS on all vertices. The last vertex to finish DFS
 *             is a candidate for mother vertex (similar to finding the
 *             vertex with the highest finish time).
 *     Step 2: Verify the candidate by doing a DFS from it. If all vertices
 *             are reachable, it is indeed a mother vertex.
 *
 *   Why this works:
 *     If a mother vertex exists, it must have the highest finish time in
 *     a DFS traversal (since it can reach all others). The last finished
 *     vertex is the best candidate.
 *
 * Input Format:
 *   First line: V (number of vertices)
 *   Next V lines: V x V adjacency matrix (0/1)
 *
 * Output Format:
 *   "Mother Vertex: <vertex_number>" (0-indexed)
 *   or "No Mother Vertex exists" if none found.
 *
 * Sample Test Case (in comments):
 *   Graph with 7 vertices:
 *     0 -> 1, 0 -> 2
 *     1 -> 3
 *     2 -> 3
 *     3 -> (no outgoing)
 *     4 -> 1
 *     5 -> 2, 5 -> 6
 *     6 -> 0, 6 -> 4
 *
 *   Adjacency Matrix:
 *     0 1 1 0 0 0 0
 *     0 0 0 1 0 0 0
 *     0 0 0 1 0 0 0
 *     0 0 0 0 0 0 0
 *     0 1 0 0 0 0 0
 *     0 0 1 0 0 0 1
 *     1 0 0 0 1 0 0
 *
 *   Mother Vertex: 5
 *   (From 5: 5->2->3, 5->6->0->1->3, 5->6->4->1->3. All vertices reachable.)
 *
 * Compile: gcc mother_vertex.c -o mother_vertex
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_V 100

int adj[MAX_V][MAX_V];  /* Adjacency matrix */
bool visited[MAX_V];     /* Visited array for DFS */
int V;                   /* Number of vertices */

/*
 * DFS from vertex u.
 * Marks all reachable vertices as visited.
 */
void dfs(int u) {
    visited[u] = true;
    for (int v = 0; v < V; v++) {
        if (adj[u][v] == 1 && !visited[v]) {
            dfs(v);
        }
    }
}

/*
 * Find mother vertex using Kosaraju's approach:
 *   1. Do DFS for each unvisited vertex; the last one to finish is candidate.
 *   2. Verify by doing DFS from candidate and checking all vertices are reached.
 * Returns mother vertex index (0-indexed), or -1 if none exists.
 */
int findMotherVertex() {
    int candidate = -1;

    /* Step 1: Do DFS from every unvisited vertex.
     * The last vertex that starts a DFS (and finishes last) is the candidate.
     * This is based on the property that the mother vertex will be the
     * last to finish in a complete DFS traversal.
     */
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i);
            candidate = i;  /* Update candidate to last DFS root */
        }
    }

    /*
     * Step 2: Verify the candidate.
     * Reset visited and do DFS from candidate.
     * If all vertices are visited, candidate is a mother vertex.
     */
    memset(visited, false, sizeof(visited));
    dfs(candidate);

    /* Check if all vertices were reached */
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            return -1;  /* Not all vertices reachable; no mother vertex */
        }
    }

    return candidate;
}

int main() {
    /* Read number of vertices */
    scanf("%d", &V);

    /* Read adjacency matrix */
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    /* Find and print mother vertex */
    int mother = findMotherVertex();

    if (mother != -1) {
        printf("Mother Vertex: %d\n", mother);
    } else {
        printf("No Mother Vertex exists\n");
    }

    return 0;
}

/*
 * ======================== TEST CASES ========================
 *
 * Test Case 1:
 * Input:
 * 7
 * 0 1 1 0 0 0 0
 * 0 0 0 1 0 0 0
 * 0 0 0 1 0 0 0
 * 0 0 0 0 0 0 0
 * 0 1 0 0 0 0 0
 * 0 0 1 0 0 0 1
 * 1 0 0 0 1 0 0
 *
 * Expected Output:
 * Mother Vertex: 5
 *
 * Explanation:
 *   From vertex 5: 5->2->3 (reaches 2,3)
 *                  5->6->0->1->3 (reaches 6,0,1)
 *                  5->6->4->1 (reaches 4)
 *   All 7 vertices (0-6) reachable from 5.
 *
 * Test Case 2:
 * Input:
 * 4
 * 0 1 0 0
 * 0 0 0 0
 * 0 0 0 1
 * 0 0 0 0
 *
 * Expected Output:
 * No Mother Vertex exists
 *
 * Explanation:
 *   Vertex 0 can reach 1 but not 2,3.
 *   Vertex 2 can reach 3 but not 0,1.
 *   No single vertex can reach all others.
 *
 * Test Case 3:
 * Input:
 * 3
 * 0 1 1
 * 0 0 1
 * 0 0 0
 *
 * Expected Output:
 * Mother Vertex: 0
 *
 * Explanation:
 *   From vertex 0: 0->1->2, 0->2. All vertices reachable.
 * =============================================================
 */
