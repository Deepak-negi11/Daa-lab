/*
 * Program: Equal Sum Partition
 * Week: 11
 * Problem: 3
 * Algorithm: Dynamic Programming (Subset Sum variant)
 * Time Complexity: O(n * sum) where sum = total sum / 2
 * Space Complexity: O(n * sum)
 *
 * Description:
 *   Given a set of positive integers, determine if it can be partitioned
 *   into two subsets such that the sum of elements in both subsets is equal.
 *   This reduces to the Subset Sum problem: can we find a subset with
 *   sum = totalSum / 2?
 *
 * Compile: gcc equal_sum_partition.c -o equal_sum_partition
 */

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

    /* dp[i][j] = true if a subset of first i elements can sum to j */
    /* Using 1D optimization: dp[j] = true if sum j is achievable */
    bool dp[MAX_SUM + 1];

    /* Read number of elements */
    scanf("%d", &n);

    /* Read elements and compute total sum */
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        totalSum += arr[i];
    }

    /*
     * If total sum is odd, equal partition is impossible because
     * two equal integer subsets would need an even total.
     */
    if (totalSum % 2 != 0) {
        printf("no\n");
        return 0;
    }

    target = totalSum / 2;

    /*
     * Subset Sum DP (1D space-optimized):
     *   dp[j] = true if there exists a subset of the elements
     *           considered so far that sums to j.
     *   Base case: dp[0] = true (empty subset sums to 0).
     *
     *   For each element arr[i], iterate j from target down to arr[i]:
     *     dp[j] = dp[j] || dp[j - arr[i]]
     *   (Iterating backwards prevents using the same element twice.)
     */

    /* Initialize */
    for (j = 0; j <= target; j++) {
        dp[j] = false;
    }
    dp[0] = true;

    /* Process each element */
    for (i = 0; i < n; i++) {
        /* Traverse from right to left to avoid reusing arr[i] */
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
