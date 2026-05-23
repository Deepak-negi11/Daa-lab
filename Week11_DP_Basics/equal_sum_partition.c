

#include <stdio.h>
#include <stdbool.h>

#define MAX_N 200
#define MAX_SUM 10000

int main() {
    int n;
    int arr[MAX_N];
    int totalSum = 0;
    int target;
    int i, j;

    
    
    bool dp[MAX_SUM + 1];

    
    scanf("%d", &n);

    
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        totalSum += arr[i];
    }

    
    if (totalSum % 2 != 0) {
        printf("no\n");
        return 0;
    }

    target = totalSum / 2;

    

    
    for (j = 0; j <= target; j++) {
        dp[j] = false;
    }
    dp[0] = true;

    
    for (i = 0; i < n; i++) {
        
        for (j = target; j >= arr[i]; j--) {
            if (dp[j - arr[i]]) {
                dp[j] = true;
            }
        }
    }

    if (dp[target]) {
        printf("yes\n");
    } else {
        printf("no\n");
    }

    return 0;
}
