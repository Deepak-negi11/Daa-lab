

#include <stdio.h>

#define MAX_N 100
#define MAX_W 1000

int main() {
    int n, W;
    int wt[MAX_N], val[MAX_N];
    int dp[MAX_N + 1][MAX_W + 1]; 
    int selected[MAX_N];          
    int selCount = 0;
    int i, w;

    
    scanf("%d", &n);

    
    for (i = 0; i < n; i++) {
        scanf("%d", &wt[i]);
    }

    
    for (i = 0; i < n; i++) {
        scanf("%d", &val[i]);
    }

    
    scanf("%d", &W);

    

    
    for (i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for (w = 0; w <= W; w++) {
        dp[0][w] = 0;
    }

    
    for (i = 1; i <= n; i++) {
        for (w = 1; w <= W; w++) {
            if (wt[i - 1] > w) {
                
                dp[i][w] = dp[i - 1][w];
            } else {
                
                int exclude = dp[i - 1][w];
                int include = dp[i - 1][w - wt[i - 1]] + val[i - 1];
                dp[i][w] = (include > exclude) ? include : exclude;
            }
        }
    }

    
    printf("Value = %d\n", dp[n][W]);

    
    w = W;
    for (i = n; i > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            selected[selCount++] = i - 1; 
            w -= wt[i - 1];
        }
    }

    
    printf("Weights selected :");
    for (i = selCount - 1; i >= 0; i--) {
        printf(" %d", wt[selected[i]]);
    }
    printf("\n");

    
    printf("Values of selected weights :");
    for (i = selCount - 1; i >= 0; i--) {
        printf(" %d", val[selected[i]]);
    }
    printf("\n");

    return 0;
}
