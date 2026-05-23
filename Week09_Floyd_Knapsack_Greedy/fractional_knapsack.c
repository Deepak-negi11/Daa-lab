

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int originalIndex; 
    int weight;
    int value;
    double ratio;      
    double fraction;   
} Item;

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

    
    for (i = 0; i < n; i++) {
        scanf("%d", &items[i].weight);
        items[i].originalIndex = i + 1;
        items[i].fraction = 0.0;
    }

    
    for (i = 0; i < n; i++) {
        scanf("%d", &items[i].value);
    }

    int capacity;
    scanf("%d", &capacity);

    
    for (i = 0; i < n; i++) {
        items[i].ratio = (double)items[i].value / items[i].weight;
    }

    
    qsort(items, n, sizeof(Item), compareByRatio);

    double maxValue = 0.0;
    int remaining = capacity;

    
    for (i = 0; i < n && remaining > 0; i++) {
        if (items[i].weight <= remaining) {
            
            items[i].fraction = 1.0;
            maxValue += items[i].value;
            remaining -= items[i].weight;
        } else {
            
            items[i].fraction = (double)remaining / items[i].weight;
            maxValue += items[i].value * items[i].fraction;
            remaining = 0;
        }
    }

    
    printf("Maximum value : %.2f\n", maxValue);

    
    printf("item - weight\n");
    for (i = 0; i < n; i++) {
        if (items[i].fraction > 0.0) {
            if (items[i].fraction >= 1.0) {
                
                printf("%d - %d\n", items[i].originalIndex, items[i].weight);
            } else {
                
                int weightTaken = (int)(items[i].weight * items[i].fraction);
                printf("%d - %d (fraction: %.2f)\n",
                       items[i].originalIndex, weightTaken, items[i].fraction);
            }
        }
    }

    return 0;
}
