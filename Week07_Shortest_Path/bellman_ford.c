

#include <stdio.h>
#include <limits.h>

#define MAX 100
#define INF INT_MAX

int graph[MAX][MAX]; 
int dist[MAX];       
int parent[MAX];     
int V;               

void printPath(int v) {
    if (parent[v] == -1) {
        printf("%d", v + 1); 
        return;
    }
    printf("%d ", v + 1);
    printPath(parent[v]);
}

void bellmanFord(int src) {
    
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }
    dist[src] = 0; 

    
    for (int iter = 0; iter < V - 1; iter++) {
        
        for (int u = 0; u < V; u++) {
            for (int v = 0; v < V; v++) {
                
                if (graph[u][v] != 0 && dist[u] != INF &&
                    dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                    parent[v] = u;
                }
            }
        }
    }

    
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

    
    scanf("%d", &V);

    
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &graph[i][j]);

    
    scanf("%d", &src);
    src--; 

    
    bellmanFord(src);

    
    for (int i = 0; i < V; i++) {
        printPath(i);
        printf(" : %d\n", dist[i]);
    }

    return 0;
}
