/*
 * Program    : Product Pairs (a*b = c*d)
 * Week       : 13
 * Problem    : 3
 * Algorithm  : Hashing (store products of all pairs)
 * Time Complexity  : O(n^2) to generate all pairs, O(1) average hash lookup
 * Space Complexity : O(n^2) for storing all pair products in hash table
 *
 * Description:
 *   Given an array of nonnegative integers, find two pairs (a,b) and (c,d)
 *   such that a*b = c*d, where a, b, c, d are distinct elements (at distinct
 *   indices).
 *
 *   Approach:
 *     1. For every pair (i, j) where i < j, compute product = arr[i] * arr[j].
 *     2. Check if this product already exists in the hash table.
 *        - If yes, we found two pairs with equal products.
 *        - If no, insert the product along with the pair indices.
 *
 * Compile: gcc product_pairs.c -o product_pairs
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TABLE_SIZE 100003  /* Large prime for hash table */

/* Node to store product and the pair of indices that produced it */
typedef struct Node {
    long long product;
    int idx1, idx2;       /* Indices of the pair */
    struct Node *next;
} Node;

/* Hash table */
Node *hashTable[TABLE_SIZE];

/* Hash function for product values */
int hashFunc(long long product) {
    int h = (int)(product % TABLE_SIZE);
    if (h < 0) h += TABLE_SIZE;
    return h;
}

/* Initialize hash table */
void initTable() {
    for (int i = 0; i < TABLE_SIZE; i++)
        hashTable[i] = NULL;
}

/*
 * Search for a product in the hash table.
 * If found, returns the node containing the pair indices.
 * The found pair must have distinct indices AND distinct values
 * (a, b, c, d must all be different elements).
 */
Node* search(long long product, int i, int j, int *arr) {
    int idx = hashFunc(product);
    Node *curr = hashTable[idx];
    while (curr != NULL) {
        if (curr->product == product) {
            /* Ensure all four indices are distinct */
            if (curr->idx1 != i && curr->idx1 != j &&
                curr->idx2 != i && curr->idx2 != j) {
                /* Also ensure all four values are distinct */
                int a = arr[curr->idx1], b = arr[curr->idx2];
                int c = arr[i], d = arr[j];
                if (a != b && a != c && a != d &&
                    b != c && b != d && c != d) {
                    return curr;
                }
            }
        }
        curr = curr->next;
    }
    return NULL;
}

/* Insert a product with its pair indices into the hash table */
void insertProduct(long long product, int i, int j) {
    int idx = hashFunc(product);
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->product = product;
    newNode->idx1 = i;
    newNode->idx2 = j;
    newNode->next = hashTable[idx];
    hashTable[idx] = newNode;
}

/* Free hash table memory */
void freeTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node *curr = hashTable[i];
        while (curr != NULL) {
            Node *temp = curr;
            curr = curr->next;
            free(temp);
        }
        hashTable[i] = NULL;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    initTable();

    bool found = false;

    /*
     * Generate all pairs (i, j) where i < j.
     * For each pair, compute product and check hash table.
     */
    for (int i = 0; i < n && !found; i++) {
        for (int j = i + 1; j < n && !found; j++) {
            long long product = (long long)arr[i] * arr[j];

            /* Check if this product was seen before with different indices */
            Node *existing = search(product, i, j, arr);
            if (existing != NULL) {
                /* Found two pairs: (arr[existing->idx1], arr[existing->idx2])
                 * and (arr[i], arr[j]) with equal products */
                printf("%d %d\n", arr[i], arr[j]);
                printf("%d %d\n", arr[existing->idx1], arr[existing->idx2]);
                found = true;
            } else {
                /* Store this product with its pair indices */
                insertProduct(product, i, j);
            }
        }
    }

    if (!found)
        printf("No such pairs found\n");

    freeTable();
    free(arr);

    return 0;
}
