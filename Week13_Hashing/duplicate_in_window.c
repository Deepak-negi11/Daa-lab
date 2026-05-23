

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TABLE_SIZE 10007  

typedef struct Node {
    int key;
    struct Node *next;
} Node;

typedef struct {
    Node *table[TABLE_SIZE];
    int size;
} HashSet;

void initHashSet(HashSet *hs) {
    for (int i = 0; i < TABLE_SIZE; i++)
        hs->table[i] = NULL;
    hs->size = 0;
}

int hashFunc(int key) {
    int h = key % TABLE_SIZE;
    if (h < 0) h += TABLE_SIZE;
    return h;
}

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

void insert(HashSet *hs, int key) {
    if (contains(hs, key)) return;  
    int idx = hashFunc(key);
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = hs->table[idx];
    hs->table[idx] = newNode;
    hs->size++;
}

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

        
        for (int i = 0; i < n; i++) {
            
            if (contains(&hs, arr[i])) {
                found = true;
                break;
            }

            
            insert(&hs, arr[i]);

            
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
