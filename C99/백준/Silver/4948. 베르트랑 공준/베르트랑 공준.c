#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void) {
    int n;
    int cap = 256, sz = 0;
    int *qs = (int*)malloc(sizeof(int) * cap);
    if (!qs) return 0;

    int maxN = 0;
    while (scanf("%d", &n) == 1) {
        if (n == 0) break;
        if (sz == cap) {
            cap *= 2;
            int *tmp = (int*)realloc(qs, sizeof(int) * cap);
            if (!tmp) { free(qs); return 0; }
            qs = tmp;
        }
        qs[sz++] = n;
        if (n > maxN) maxN = n;
    }
    if (sz == 0) { free(qs); return 0; }

    int limit = 2 * maxN;

    bool *isPrime = (bool*)malloc(sizeof(bool) * (limit + 1));
    int  *prefix  = (int*)malloc(sizeof(int)  * (limit + 1));
    if (!isPrime || !prefix) { free(qs); free(isPrime); free(prefix); return 0; }

    for (int i = 0; i <= limit; i++) isPrime[i] = true;
    if (limit >= 0) isPrime[0] = false;
    if (limit >= 1) isPrime[1] = false;

    for (int p = 2; p * p <= limit; p++) {
        if (isPrime[p]) {
            for (int x = p * p; x <= limit; x += p) {
                isPrime[x] = false;
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i <= limit; i++) {
        if (isPrime[i]) cnt++;
        prefix[i] = cnt;
    }

    for (int i = 0; i < sz; i++) {
        int q = qs[i];
        int ans = prefix[2 * q] - prefix[q];
        printf("%d\n", ans);
    }

    free(qs);
    free(isPrime);
    free(prefix);
    return 0;
}
