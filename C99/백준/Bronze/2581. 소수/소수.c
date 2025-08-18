#include <stdio.h>
#include <math.h>

int isPrime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0) return 0;
    return 1;
}

int main() {
    int M, N, sum = 0, min = -1;
    scanf("%d %d", &M, &N);
    for (int i = M; i <= N; i++) {
        if (isPrime(i)) {
            sum += i;
            if (min == -1) min = i;
        }
    }
    if (min == -1) printf("-1\n");
    else {
        printf("%d\n%d\n", sum, min);
    }
    return 0;
}
