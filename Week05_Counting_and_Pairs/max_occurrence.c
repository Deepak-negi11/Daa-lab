

#include <stdio.h>
#include <string.h>

#define ALPHA_SIZE 26

int main() {
    int t;
    scanf("%d", &t); 

    while (t--) {
        int n;
        scanf("%d", &n); 

        char str[100001];
        scanf("%s", str); 

        
        int freq[ALPHA_SIZE] = {0};

        
        for (int i = 0; i < (int)strlen(str); i++) {
            freq[str[i] - 'a']++;
        }

        
        int maxFreq = 0;
        char maxChar = 'a';
        for (int i = 0; i < ALPHA_SIZE; i++) {
            if (freq[i] > maxFreq) {
                maxFreq = freq[i];
                maxChar = 'a' + i;
            }
        }

        
        if (maxFreq <= 1) {
            printf("No Duplicates Present\n");
        } else {
            printf("%c - %d\n", maxChar, maxFreq);
        }
    }

    return 0;
}
