#include <stdio.h>
#include <stdlib.h>

int cmp_int(const void *a, const void *b) {
    int x = *(const int*)a;
    int y = *(const int*)b;
    return (x > y) - (x < y);
}

int lower_bound(int *a, int n, int x) {
    int l = 0, r = n; // [l, r)
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (a[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return l;
}

int upper_bound(int *a, int n, int x) {
    int l = 0, r = n; // [l, r)
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (a[mid] > x) r = mid;
        else l = mid + 1;
    }
    return l;
}

int main(void) {
    int n;
    scanf("%d", &n);
    int *arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    qsort(arr, n, sizeof(int), cmp_int);

    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int q;
        scanf("%d", &q);
        int lb = lower_bound(arr, n, q);
        int ub = upper_bound(arr, n, q);
        int ans = ub - lb;
        if (i) putchar(' ');
        printf("%d", ans);
    }
    putchar('\n');

    free(arr);
    return 0;
}
