#include <stdio.h>
#include <stdlib.h>
int main() {
    int arr[] = {15, 18, 42, 13, 1};
    int n = 5, k = 20, count = 0;
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++)
            if (abs(arr[i] - arr[j]) == k) {
                printf("Pair: (%d, %d) diff=%d\n", arr[i], arr[j], abs(arr[i]-arr[j]));
                count++;
            }
    printf("Unordered pairs: %d\n", count);
    printf("Ordered pairs: %d\n", count * 2);
    
    
    printf("\n--- With key=2 ---\n");
    count = 0; k = 2;
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++)
            if (abs(arr[i] - arr[j]) == k) {
                printf("Pair: (%d, %d)\n", arr[i], arr[j]);
                count++;
            }
    printf("Count: %d\n", count);
    
    printf("\n--- With key=5 ---\n");
    count = 0; k = 5;
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++)
            if (abs(arr[i] - arr[j]) == k) {
                printf("Pair: (%d, %d)\n", arr[i], arr[j]);
                count++;
            }
    printf("Count: %d\n", count);
    return 0;
}
