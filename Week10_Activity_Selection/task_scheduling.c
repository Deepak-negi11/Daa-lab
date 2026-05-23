

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int duration;
    int deadline;
    int index; 
} Task;

int compareByDeadline(const void *a, const void *b) {
    Task *t1 = (Task *)a;
    Task *t2 = (Task *)b;
    if (t1->deadline != t2->deadline)
        return t1->deadline - t2->deadline;
    return t1->duration - t2->duration;
}

int compareInt(const void *a, const void *b) {
    return (*(int *)a) - (*(int *)b);
}

int main() {
    int n, i;
    scanf("%d", &n);

    Task tasks[n];

    
    for (i = 0; i < n; i++) {
        scanf("%d", &tasks[i].duration);
        tasks[i].index = i + 1;
    }

    
    for (i = 0; i < n; i++) {
        scanf("%d", &tasks[i].deadline);
    }

    
    qsort(tasks, n, sizeof(Task), compareByDeadline);

    
    int selected[n];
    int count = 0;
    int currentTime = 0;

    for (i = 0; i < n; i++) {
        if (currentTime + tasks[i].duration <= tasks[i].deadline) {
            currentTime += tasks[i].duration;
            selected[count++] = tasks[i].index;
        }
    }

    
    qsort(selected, count, sizeof(int), compareInt);

    
    printf("Max number of tasks = %d\n", count);
    printf("Selected task numbers : ");
    for (i = 0; i < count; i++) {
        if (i > 0) printf(", ");
        printf("%d", selected[i]);
    }
    printf("\n");

    return 0;
}
