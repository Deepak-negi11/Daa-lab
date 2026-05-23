/*
 * Program: Optimal Merge Pattern
 * Week: 9
 * Problem: 3
 * Algorithm: Greedy (Min-Heap / Priority Queue)
 * Time Complexity: O(N log N)
 * Space Complexity: O(N)
 *
 * Description:
 *   Given n file sizes, find the minimum computation cost to merge
 *   all files into a single file. Always merge the two smallest files
 *   first (Huffman-style merging).
 */

#include <stdio.h>

#define MAX 1000

int heap[MAX];
int heapSize = 0;

// Swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Min-heapify (sift down) at index i
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

// Insert a value into the min-heap
void insert(int val) {
    heap[heapSize] = val;
    int i = heapSize;
    heapSize++;

    // Sift up
    while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Extract the minimum value from the min-heap
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

    // Read file sizes and insert into min-heap
    for (i = 0; i < n; i++) {
        int size;
        scanf("%d", &size);
        insert(size);
    }

    int totalCost = 0;

    // Repeatedly merge two smallest files until one file remains
    while (heapSize > 1) {
        int first = extractMin();   // Smallest
        int second = extractMin();  // Second smallest
        int merged = first + second;

        totalCost += merged;  // Add merge cost
        insert(merged);       // Insert merged file back
    }

    printf("%d\n", totalCost);

    return 0;
}
