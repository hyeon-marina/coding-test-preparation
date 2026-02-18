#include <stdio.h>
#include <stdlib.h>

static unsigned char* sieve(int n) {
    unsigned char *is_prime = (unsigned char*)malloc((n + 1) * sizeof(unsigned char));
    for (int i = 0; i <= n; i++) is_prime[i] = 1;
    if (n >= 0) is_prime[0] = 0;
    if (n >= 1) is_prime[1] = 0;

    for (int i = 2; (long long)i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = 0;
            }
        }
    }
    return is_prime;
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;

    int *nums = (int*)malloc(t * sizeof(int));
    int max_n = 0;
    for (int i = 0; i < t; i++) {
        scanf("%d", &nums[i]);
        if (nums[i] > max_n) max_n = nums[i];
    }

    unsigned char *is_prime = sieve(max_n);

    for (int i = 0; i < t; i++) {
        int n = nums[i];
        int half = n / 2;
        int cnt = 0;
        for (int p = 2; p <= half; p++) {
            if (is_prime[p] && is_prime[n - p]) cnt++;
        }
        printf("%d\n", cnt);
    }

    free(is_prime);
    free(nums);
    return 0;
}
