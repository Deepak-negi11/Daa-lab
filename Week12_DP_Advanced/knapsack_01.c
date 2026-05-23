/*
 * Program: 0-1 Knapsack
 * Week: 12
 * Problem: 2
 * Algorithm: Dynamic Programming (Bottom-Up) with Item Backtracking
 * Time Complexity: O(n * W) where n = number of items, W = capacity
 * Space Complexity: O(n * W)
 *
 * Description:
 *   Given n items each with a weight and value, and a knapsack of capacity W,
 *   determine the maximum value achievable by selecting items such that
 *   total weight <= W. Each item can be picked at most once (0-1 property).
 *   Also outputs which items were selected.
 *
 * Compile: gcc knapsack_01.c -o knapsack_01
 */

#include <stdio.h>

#define MAX_N 100
#define MAX_W 1000

int main() {
    int n, W;
    int wt[MAX_N], val[MAX_N];
    int dp[MAX_N + 1][MAX_W + 1]; /* dp[i][w] = max value using first i items with capacity w */
    int selected[MAX_N];          /* 1 if item is selected, 0 otherwise */
    int selCount = 0;
    int i, w;

    /* Read number of items */
    scanf("%d", &n);

    /* Read weights */
    for (i = 0; i < n; i++) {
        scanf("%d", &wt[i]);
    }

    /* Read values */
    for (i = 0; i < n; i++) {
        scanf("%d", &val[i]);
    }

    /* Read knapsack capacity */
    scanf("%d", &W);

    /*
     * DP Recurrence:
     *   dp[i][w] = 0                                           if i == 0 or w == 0
     *   dp[i][w] = dp[i-1][w]                                  if wt[i-1] > w (can't include)
     *   dp[i][w] = max(dp[i-1][w], dp[i-1][w-wt[i-1]] + val[i-1])  otherwise
     */

    /* Base cases */
    for (i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for (w = 0; w <= W; w++) {
        dp[0][w] = 0;
    }

    /* Fill the DP table */
    for (i = 1; i <= n; i++) {
        for (w = 1; w <= W; w++) {
            if (wt[i - 1] > w) {
                /* Item i is too heavy for current capacity */
                dp[i][w] = dp[i - 1][w];
            } else {
                /* Choose the better option: exclude or include item i */
                int exclude = dp[i - 1][w];
                int include = dp[i - 1][w - wt[i - 1]] + val[i - 1];
                dp[i][w] = (include > exclude) ? include : exclude;
            }
        }
    }

    /* Print maximum value */
    printf("Value = %d\n", dp[n][W]);

    /*
     * Backtrack to find which items were selected.
     * Starting from dp[n][W], if dp[i][w] != dp[i-1][w],
     * then item i was included.
     */
    w = W;
    for (i = n; i > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            selected[selCount++] = i - 1; /* Store 0-indexed item number */
            w -= wt[i - 1];
        }
    }

    /* Print selected weights (in original order) */
    printf("Weights selected :");
    for (i = selCount - 1; i >= 0; i--) {
        printf(" %d", wt[selected[i]]);
    }
    printf("\n");

    /* Print values of selected weights (in original order) */
    printf("Values of selected weights :");
    for (i = selCount - 1; i >= 0; i--) {
        printf(" %d", val[selected[i]]);
    }
    printf("\n");

    return 0;
}
