

#include <stdio.h>

#define MAX_V 100

#define WHITE 0  
#define GRAY  1  
#define BLACK 2  

int adj[MAX_V][MAX_V]; 
int state[MAX_V];       
int V;                  

int dfsCycleDetect(int u) {
    state[u] = GRAY; 

    for (int v = 0; v < V; v++) {
        if (adj[u][v] == 1) { 
            if (state[v] == GRAY) {
                
                return 1; 
            }
            if (state[v] == WHITE) {
                
                if (dfsCycleDetect(v)) {
                    return 1; 
                }
            }
            
        }
    }

    state[u] = BLACK; 
    return 0;         
}

int main() {
    scanf("%d", &V); 

    
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    
    for (int i = 0; i < V; i++) {
        state[i] = WHITE;
    }

    
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
