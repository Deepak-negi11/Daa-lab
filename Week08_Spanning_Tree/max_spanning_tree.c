

#include <stdio.h>

#define MAX 100
#define MAX_EDGES (MAX * MAX / 2)

typedef struct {
    int u, v, weight;
} Edge;

int parent[MAX];   
int rank_arr[MAX];  
int V;              

void makeSet(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank_arr[i] = 0;
    }
}

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unionSets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX == rootY) return;

    if (rank_arr[rootX] < rank_arr[rootY])
        parent[rootX] = rootY;
    else if (rank_arr[rootX] > rank_arr[rootY])
        parent[rootY] = rootX;
    else {
        parent[rootY] = rootX;
        rank_arr[rootX]++;
    }
}

void sortEdgesDesc(Edge edges[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int maxIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (edges[j].weight > edges[maxIdx].weight)
                maxIdx = j;
        }
        if (maxIdx != i) {
            Edge temp = edges[i];
            edges[i] = edges[maxIdx];
            edges[maxIdx] = temp;
        }
    }
}

int main() {
    int graph[MAX][MAX];
    Edge edges[MAX_EDGES];
    int edgeCount = 0;

    
    scanf("%d", &V);

    
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
            if (j > i && graph[i][j] != 0) {
                edges[edgeCount].u = i;
                edges[edgeCount].v = j;
                edges[edgeCount].weight = graph[i][j];
                edgeCount++;
            }
        }
    }

    
    sortEdgesDesc(edges, edgeCount);

    
    makeSet(V);

    int maxWeight = 0;
    int mstEdges = 0;

    
    for (int i = 0; i < edgeCount && mstEdges < V - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;

        
        if (find(u) != find(v)) {
            unionSets(u, v);
            maxWeight += edges[i].weight;
            mstEdges++;
        }
    }

    printf("Maximum Spanning Weight: %d\n", maxWeight);

    return 0;
}
