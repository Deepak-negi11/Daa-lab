

#include <stdio.h>
#include <stdlib.h>

long long min3(long long a, long long b, long long c) {
    long long min = a;
    if (b < min) min = b;
    if (c < min) min = c;
    return min;
}

long long nthUglyNumber(int n) {
    long long *ugly = (long long *)malloc(n * sizeof(long long));

    ugly[0] = 1;  

    
    int i2 = 0, i3 = 0, i5 = 0;

    
    long long next_mult_2 = 2;
    long long next_mult_3 = 3;
    long long next_mult_5 = 5;

    for (int i = 1; i < n; i++) {
        
        ugly[i] = min3(next_mult_2, next_mult_3, next_mult_5);

        
        if (ugly[i] == next_mult_2) {
            i2++;
            next_mult_2 = ugly[i2] * 2;
        }
        if (ugly[i] == next_mult_3) {
            i3++;
            next_mult_3 = ugly[i3] * 3;
        }
        if (ugly[i] == next_mult_5) {
            i5++;
            next_mult_5 = ugly[i5] * 5;
        }
    }

    long long result = ugly[n - 1];
    free(ugly);
    return result;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int n;
        scanf("%d", &n);

        long long result = nthUglyNumber(n);
        printf("%lld\n", result);
    }

    return 0;
}
