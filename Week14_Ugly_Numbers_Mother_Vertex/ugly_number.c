/*
 * Program    : Nth Ugly Number
 * Week       : 14
 * Problem    : 1
 * Algorithm  : Dynamic Programming with Three Pointers
 * Time Complexity  : O(n) per test case
 * Space Complexity : O(n) for the DP array
 *
 * Description:
 *   Ugly numbers are positive numbers whose only prime factors are 2, 3, or 5.
 *   The sequence: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, 16, 18, 20, 24, ...
 *   (1 is conventionally included as an ugly number)
 *
 *   DP Approach:
 *     - Maintain three pointers i2, i3, i5 for multiples of 2, 3, and 5.
 *     - At each step, the next ugly number is:
 *         min(ugly[i2]*2, ugly[i3]*3, ugly[i5]*5)
 *     - Increment the pointer(s) whose multiple was chosen.
 *     - This ensures we generate ugly numbers in sorted order without duplicates.
 *
 * Compile: gcc ugly_number.c -o ugly_number
 */

#include <stdio.h>
#include <stdlib.h>

/* Utility: return minimum of three values */
long long min3(long long a, long long b, long long c) {
    long long min = a;
    if (b < min) min = b;
    if (c < min) min = c;
    return min;
}

/*
 * Find the nth ugly number using DP with three pointers.
 * Returns the nth ugly number (1-indexed).
 */
long long nthUglyNumber(int n) {
    long long *ugly = (long long *)malloc(n * sizeof(long long));

    ugly[0] = 1;  /* First ugly number is 1 */

    /* Three pointers: indices into the ugly array */
    int i2 = 0, i3 = 0, i5 = 0;

    /* Next multiples of 2, 3, and 5 */
    long long next_mult_2 = 2;
    long long next_mult_3 = 3;
    long long next_mult_5 = 5;

    for (int i = 1; i < n; i++) {
        /* Choose the smallest among the three candidates */
        ugly[i] = min3(next_mult_2, next_mult_3, next_mult_5);

        /*
         * Increment pointer(s) whose multiple was chosen.
         * Note: Multiple pointers may be incremented if there are ties
         * (e.g., 2*3 = 6 = 3*2), which avoids duplicates.
         */
        if (ugly[i] == next_mult_2) {
            i2++;
            next_mult_2 = ugly[i2] * 2;
        }
        if (ugly[i] == next_mult_3) {
            i3++;
            next_mult_3 = ugly[i3] * 3;
        }
        if (ugly[i] == next_mult_5) {
            i5++;
            next_mult_5 = ugly[i5] * 5;
        }
    }

    long long result = ugly[n - 1];
    free(ugly);
    return result;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int n;
        scanf("%d", &n);

        long long result = nthUglyNumber(n);
        printf("%lld\n", result);
    }

    return 0;
}
