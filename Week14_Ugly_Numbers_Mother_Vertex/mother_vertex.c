

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_V 100

int adj[MAX_V][MAX_V];  
bool visited[MAX_V];     
int V;                   

void dfs(int u) {
    visited[u] = true;
    for (int v = 0; v < V; v++) {
        if (adj[u][v] == 1 && !visited[v]) {
            dfs(v);
        }
    }
}

int findMotherVertex() {
    int candidate = -1;

    
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i);
            candidate = i;  
        }
    }

    
    memset(visited, false, sizeof(visited));
    dfs(candidate);

    
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            return -1;  
        }
    }

    return candidate;
}

int main() {
    
    scanf("%d", &V);

    
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    
    int mother = findMotherVertex();

    if (mother != -1) {
        printf("Mother Vertex: %d\n", mother);
    } else {
        printf("No Mother Vertex exists\n");
    }

    return 0;
}

