/*
 * Program    : Duplicate in Window of Size K
 * Week       : 13
 * Problem    : 2
 * Algorithm  : Hashing with Sliding Window (Hash Set)
 * Time Complexity  : O(n) average case per test case
 * Space Complexity : O(k) for the hash set
 *
 * Description:
 *   Given an array of integers of size n, check whether the array contains
 *   a duplicate element within a window of size k (i.e., two equal elements
 *   whose indices differ by at most k).
 *
 *   Approach: Maintain a hash set of size k. For each element:
 *     1. If it already exists in the hash set, duplicate found.
 *     2. Add the current element to the hash set.
 *     3. If the hash set has more than k elements, remove the element
 *        that falls outside the window (arr[i - k]).
 *
 * Compile: gcc duplicate_in_window.c -o duplicate_in_window
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* ---------- Hash Set Implementation (Chaining) ---------- */

#define TABLE_SIZE 10007  /* Prime number for better distribution */

/* Node for chaining in hash set */
typedef struct Node {
    int key;
    struct Node *next;
} Node;

/* Hash set structure */
typedef struct {
    Node *table[TABLE_SIZE];
    int size;
} HashSet;

/* Initialize hash set */
void initHashSet(HashSet *hs) {
    for (int i = 0; i < TABLE_SIZE; i++)
        hs->table[i] = NULL;
    hs->size = 0;
}

/* Hash function: handles negative numbers */
int hashFunc(int key) {
    int h = key % TABLE_SIZE;
    if (h < 0) h += TABLE_SIZE;
    return h;
}

/* Check if key exists in hash set */
bool contains(HashSet *hs, int key) {
    int idx = hashFunc(key);
    Node *curr = hs->table[idx];
    while (curr != NULL) {
        if (curr->key == key)
            return true;
        curr = curr->next;
    }
    return false;
}

/* Insert key into hash set */
void insert(HashSet *hs, int key) {
    if (contains(hs, key)) return;  /* Already present */
    int idx = hashFunc(key);
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = hs->table[idx];
    hs->table[idx] = newNode;
    hs->size++;
}

/* Remove key from hash set */
void removeKey(HashSet *hs, int key) {
    int idx = hashFunc(key);
    Node *curr = hs->table[idx];
    Node *prev = NULL;
    while (curr != NULL) {
        if (curr->key == key) {
            if (prev == NULL)
                hs->table[idx] = curr->next;
            else
                prev->next = curr->next;
            free(curr);
            hs->size--;
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

/* Free all memory in hash set */
void freeHashSet(HashSet *hs) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node *curr = hs->table[i];
        while (curr != NULL) {
            Node *temp = curr;
            curr = curr->next;
            free(temp);
        }
        hs->table[i] = NULL;
    }
    hs->size = 0;
}

/* ---------- Main Logic ---------- */

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int n, k;
        scanf("%d", &n);

        int *arr = (int *)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        scanf("%d", &k);

        HashSet hs;
        initHashSet(&hs);
        bool found = false;

        /*
         * Sliding window approach:
         * For each element arr[i], check if it's already in the hash set
         * (which contains elements from the current window of size k).
         * If yes, a duplicate exists within window k.
         * Otherwise, add arr[i] to the set and remove arr[i-k] if i >= k.
         */
        for (int i = 0; i < n; i++) {
            /* Check if current element already exists in the window */
            if (contains(&hs, arr[i])) {
                found = true;
                break;
            }

            /* Add current element to hash set */
            insert(&hs, arr[i]);

            /* Remove element that is now outside the window */
            if (i >= k) {
                removeKey(&hs, arr[i - k]);
            }
        }

        if (found)
            printf("Duplicate present in window %d\n", k);
        else
            printf("Duplicate not present in window %d\n", k);

        freeHashSet(&hs);
        free(arr);
    }

    return 0;
}
