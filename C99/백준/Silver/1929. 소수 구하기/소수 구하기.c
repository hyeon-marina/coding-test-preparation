#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    char *isPrime = (char*)malloc(n + 1);
    for (int i = 0; i <= n; i++) isPrime[i] = 1;
    if (n >= 0) isPrime[0] = 0;
    if (n >= 1) isPrime[1] = 0;

    int limit = (int)sqrt((double)n);
    for (int i = 2; i <= limit; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = 0;
            }
        }
    }

    for (int x = (m < 2 ? 2 : m); x <= n; x++) {
        if (isPrime[x]) printf("%d\n", x);
    }

    free(isPrime);
    return 0;
}
