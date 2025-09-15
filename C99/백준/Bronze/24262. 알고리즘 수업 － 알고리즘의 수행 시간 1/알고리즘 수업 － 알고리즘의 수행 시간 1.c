#include <stdio.h>

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    // 코드1은 무조건 한 번 실행됨
    printf("1\n");
    // 시간 복잡도 O(1)의 최고차항 차수는 0
    printf("0\n");
    return 0;
}