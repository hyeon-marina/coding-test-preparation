#include <stdio.h>
int main(void) {
    int X, line = 1;
    scanf("%d", &X);
    while (X > line) {
        X -= line;
        line++;
    }
    int a, b;
    if (line % 2 == 0) {
        a = X;
        b = line - X + 1;
    } else {
        a = line - X + 1;
        b = X;
    }
    printf("%d/%d\n", a, b);
    return 0;
}
