#include <stdio.h>

int self_sum(int x) {
    int s = x;
    while (x > 0) {
        s += x % 10;
        x /= 10;
    }
    return s;
}

int main() {
    int N;
    if (scanf("%d", &N) != 1) return 0;
    int ans = 0;

    // 자릿수 개수 구하기
    int tmp = N;
    int d = 0;
    while (tmp > 0) {
        d++;
        tmp /= 10;
    }
    int start = N - 9 * d;
    if (start < 1) start = 1;
    for (int m = start; m < N; m++) {
        if (self_sum(m) == N) {
            ans = m;
            break;
        }
    }

    printf("%d\n", ans);
    return 0;
}