

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 100
#define INF INT_MAX

int graph[MAX][MAX]; 
int dist[MAX];       
int parent[MAX];     
bool visited[MAX];   
int V;               

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

void printPath(int v) {
    if (parent[v] == -1) {
        printf("%d", v + 1); 
        return;
    }
    printf("%d ", v + 1);
    printPath(parent[v]);
}

void dijkstra(int src) {
    
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = false;
        parent[i] = -1;
    }
    dist[src] = 0; 

    
    for (int count = 0; count < V; count++) {
        int u = minDistVertex(); 
        if (u == -1) break;      

        visited[u] = true;

        
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

    
    scanf("%d", &V);

    
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &graph[i][j]);

    
    scanf("%d", &src);
    src--; 

    
    dijkstra(src);

    
    for (int i = 0; i < V; i++) {
        printPath(i);
        printf(" : %d\n", dist[i]);
    }

    return 0;
}
