#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    int ia = *(const int*)a;
    int ib = *(const int*)b;
    return ia - ib;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int *arr = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    qsort(arr, n, sizeof(int), cmp);
    for (int i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
    }
    free(arr);
    return 0;
}