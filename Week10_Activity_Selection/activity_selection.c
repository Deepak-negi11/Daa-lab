

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int finish;
    int index; 
} Activity;

int compareByFinish(const void *a, const void *b) {
    Activity *a1 = (Activity *)a;
    Activity *b1 = (Activity *)b;
    if (a1->finish != b1->finish)
        return a1->finish - b1->finish;
    return a1->start - b1->start; 
}

int main() {
    int n, i;
    scanf("%d", &n);

    Activity activities[n];

    
    for (i = 0; i < n; i++) {
        scanf("%d", &activities[i].start);
        activities[i].index = i + 1;
    }

    
    for (i = 0; i < n; i++) {
        scanf("%d", &activities[i].finish);
    }

    
    qsort(activities, n, sizeof(Activity), compareByFinish);

    
    int selected[n];
    int count = 0;

    
    selected[count++] = activities[0].index;
    int lastFinish = activities[0].finish;

    for (i = 1; i < n; i++) {
        
        if (activities[i].start >= lastFinish) {
            selected[count++] = activities[i].index;
            lastFinish = activities[i].finish;
        }
    }

    
    printf("No. of non-conflicting activities: %d\n", count);
    printf("List of selected activities: ");
    for (i = 0; i < count; i++) {
        if (i > 0) printf(", ");
        printf("%d", selected[i]);
    }
    printf("\n");

    return 0;
}
