#include <stdio.h>
#include <stdlib.h>

int cmp(const void *p, const void *q) {
    return (*(int*)p) - (*(int*)q);
}

int main(void) {
    int a, b, c;
    if (scanf("%d %d %d", &a, &b, &c) != 3) return 0;

    int s[3] = {a, b, c};
    qsort(s, 3, sizeof(int), cmp);
    int x = s[0], y = s[1], z = s[2];

    int ans;
    if (x + y > z) {
        ans = x + y + z;
    } else {
        ans = 2 * (x + y) - 1;
    }

    printf("%d\n", ans);
    return 0;
}