#include <stdio.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int count5 = n / 5;
    while (count5 >= 0) {
        int rem = n - count5 * 5;
        if (rem % 3 == 0) {
            int count3 = rem / 3;
            printf("%d\n", count5 + count3);
            return 0;
        }
        count5--;
    }
    printf("-1\n");
    return 0;
}