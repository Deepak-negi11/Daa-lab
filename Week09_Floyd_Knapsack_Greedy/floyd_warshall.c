/*
 * Program: Floyd-Warshall All-Pairs Shortest Path
 * Week: 9
 * Problem: 1
 * Algorithm: Floyd-Warshall Dynamic Programming
 * Time Complexity: O(V^3)
 * Space Complexity: O(V^2)
 *
 * Description:
 *   Given a weighted adjacency matrix (with INF for no direct edge),
 *   compute the shortest distance between every pair of vertices.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INF 99999
#define MAX 100

int dist[MAX][MAX]; // Shortest distance matrix

/*
 * Floyd-Warshall Algorithm:
 *   For each intermediate vertex k (0..V-1),
 *     for each source i,
 *       for each destination j,
 *         if dist[i][k] + dist[k][j] < dist[i][j],
 *           update dist[i][j].
 */
void floydWarshall(int V) {
    int i, j, k;
    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                // Avoid overflow: only update if neither sub-path is INF
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }
}

int main() {
    int V, i, j;
    char token[20];

    // Read number of vertices
    scanf("%d", &V);

    // Read adjacency matrix, handling "INF" strings
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            scanf("%s", token);
            if (strcmp(token, "INF") == 0) {
                dist[i][j] = INF;
            } else {
                dist[i][j] = atoi(token);
            }
        }
    }

    // Run Floyd-Warshall
    floydWarshall(V);

    // Print the shortest distance matrix
    printf("Shortest Distance Matrix:\n");
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            if (j > 0) printf(" ");
            if (dist[i][j] >= INF) {
                printf("INF");
            } else {
                printf("%d", dist[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}
