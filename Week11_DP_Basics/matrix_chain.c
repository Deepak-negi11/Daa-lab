/*
 * Program: Matrix Chain Multiplication
 * Week: 11
 * Problem: 1
 * Algorithm: Dynamic Programming (Bottom-Up)
 * Time Complexity: O(n^3)
 * Space Complexity: O(n^2)
 *
 * Description:
 *   Given a sequence of matrices, find the most efficient way to multiply
 *   them together. The problem is not to perform the multiplications, but
 *   to decide the order (parenthesization) that minimizes total scalar
 *   multiplications.
 *
 * Compile: gcc matrix_chain.c -o matrix_chain
 */

#include <stdio.h>
#include <limits.h>

#define MAX 100

int main() {
    int n;
    int rows[MAX], cols[MAX];
    int p[MAX + 1]; /* Dimension array: Matrix i has dimensions p[i-1] x p[i] */
    int m[MAX][MAX]; /* m[i][j] = minimum multiplications for matrices i..j */
    int i, j, k, L, q;

    /* Read number of matrices */
    scanf("%d", &n);

    /* Read dimensions of each matrix */
    for (i = 0; i < n; i++) {
        scanf("%d %d", &rows[i], &cols[i]);
    }

    /*
     * Build the dimension array p[] such that matrix i has dimensions
     * p[i] x p[i+1]. For a valid chain, cols[i] == rows[i+1].
     */
    p[0] = rows[0];
    for (i = 0; i < n; i++) {
        p[i + 1] = cols[i];
    }

    /*
     * DP Recurrence:
     *   m[i][j] = 0                                          if i == j
     *   m[i][j] = min over i <= k < j of:
     *             m[i][k] + m[k+1][j] + p[i]*p[k+1]*p[j+1]  if i < j
     *
     * We solve for increasing chain lengths L = 2, 3, ..., n.
     */

    /* Base case: cost of multiplying a single matrix is 0 */
    for (i = 0; i < n; i++) {
        m[i][i] = 0;
    }

    /* L is the chain length (number of matrices in the sub-chain) */
    for (L = 2; L <= n; L++) {
        for (i = 0; i <= n - L; i++) {
            j = i + L - 1; /* Ending index of sub-chain */
            m[i][j] = INT_MAX;

            /* Try all possible split points k */
            for (k = i; k < j; k++) {
                q = m[i][k] + m[k + 1][j] + p[i] * p[k + 1] * p[j + 1];
                if (q < m[i][j]) {
                    m[i][j] = q;
                }
            }
        }
    }

    /* The answer is the minimum cost to multiply matrices 0..n-1 */
    printf("%d\n", m[0][n - 1]);

    return 0;
}
