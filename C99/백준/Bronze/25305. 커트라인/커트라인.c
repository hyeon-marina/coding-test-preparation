#include <stdio.h>
#include <stdlib.h>

int cmp_desc(const void *a, const void *b) {
    // 내림차순
    return (*(int*)b - *(int*)a);
}

int main() {
    int N, k;
    scanf("%d %d", &N, &k);
    int *scores = malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &scores[i]);
    }
    qsort(scores, N, sizeof(int), cmp_desc);
    printf("%d\n", scores[k-1]);
    free(scores);
    return 0;
}