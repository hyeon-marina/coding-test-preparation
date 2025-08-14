#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
    char N[40];
    int B, len, result = 0;
    scanf("%s %d", N, &B);
    len = strlen(N);
    for(int i = 0; i < len; i++) {
        int val;
        if (N[i] >= 'A' && N[i] <= 'Z')
            val = N[i] - 'A' + 10;
        else
            val = N[i] - '0';
        result = result * B + val;
    }
    printf("%d\n", result);
    return 0;
}
