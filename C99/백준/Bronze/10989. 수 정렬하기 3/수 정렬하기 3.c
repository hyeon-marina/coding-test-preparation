#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int N;
    scanf("%d", &N);
    int *count = (int*)calloc(10001, sizeof(int));
    if (!count) return 0;

    for (int i = 0; i < N; i++) {
        int num;
        scanf("%d", &num);
        count[num]++;
    }

    for (int num = 1; num <= 10000; num++) {
        int c = count[num];
        for (int k = 0; k < c; k++) {
            printf("%d\n", num);
        }
    }

    free(count);
    return 0;
}