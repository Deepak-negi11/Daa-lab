

#include <stdio.h>

#define MAX_V 100

int adj[MAX_V][MAX_V]; 
int visited[MAX_V];     
int V;                  

void dfs(int u) {
    visited[u] = 1; 

    
    for (int v = 0; v < V; v++) {
        
        if (adj[u][v] == 1 && !visited[v]) {
            dfs(v); 
        }
    }
}

int main() {
    scanf("%d", &V); 

    
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    int src, dest;
    scanf("%d %d", &src, &dest); 

    
    for (int i = 0; i < V; i++) {
        visited[i] = 0;
    }

    
    dfs(src);

    
    if (visited[dest]) {
        printf("Yes Path Exists\n");
    } else {
        printf("No Such Path Exists\n");
    }

    return 0;
}
