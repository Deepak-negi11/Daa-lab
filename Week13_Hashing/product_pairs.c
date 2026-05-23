

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TABLE_SIZE 100003  

typedef struct Node {
    long long product;
    int idx1, idx2;       
    struct Node *next;
} Node;

Node *hashTable[TABLE_SIZE];

int hashFunc(long long product) {
    int h = (int)(product % TABLE_SIZE);
    if (h < 0) h += TABLE_SIZE;
    return h;
}

void initTable() {
    for (int i = 0; i < TABLE_SIZE; i++)
        hashTable[i] = NULL;
}

Node* search(long long product, int i, int j, int *arr) {
    int idx = hashFunc(product);
    Node *curr = hashTable[idx];
    while (curr != NULL) {
        if (curr->product == product) {
            
            if (curr->idx1 != i && curr->idx1 != j &&
                curr->idx2 != i && curr->idx2 != j) {
                
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

void insertProduct(long long product, int i, int j) {
    int idx = hashFunc(product);
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->product = product;
    newNode->idx1 = i;
    newNode->idx2 = j;
    newNode->next = hashTable[idx];
    hashTable[idx] = newNode;
}

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

    
    for (int i = 0; i < n && !found; i++) {
        for (int j = i + 1; j < n && !found; j++) {
            long long product = (long long)arr[i] * arr[j];

            
            Node *existing = search(product, i, j, arr);
            if (existing != NULL) {
                
                printf("%d %d\n", arr[i], arr[j]);
                printf("%d %d\n", arr[existing->idx1], arr[existing->idx2]);
                found = true;
            } else {
                
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
