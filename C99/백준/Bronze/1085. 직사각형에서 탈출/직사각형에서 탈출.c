#include <stdio.h>

int main(void) {
    int x, y, w, h;
    scanf("%d %d %d %d", &x, &y, &w, &h);

    int min = x;
    if (w - x < min) min = w - x;
    if (y < min) min = y;
    if (h - y < min) min = h - y;

    printf("%d\n", min);
    return 0;
}