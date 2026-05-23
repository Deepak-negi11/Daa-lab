/*
 * Program: Cycle Detection in Directed Graph
 * Week: 06
 * Problem: 3
 * Algorithm: DFS with Back-Edge Detection (3-color / White-Gray-Black)
 * Time Complexity: O(V^2) - adjacency matrix representation
 * Space Complexity: O(V) - color/state array + recursion stack
 *
 * Description:
 *   Given a directed graph represented as an adjacency matrix, detect
 *   whether a cycle exists. Uses DFS with three states:
 *     WHITE (0) = unvisited
 *     GRAY  (1) = currently in recursion stack (being processed)
 *     BLACK (2) = fully processed (all descendants visited)
 *   A back edge (edge to a GRAY vertex) indicates a cycle.
 *
 * Input Format:
 *   First line: V (number of vertices)
 *   Next V lines: V x V adjacency matrix (directed)
 *
 * Sample Input (Cycle: 0->1->2->0):
 *   3
 *   0 1 0
 *   0 0 1
 *   1 0 0
 *
 * Sample Output:
 *   Yes Cycle Exists
 *
 * Sample Input (No Cycle: DAG 0->1->2):
 *   3
 *   0 1 0
 *   0 0 1
 *   0 0 0
 *
 * Sample Output:
 *   No Cycle Exists
 *
 * Compile: gcc cycle_detection.c -o cycle_detection
 */

#include <stdio.h>

#define MAX_V 100

// Vertex states for DFS
#define WHITE 0  // Unvisited
#define GRAY  1  // In current DFS path (recursion stack)
#define BLACK 2  // Fully processed

int adj[MAX_V][MAX_V]; // Adjacency matrix (directed graph)
int state[MAX_V];       // State of each vertex: WHITE, GRAY, or BLACK
int V;                  // Number of vertices

/*
 * DFS from vertex u to detect back edges.
 * Returns 1 if a cycle is found, 0 otherwise.
 *
 * Logic:
 *   - Mark u as GRAY (currently exploring).
 *   - For each neighbor v of u:
 *       - If v is GRAY, we found a back edge => cycle exists.
 *       - If v is WHITE, recurse on v.
 *   - After exploring all neighbors, mark u as BLACK (done).
 */
int dfsCycleDetect(int u) {
    state[u] = GRAY; // Mark as currently being processed

    for (int v = 0; v < V; v++) {
        if (adj[u][v] == 1) { // Directed edge from u to v
            if (state[v] == GRAY) {
                // Back edge found: v is an ancestor in current DFS path
                return 1; // Cycle detected
            }
            if (state[v] == WHITE) {
                // Unvisited vertex: recurse
                if (dfsCycleDetect(v)) {
                    return 1; // Propagate cycle detection
                }
            }
            // If state[v] == BLACK, v is already fully processed, skip
        }
    }

    state[u] = BLACK; // All descendants processed, mark as done
    return 0;         // No cycle found from this vertex
}

int main() {
    scanf("%d", &V); // Read number of vertices

    // Read adjacency matrix
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    // Initialize all vertices as WHITE (unvisited)
    for (int i = 0; i < V; i++) {
        state[i] = WHITE;
    }

    /*
     * Run DFS from every unvisited vertex to handle
     * disconnected components in the directed graph.
     */
    int cycleFound = 0;
    for (int i = 0; i < V; i++) {
        if (state[i] == WHITE) {
            if (dfsCycleDetect(i)) {
                cycleFound = 1;
                break;
            }
        }
    }

    if (cycleFound) {
        printf("Yes Cycle Exists\n");
    } else {
        printf("No Cycle Exists\n");
    }

    return 0;
}
