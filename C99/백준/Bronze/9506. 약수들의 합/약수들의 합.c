#include <stdio.h>

int main() {
    int n;
    while(1) {
        scanf("%d", &n);
        if (n == -1) break;
        
        int sum = 0;
        int first = 1;
        
        // 약수를 먼저 구해서 합을 계산
        for (int i = 1; i < n; i++) {
            if (n % i == 0) {
                sum += i;
            }
        }
        
        if (sum == n) {  // 완전수인 경우
            printf("%d =", n);
            for (int i = 1, printed = 0; i < n; i++) {
                if (n % i == 0) {
                    if (printed > 0)
                        printf(" +");
                    printf(" %d", i);
                    printed++;
                }
            }
            printf("\n");
        } else {  // 완전수가 아닌 경우
            printf("%d is NOT perfect.\n", n);
        }
    }
    return 0;
}
