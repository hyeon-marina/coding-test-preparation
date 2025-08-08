#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char s[1000001];
    fgets(s, sizeof(s), stdin);  // 전체 라인 입력 받기

    int count = 0;
    int in_word = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] != ' ' && s[i] != '\n') {
            if (in_word == 0) {
                in_word = 1;
                count++;
            }
        } else {
            in_word = 0;
        }
    }

    printf("%d\n", count);
    return 0;
}
