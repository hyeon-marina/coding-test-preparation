#include <stdio.h>
#include <stdlib.h>

int cmp_int(const void *a, const void *b) {
    int ia = *(const int*)a;
    int ib = *(const int*)b;
    if (ia < ib) return -1;
    else if (ia > ib) return 1;
    else return 0;
}

int main() {
    int N;
    if (scanf("%d", &N) != 1) return 0;
    int *arr = (int*)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    qsort(arr, N, sizeof(int), cmp_int);
    for (int i = 0; i < N; i++) {
        printf("%d\n", arr[i]);
    }
    free(arr);
    return 0;
}