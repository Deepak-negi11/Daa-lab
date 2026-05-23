

#include <stdio.h>
#include <string.h>

#define HASH_SIZE 256  

int main() {
    int n;
    int freq[HASH_SIZE];  
    char ch;

    
    memset(freq, 0, sizeof(freq));

    
    scanf("%d", &n);

    
    for (int i = 0; i < n; i++) {
        scanf(" %c", &ch);          
        freq[(int)ch]++;            
    }

    
    for (int i = 0; i < HASH_SIZE; i++) {
        if (freq[i] > 0) {
            printf("%c - %d\n", (char)i, freq[i]);
        }
    }

    return 0;
}
