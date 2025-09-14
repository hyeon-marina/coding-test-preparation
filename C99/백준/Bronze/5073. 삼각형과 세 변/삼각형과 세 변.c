#include <stdio.h>
#include <stdlib.h>

int cmp(const void *p, const void *q) {
    return (*(int*)p) - (*(int*)q);
}

int main(void) {
    int a, b, c;
    while (1) {
        if (scanf("%d %d %d", &a, &b, &c) != 3) break;
        if (a == 0 && b == 0 && c == 0) break;

        int sides[3] = {a, b, c};
        qsort(sides, 3, sizeof(int), cmp);
        int x = sides[0], y = sides[1], z = sides[2];

        if (x + y <= z) {
            printf("Invalid\n");
        } else {
            if (x == y && y == z) {
                printf("Equilateral\n");
            } else if (x == y || y == z || x == z) {
                printf("Isosceles\n");
            } else {
                printf("Scalene\n");
            }
        }
    }
    return 0;
}