#include <stdio.h>

int reverse(int n) {
    int rev = 0;
    while (n > 0) {
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    return rev;
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    int a_rev = reverse(a);
    int b_rev = reverse(b);

    if (a_rev > b_rev) {
        printf("%d\n", a_rev);
    } else {
        printf("%d\n", b_rev);
    }

    return 0;
}
