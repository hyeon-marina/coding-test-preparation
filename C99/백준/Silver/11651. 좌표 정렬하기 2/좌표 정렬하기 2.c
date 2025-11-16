#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} Point;

int cmp(const void *a, const void *b) {
    Point *pa = (Point *)a;
    Point *pb = (Point *)b;
    if (pa->y != pb->y) {
        return (pa->y < pb->y) ? -1 : 1;
    } else {
        return (pa->x < pb->x) ? -1 : 1;
    }
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    Point *arr = malloc(sizeof(Point) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].x, &arr[i].y);
    }
    qsort(arr, n, sizeof(Point), cmp);
    for (int i = 0; i < n; i++) {
        printf("%d %d\n", arr[i].x, arr[i].y);
    }
    free(arr);
    return 0;
}