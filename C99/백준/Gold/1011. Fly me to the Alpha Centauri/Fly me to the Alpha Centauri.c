#include <stdio.h>
#include <math.h>

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int x, y;
        scanf("%d %d", &x, &y);
        int d = y - x;
        int n = (int)sqrt(d);
        if(n * n == d)
            printf("%d\n", 2 * n - 1);
        else if(n * n < d && d <= n * (n + 1))
            printf("%d\n", 2 * n);
        else
            printf("%d\n", 2 * n + 1);
    }
    return 0;
}
