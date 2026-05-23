

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 100
#define INF INT_MAX

int graph[MAX][MAX]; 
int key[MAX];        
bool inMST[MAX];     
int V;               

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

int primMST() {
    int totalWeight = 0;

    
    for (int i = 0; i < V; i++) {
        key[i] = INF;
        inMST[i] = false;
    }

    key[0] = 0; 

    
    for (int count = 0; count < V; count++) {
        int u = minKeyVertex(); 
        if (u == -1) break;

        inMST[u] = true;       
        totalWeight += key[u];  

        
        for (int v = 0; v < V; v++) {
            
            
            if (graph[u][v] != 0 && !inMST[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
            }
        }
    }

    return totalWeight;
}

int main() {
    
    scanf("%d", &V);

    
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &graph[i][j]);

    
    int mstWeight = primMST();
    printf("Minimum Spanning Weight: %d\n", mstWeight);

    return 0;
}
