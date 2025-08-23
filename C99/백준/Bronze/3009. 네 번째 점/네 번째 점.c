#include <stdio.h>

int main(void) {
    int x1, y1, x2, y2, x3, y3;
    scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);

    int x, y;
    // x 좌표 판별
    if (x1 == x2) x = x3;
    else if (x1 == x3) x = x2;
    else x = x1;
    // y 좌표 판별
    if (y1 == y2) y = y3;
    else if (y1 == y3) y = y2;
    else y = y1;

    printf("%d %d\n", x, y);
    return 0;
}