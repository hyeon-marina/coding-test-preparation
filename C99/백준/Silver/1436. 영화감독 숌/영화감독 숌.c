#include <stdio.h>
#include <string.h>

int main() {
    int N;
    if (scanf("%d", &N) != 1) return 0;

    int count = 0;
    int num = 666;
    char buf[30];
    while (1) {
        sprintf(buf, "%d", num);
        if (strstr(buf, "666") != NULL) {
            count++;
            if (count == N) {
                printf("%d\n", num);
                break;
            }
        }
        num++;
    }
    return 0;
}