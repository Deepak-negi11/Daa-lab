

#include <stdio.h>
#include <limits.h>

#define MAX 100
#define INF INT_MAX

int graph[MAX][MAX]; 
int V;               

int shortestPathKEdges(int src, int dst, int k) {
    
    int dp[MAX + 1][MAX];

    
    for (int v = 0; v < V; v++)
        dp[0][v] = INF;
    dp[0][src] = 0; 

    
    for (int e = 1; e <= k; e++) {
        for (int v = 0; v < V; v++) {
            dp[e][v] = INF;
            
            for (int u = 0; u < V; u++) {
                if (graph[u][v] != 0 && dp[e - 1][u] != INF) {
                    int newDist = dp[e - 1][u] + graph[u][v];
                    if (newDist < dp[e][v]) {
                        dp[e][v] = newDist;
                    }
                }
            }
        }
    }

    return dp[k][dst];
}

int main() {
    int src, dst, k;

    
    scanf("%d", &V);

    
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &graph[i][j]);

    
    scanf("%d %d", &src, &dst);
    src--; dst--; 

    
    scanf("%d", &k);

    
    int result = shortestPathKEdges(src, dst, k);

    if (result == INF) {
        printf("no path of length %d is available\n", k);
    } else {
        
        printf("Weight of shortest path from (%d,%d) with %d edges : %d\n",
               src + 1, dst + 1, k, result);
    }

    return 0;
}
