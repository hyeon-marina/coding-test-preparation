#include <stdio.h>

int main(void) {
    int goal[] = {1, 1, 2, 2, 2, 8};
    int x;
    for (int i = 0; i < 6; i++) {
        scanf("%d", &x);
        printf("%d ", goal[i] - x);
    }
    return 0;
}