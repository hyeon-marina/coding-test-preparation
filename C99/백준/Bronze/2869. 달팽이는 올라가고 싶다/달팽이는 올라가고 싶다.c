#include <stdio.h>
int main(void) {
    int a, b, v;
    scanf("%d %d %d", &a, &b, &v);
    int day = (v-b-1)/(a-b) + 1;
    printf("%d\n", day);
    return 0;
}
