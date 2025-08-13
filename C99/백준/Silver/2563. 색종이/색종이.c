#include <stdio.h>

int main() {
    int N, x, y, i, j, total = 0;
    int paper[100][100] = {0};
    scanf("%d", &N);
    for (int k = 0; k < N; k++) {
        scanf("%d %d", &x, &y);
        for (i = x; i < x + 10; i++) {
            for (j = y; j < y + 10; j++) {
                paper[i][j] = 1;
            }
        }
    }
    for (i = 0; i < 100; i++) {
        for (j = 0; j < 100; j++) {
            if (paper[i][j] == 1) total++;
        }
    }
    printf("%d\n", total);
    return 0;
}