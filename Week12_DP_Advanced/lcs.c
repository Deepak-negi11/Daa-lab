

#include <stdio.h>
#include <string.h>

#define MAX 1000

int main() {
    char s1[MAX + 1], s2[MAX + 1];
    int dp[MAX + 1][MAX + 1]; 
    char lcs[MAX + 1];        
    int m, n;
    int i, j, idx;

    
    scanf("%s", s1);
    scanf("%s", s2);

    m = strlen(s1);
    n = strlen(s2);

    

    
    for (i = 0; i <= m; i++) {
        dp[i][0] = 0;
    }
    for (j = 0; j <= n; j++) {
        dp[0][j] = 0;
    }

    
    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else if (dp[i - 1][j] >= dp[i][j - 1]) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = dp[i][j - 1];
            }
        }
    }

    
    idx = dp[m][n]; 
    lcs[idx] = '\0';

    i = m;
    j = n;
    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            
            lcs[idx - 1] = s1[i - 1];
            i--;
            j--;
            idx--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--; 
        } else {
            j--; 
        }
    }

    printf("LCS: %s\n", lcs);
    printf("Length: %d\n", dp[m][n]);

    return 0;
}
