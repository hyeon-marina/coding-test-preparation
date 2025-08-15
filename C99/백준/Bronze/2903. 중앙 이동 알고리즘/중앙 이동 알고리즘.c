#include <stdio.h>
#include <math.h>
int main(void) {
    int N;
    scanf("%d", &N);
    int side = (int)pow(2, N) + 1;
    printf("%d\n", side * side);
    return 0;
}
