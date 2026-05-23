/*
 * Program    : Distinct Characters using Hashing
 * Week       : 13
 * Problem    : 1
 * Algorithm  : Hashing (Direct Address Table using character ASCII values)
 * Time Complexity  : O(n) for counting + O(ALPHABET_SIZE) for output = O(n)
 * Space Complexity : O(1) - fixed size hash table (256 entries)
 *
 * Description:
 *   Given an array of characters, find distinct characters and their
 *   frequencies using a hash table. Output is in alphabetical order.
 *   We use an integer array of size 256 (ASCII range) as a direct
 *   address hash table where the index is the ASCII value of the character.
 *
 * Compile: gcc distinct_chars.c -o distinct_chars
 */

#include <stdio.h>
#include <string.h>

#define HASH_SIZE 256  /* Size of ASCII character set */

int main() {
    int n;
    int freq[HASH_SIZE];  /* Hash table: index = ASCII value, value = frequency */
    char ch;

    /* Initialize hash table with zeros */
    memset(freq, 0, sizeof(freq));

    /* Read number of characters */
    scanf("%d", &n);

    /* Read each character and hash it (increment its frequency) */
    for (int i = 0; i < n; i++) {
        scanf(" %c", &ch);          /* Leading space skips whitespace */
        freq[(int)ch]++;            /* Hash function: h(ch) = ASCII(ch) */
    }

    /*
     * Print distinct characters in alphabetical order.
     * Since we iterate from index 0 to 255, lowercase letters (97-122)
     * will naturally appear in alphabetical order.
     * We also handle uppercase letters (65-90) which come before lowercase.
     */
    for (int i = 0; i < HASH_SIZE; i++) {
        if (freq[i] > 0) {
            printf("%c - %d\n", (char)i, freq[i]);
        }
    }

    return 0;
}
