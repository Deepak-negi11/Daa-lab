/*
 * Program: String Permutations in Lexicographic Order
 * Week: 12
 * Problem: 3
 * Algorithm: Next Permutation (Iterative, Lexicographic)
 * Time Complexity: O(n! * n) where n = length of string
 * Space Complexity: O(n) for the string
 *
 * Description:
 *   Given a string, print all its permutations in lexicographic (dictionary)
 *   order. The approach:
 *   1. Sort the string to get the smallest permutation.
 *   2. Repeatedly find the next lexicographic permutation until no more exist.
 *
 * Compile: gcc permutations.c -o permutations
 */

#include <stdio.h>
#include <string.h>

#define MAX 20

/* Swap two characters */
void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

/* Reverse the substring str[left..right] */
void reverse(char *str, int left, int right) {
    while (left < right) {
        swap(&str[left], &str[right]);
        left++;
        right--;
    }
}

/* Sort the string using simple selection sort (sufficient for short strings) */
void sortString(char *str, int len) {
    int i, j, minIdx;
    for (i = 0; i < len - 1; i++) {
        minIdx = i;
        for (j = i + 1; j < len; j++) {
            if (str[j] < str[minIdx]) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            swap(&str[i], &str[minIdx]);
        }
    }
}

/*
 * Generate the next lexicographic permutation in-place.
 * Returns 1 if successful, 0 if already the last permutation.
 *
 * Algorithm:
 *   1. Find the largest index i such that str[i] < str[i+1].
 *      If no such index exists, the permutation is the last one.
 *   2. Find the largest index j > i such that str[i] < str[j].
 *   3. Swap str[i] and str[j].
 *   4. Reverse the suffix starting at str[i+1].
 */
int nextPermutation(char *str, int len) {
    int i, j;

    /* Step 1: Find rightmost character smaller than its successor */
    i = len - 2;
    while (i >= 0 && str[i] >= str[i + 1]) {
        i--;
    }

    /* If no such character found, this is the last permutation */
    if (i < 0) {
        return 0;
    }

    /* Step 2: Find rightmost character greater than str[i] */
    j = len - 1;
    while (str[j] <= str[i]) {
        j--;
    }

    /* Step 3: Swap */
    swap(&str[i], &str[j]);

    /* Step 4: Reverse the suffix after index i */
    reverse(str, i + 1, len - 1);

    return 1;
}

int main() {
    char str[MAX + 1];
    int len;

    /* Read input string */
    scanf("%s", str);
    len = strlen(str);

    /* Step 1: Sort the string to get the lexicographically smallest permutation */
    sortString(str, len);

    /* Step 2: Print all permutations in order */
    do {
        printf("%s\n", str);
    } while (nextPermutation(str, len));

    return 0;
}
