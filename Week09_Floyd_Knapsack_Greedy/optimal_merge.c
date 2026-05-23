

#include <stdio.h>

#define MAX 1000

int heap[MAX];
int heapSize = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heapSize && heap[left] < heap[smallest])
        smallest = left;
    if (right < heapSize && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        minHeapify(smallest);
    }
}

void insert(int val) {
    heap[heapSize] = val;
    int i = heapSize;
    heapSize++;

    
    while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int extractMin() {
    int minVal = heap[0];
    heapSize--;
    heap[0] = heap[heapSize];
    minHeapify(0);
    return minVal;
}

int main() {
    int n, i;
    scanf("%d", &n);

    
    for (i = 0; i < n; i++) {
        int size;
        scanf("%d", &size);
        insert(size);
    }

    int totalCost = 0;

    
    while (heapSize > 1) {
        int first = extractMin();   
        int second = extractMin();  
        int merged = first + second;

        totalCost += merged;  
        insert(merged);       
    }

    printf("%d\n", totalCost);

    return 0;
}
