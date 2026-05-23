

#include <stdio.h>
#include <string.h>

#define MAX 20

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(char *str, int left, int right) {
    while (left < right) {
        swap(&str[left], &str[right]);
        left++;
        right--;
    }
}

void sortString(char *str, int len) {
    int i, j, minIdx;
    for (i = 0; i < len - 1; i++) {
        minIdx = i;
        for (j = i + 1; j < len; j++) {
            if (str[j] < str[minIdx]) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            swap(&str[i], &str[minIdx]);
        }
    }
}

int nextPermutation(char *str, int len) {
    int i, j;

    
    i = len - 2;
    while (i >= 0 && str[i] >= str[i + 1]) {
        i--;
    }

    
    if (i < 0) {
        return 0;
    }

    
    j = len - 1;
    while (str[j] <= str[i]) {
        j--;
    }

    
    swap(&str[i], &str[j]);

    
    reverse(str, i + 1, len - 1);

    return 1;
}

int main() {
    char str[MAX + 1];
    int len;

    
    scanf("%s", str);
    len = strlen(str);

    
    sortString(str, len);

    
    do {
        printf("%s\n", str);
    } while (nextPermutation(str, len));

    return 0;
}
