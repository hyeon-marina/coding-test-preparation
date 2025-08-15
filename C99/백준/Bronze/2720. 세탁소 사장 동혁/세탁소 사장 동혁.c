#include <stdio.h>
int main(void) {
    int T, C;
    scanf("%d", &T);
    for (int i = 0; i < T; i++){
        scanf("%d", &C);
        printf("%d %d %d %d\n", C/25, (C%25)/10, (C%25%10)/5, (C%25%10%5)/1);
    }
    return 0;
}
