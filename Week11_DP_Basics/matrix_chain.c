

#include <stdio.h>
#include <limits.h>

#define MAX 100

int main() {
    int n;
    int rows[MAX], cols[MAX];
    int p[MAX + 1]; 
    int m[MAX][MAX]; 
    int i, j, k, L, q;

    
    scanf("%d", &n);

    
    for (i = 0; i < n; i++) {
        scanf("%d %d", &rows[i], &cols[i]);
    }

    
    p[0] = rows[0];
    for (i = 0; i < n; i++) {
        p[i + 1] = cols[i];
    }

    

    
    for (i = 0; i < n; i++) {
        m[i][i] = 0;
    }

    
    for (L = 2; L <= n; L++) {
        for (i = 0; i <= n - L; i++) {
            j = i + L - 1; 
            m[i][j] = INT_MAX;

            
            for (k = i; k < j; k++) {
                q = m[i][k] + m[k + 1][j] + p[i] * p[k + 1] * p[j + 1];
                if (q < m[i][j]) {
                    m[i][j] = q;
                }
            }
        }
    }

    
    printf("%d\n", m[0][n - 1]);

    return 0;
}
