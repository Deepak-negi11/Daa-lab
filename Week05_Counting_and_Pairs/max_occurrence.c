/*
 * Program: Max Occurrence using Counting Sort Approach
 * Week: 05
 * Problem: 1
 * Algorithm: Counting Sort / Frequency Counting
 * Time Complexity: O(n) - single pass through the string
 * Space Complexity: O(1) - fixed size frequency array (26 lowercase letters)
 *
 * Description:
 *   Given an unsorted array of alphabets with possible duplicates,
 *   find which alphabet has the maximum number of occurrences.
 *   If no character appears more than once, print "No Duplicates Present".
 *
 * Compile: gcc max_occurrence.c -o max_occurrence
 */

#include <stdio.h>
#include <string.h>

#define ALPHA_SIZE 26

int main() {
    int t;
    scanf("%d", &t); // Number of test cases

    while (t--) {
        int n;
        scanf("%d", &n); // Length of the string

        char str[100001];
        scanf("%s", str); // Read the string of characters

        // Frequency array for 26 lowercase letters (counting sort approach)
        int freq[ALPHA_SIZE] = {0};

        // Count frequency of each character - O(n)
        for (int i = 0; i < (int)strlen(str); i++) {
            freq[str[i] - 'a']++;
        }

        // Find the character with maximum frequency - O(26) = O(1)
        int maxFreq = 0;
        char maxChar = 'a';
        for (int i = 0; i < ALPHA_SIZE; i++) {
            if (freq[i] > maxFreq) {
                maxFreq = freq[i];
                maxChar = 'a' + i;
            }
        }

        // If max frequency is 1, no character is duplicated
        if (maxFreq <= 1) {
            printf("No Duplicates Present\n");
        } else {
            printf("%c - %d\n", maxChar, maxFreq);
        }
    }

    return 0;
}
