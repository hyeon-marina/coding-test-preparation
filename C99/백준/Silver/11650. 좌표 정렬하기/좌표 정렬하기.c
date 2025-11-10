#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x, y;
} Point;

int cmp(const void *a, const void *b) {
    Point *p1 = (Point *)a;
    Point *p2 = (Point *)b;
    if (p1->x != p2->x) return p1->x - p2->x;
    return p1->y - p2->y;
}

int main() {
    int n;
    scanf("%d", &n);
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