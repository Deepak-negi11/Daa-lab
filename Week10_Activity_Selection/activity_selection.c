/*
 * Program: Activity Selection Problem
 * Week: 10
 * Problem: 1
 * Algorithm: Greedy (sort by finish time)
 * Time Complexity: O(N log N) for sorting + O(N) for selection
 * Space Complexity: O(N)
 *
 * Description:
 *   Given N activities with start and finish times, select the maximum
 *   number of non-conflicting activities. An activity is compatible if
 *   its start time >= finish time of the previously selected activity.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int finish;
    int index; // 1-indexed original position
} Activity;

// Compare activities by finish time (ascending)
int compareByFinish(const void *a, const void *b) {
    Activity *a1 = (Activity *)a;
    Activity *b1 = (Activity *)b;
    if (a1->finish != b1->finish)
        return a1->finish - b1->finish;
    return a1->start - b1->start; // tie-break by start time
}

int main() {
    int n, i;
    scanf("%d", &n);

    Activity activities[n];

    // Read start times
    for (i = 0; i < n; i++) {
        scanf("%d", &activities[i].start);
        activities[i].index = i + 1;
    }

    // Read finish times
    for (i = 0; i < n; i++) {
        scanf("%d", &activities[i].finish);
    }

    // Sort activities by finish time
    qsort(activities, n, sizeof(Activity), compareByFinish);

    // Greedy selection
    int selected[n];
    int count = 0;

    // Always select the first activity (earliest finish)
    selected[count++] = activities[0].index;
    int lastFinish = activities[0].finish;

    for (i = 1; i < n; i++) {
        // Select activity if its start time >= last selected finish time
        if (activities[i].start >= lastFinish) {
            selected[count++] = activities[i].index;
            lastFinish = activities[i].finish;
        }
    }

    // Output
    printf("No. of non-conflicting activities: %d\n", count);
    printf("List of selected activities: ");
    for (i = 0; i < count; i++) {
        if (i > 0) printf(", ");
        printf("%d", selected[i]);
    }
    printf("\n");

    return 0;
}
