#include <stdio.h>
#include <string.h>

int main() {
    char str[101];
    scanf("%s", str);
    char *croatia[] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

    for (int i = 0; i < 8; i++) {
        char *p;
        while ((p = strstr(str, croatia[i])) != NULL) {
            // 발견된 곳을 '*'로 치환하고 나머지 글자들은 앞으로 땡기는 작업
            int len = strlen(croatia[i]);
            *p = '*';  // 첫 글자만 '*'로 치환
            memmove(p + 1, p + len, strlen(p + len) + 1);  // 나머지 글자 땡기기
        }
    }

    printf("%lu\n", strlen(str));
    return 0;
}
