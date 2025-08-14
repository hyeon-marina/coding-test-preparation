#include <stdio.h>
int main(void) {
    char ans[100];
    int N, B, idx = 0, mod;
    scanf("%d %d", &N, &B);
    while (N > 0) {
        mod = N % B;
        if (mod < 10)
            ans[idx++] = mod + '0';
        else
            ans[idx++] = mod - 10 + 'A';
        N /= B;
    }
    for (int i = idx - 1; i >= 0; i--)
        printf("%c", ans[i]);
    return 0;
}
