

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INF 99999
#define MAX 100

int dist[MAX][MAX]; 

void floydWarshall(int V) {
    int i, j, k;
    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                
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

    
    scanf("%d", &V);

    
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

    
    floydWarshall(V);

    
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
