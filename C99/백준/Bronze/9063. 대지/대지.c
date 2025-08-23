#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);

    int x, y;
    int minX = 10001, maxX = -10001;
    int minY = 10001, maxY = -10001;

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        if (x < minX) minX = x;
        if (x > maxX) maxX = x;
        if (y < minY) minY = y;
        if (y > maxY) maxY = y;
    }

    if (n == 1) printf("0");
    else printf("%d", (maxX - minX) * (maxY - minY));
    return 0;
}