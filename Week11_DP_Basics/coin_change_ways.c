/*
 * Program: Coin Change - Number of Ways
 * Week: 11
 * Problem: 2
 * Algorithm: Dynamic Programming (Bottom-Up, Unbounded)
 * Time Complexity: O(n * N) where n = number of coin types, N = target sum
 * Space Complexity: O(N)
 *
 * Description:
 *   Given coin denominations with infinite supply, count the number of
 *   distinct ways to make change for a given value N. Each combination
 *   is counted once (order does not matter).
 *
 * Compile: gcc coin_change_ways.c -o coin_change_ways
 */

#include <stdio.h>

#define MAX_COINS 100
#define MAX_SUM 10000

int main() {
    int n;          /* Number of coin types */
    int coins[MAX_COINS];
    int N;          /* Target sum */
    long long dp[MAX_SUM + 1]; /* dp[j] = number of ways to make sum j */
    int i, j;

    /* Read number of coin types */
    scanf("%d", &n);

    /* Read coin values */
    for (i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }

    /* Read target sum */
    scanf("%d", &N);

    /*
     * DP Approach:
     *   dp[j] = number of ways to form sum j using coins considered so far.
     *   Initialize dp[0] = 1 (one way to make sum 0: use no coins).
     *
     *   For each coin, update dp[j] for all j >= coin value:
     *     dp[j] += dp[j - coins[i]]
     *
     *   By iterating coins in the outer loop, we ensure each combination
     *   is counted only once (avoids counting permutations).
     */

    /* Initialize: 0 ways for all sums except sum 0 */
    for (j = 0; j <= N; j++) {
        dp[j] = 0;
    }
    dp[0] = 1; /* Base case: one way to make sum 0 */

    /* Process each coin type */
    for (i = 0; i < n; i++) {
        for (j = coins[i]; j <= N; j++) {
            dp[j] += dp[j - coins[i]];
        }
    }

    printf("%lld\n", dp[N]);

    return 0;
}
