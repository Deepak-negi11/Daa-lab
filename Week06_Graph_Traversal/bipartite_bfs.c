

#include <stdio.h>

#define MAX_V 100

int adj[MAX_V][MAX_V]; 
int color[MAX_V];       
int V;                  

int bfsBipartiteCheck(int src) {
    
    int queue[MAX_V];
    int front = 0, rear = 0;

    color[src] = 0;          
    queue[rear++] = src;     

    while (front < rear) {
        int u = queue[front++]; 

        
        for (int v = 0; v < V; v++) {
            if (adj[u][v] == 1) { 
                if (color[v] == -1) {
                    
                    color[v] = 1 - color[u];
                    queue[rear++] = v; 
                } else if (color[v] == color[u]) {
                    
                    return 0;
                }
                
            }
        }
    }

    return 1; 
}

int main() {
    scanf("%d", &V); 

    
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    
    for (int i = 0; i < V; i++) {
        color[i] = -1;
    }

    
    int isBipartite = 1;
    for (int i = 0; i < V; i++) {
        if (color[i] == -1) { 
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
