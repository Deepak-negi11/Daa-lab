/*
 * Program: Longest Common Subsequence (LCS)
 * Week: 12
 * Problem: 1
 * Algorithm: Dynamic Programming (Bottom-Up) with Backtracking
 * Time Complexity: O(m * n) where m, n are lengths of the two strings
 * Space Complexity: O(m * n)
 *
 * Description:
 *   Given two strings, find their Longest Common Subsequence (LCS).
 *   A subsequence is a sequence derived from another by deleting some
 *   or no elements without changing the order. The program outputs
 *   both the LCS string and its length.
 *
 * Compile: gcc lcs.c -o lcs
 */

#include <stdio.h>
#include <string.h>

#define MAX 1000

int main() {
    char s1[MAX + 1], s2[MAX + 1];
    int dp[MAX + 1][MAX + 1]; /* dp[i][j] = LCS length of s1[0..i-1] and s2[0..j-1] */
    char lcs[MAX + 1];        /* To store the LCS string */
    int m, n;
    int i, j, idx;

    /* Read two strings */
    scanf("%s", s1);
    scanf("%s", s2);

    m = strlen(s1);
    n = strlen(s2);

    /*
     * DP Recurrence:
     *   dp[i][j] = 0                              if i == 0 or j == 0
     *   dp[i][j] = dp[i-1][j-1] + 1               if s1[i-1] == s2[j-1]
     *   dp[i][j] = max(dp[i-1][j], dp[i][j-1])    otherwise
     */

    /* Base cases: first row and first column are 0 */
    for (i = 0; i <= m; i++) {
        dp[i][0] = 0;
    }
    for (j = 0; j <= n; j++) {
        dp[0][j] = 0;
    }

    /* Fill the DP table */
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

    /*
     * Backtrack to find the actual LCS string.
     * Start from dp[m][n] and trace back:
     *   - If s1[i-1] == s2[j-1], this char is in LCS; move diagonally.
     *   - Else, move in direction of larger value.
     */
    idx = dp[m][n]; /* Length of LCS */
    lcs[idx] = '\0';

    i = m;
    j = n;
    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            /* Current character is part of LCS */
            lcs[idx - 1] = s1[i - 1];
            i--;
            j--;
            idx--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--; /* Move up */
        } else {
            j--; /* Move left */
        }
    }

    printf("LCS: %s\n", lcs);
    printf("Length: %d\n", dp[m][n]);

    return 0;
}
