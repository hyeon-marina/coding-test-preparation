#include <stdio.h>
int main(void) {
    int n;
    scanf("%d", &n);
    int honey = 1, layer = 1;
    while (n > honey) {
        honey += 6 * layer;
        layer++;
    }
    printf("%d\n", layer);
    return 0;
}
