

#include <stdio.h>

#define MAX_COINS 100
#define MAX_SUM 10000

int main() {
    int n;          
    int coins[MAX_COINS];
    int N;          
    long long dp[MAX_SUM + 1]; 
    int i, j;

    
    scanf("%d", &n);

    
    for (i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }

    
    scanf("%d", &N);

    

    
    for (j = 0; j <= N; j++) {
        dp[j] = 0;
    }
    dp[0] = 1; 

    
    for (i = 0; i < n; i++) {
        for (j = coins[i]; j <= N; j++) {
            dp[j] += dp[j - coins[i]];
        }
    }

    printf("%lld\n", dp[N]);

    return 0;
}
