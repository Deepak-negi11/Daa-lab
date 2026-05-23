/*
 * Program: Fractional Knapsack (Greedy)
 * Week: 9
 * Problem: 2
 * Algorithm: Greedy (sort by value/weight ratio descending)
 * Time Complexity: O(N log N) for sorting
 * Space Complexity: O(N)
 *
 * Description:
 *   Items can be broken into fractions. Sort items by value-to-weight
 *   ratio in descending order, then greedily pick items.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int originalIndex; // 1-indexed item number
    int weight;
    int value;
    double ratio;      // value / weight
    double fraction;   // fraction of item taken (1.0 = full)
} Item;

// Compare items by ratio in descending order
int compareByRatio(const void *a, const void *b) {
    double ra = ((Item *)a)->ratio;
    double rb = ((Item *)b)->ratio;
    if (rb > ra) return 1;
    if (rb < ra) return -1;
    return 0;
}

int main() {
    int n, i;
    scanf("%d", &n);

    Item items[n];

    // Read weights
    for (i = 0; i < n; i++) {
        scanf("%d", &items[i].weight);
        items[i].originalIndex = i + 1;
        items[i].fraction = 0.0;
    }

    // Read values
    for (i = 0; i < n; i++) {
        scanf("%d", &items[i].value);
    }

    int capacity;
    scanf("%d", &capacity);

    // Compute value/weight ratio for each item
    for (i = 0; i < n; i++) {
        items[i].ratio = (double)items[i].value / items[i].weight;
    }

    // Sort items by ratio (descending)
    qsort(items, n, sizeof(Item), compareByRatio);

    double maxValue = 0.0;
    int remaining = capacity;

    // Greedily pick items
    for (i = 0; i < n && remaining > 0; i++) {
        if (items[i].weight <= remaining) {
            // Take the whole item
            items[i].fraction = 1.0;
            maxValue += items[i].value;
            remaining -= items[i].weight;
        } else {
            // Take a fraction of the item
            items[i].fraction = (double)remaining / items[i].weight;
            maxValue += items[i].value * items[i].fraction;
            remaining = 0;
        }
    }

    // Print maximum value
    printf("Maximum value : %.2f\n", maxValue);

    // Print selected items
    printf("item - weight\n");
    for (i = 0; i < n; i++) {
        if (items[i].fraction > 0.0) {
            if (items[i].fraction >= 1.0) {
                // Full item taken
                printf("%d - %d\n", items[i].originalIndex, items[i].weight);
            } else {
                // Partial item taken: show weight taken and fraction
                int weightTaken = (int)(items[i].weight * items[i].fraction);
                printf("%d - %d (fraction: %.2f)\n",
                       items[i].originalIndex, weightTaken, items[i].fraction);
            }
        }
    }

    return 0;
}
