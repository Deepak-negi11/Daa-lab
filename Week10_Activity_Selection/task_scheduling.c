/*
 * Program: Task Scheduling with Deadlines
 * Week: 10
 * Problem: 2
 * Algorithm: Greedy (sort by deadline, schedule earliest-deadline-first)
 * Time Complexity: O(N log N)
 * Space Complexity: O(N)
 *
 * Description:
 *   Given N tasks with durations and deadlines, find the maximum number
 *   of tasks that can be completed without crossing their deadlines.
 *   Strategy: Sort tasks by deadline. Greedily pick tasks in deadline
 *   order, accumulating time. If current_time + duration <= deadline,
 *   the task can be scheduled.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int duration;
    int deadline;
    int index; // 1-indexed original position
} Task;

// Compare tasks by deadline (ascending), tie-break by duration (ascending)
int compareByDeadline(const void *a, const void *b) {
    Task *t1 = (Task *)a;
    Task *t2 = (Task *)b;
    if (t1->deadline != t2->deadline)
        return t1->deadline - t2->deadline;
    return t1->duration - t2->duration;
}

// Compare integers for sorting selected task numbers
int compareInt(const void *a, const void *b) {
    return (*(int *)a) - (*(int *)b);
}

int main() {
    int n, i;
    scanf("%d", &n);

    Task tasks[n];

    // Read task durations
    for (i = 0; i < n; i++) {
        scanf("%d", &tasks[i].duration);
        tasks[i].index = i + 1;
    }

    // Read task deadlines
    for (i = 0; i < n; i++) {
        scanf("%d", &tasks[i].deadline);
    }

    // Sort tasks by deadline
    qsort(tasks, n, sizeof(Task), compareByDeadline);

    // Greedy selection: accumulate time and pick feasible tasks
    int selected[n];
    int count = 0;
    int currentTime = 0;

    for (i = 0; i < n; i++) {
        if (currentTime + tasks[i].duration <= tasks[i].deadline) {
            currentTime += tasks[i].duration;
            selected[count++] = tasks[i].index;
        }
    }

    // Sort selected task indices for display
    qsort(selected, count, sizeof(int), compareInt);

    // Output
    printf("Max number of tasks = %d\n", count);
    printf("Selected task numbers : ");
    for (i = 0; i < count; i++) {
        if (i > 0) printf(", ");
        printf("%d", selected[i]);
    }
    printf("\n");

    return 0;
}
