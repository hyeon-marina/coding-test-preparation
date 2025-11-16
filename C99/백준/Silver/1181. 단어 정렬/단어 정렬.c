#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b) {
    const char *pa = *(const char **)a;
    const char *pb = *(const char **)b;
    int la = strlen(pa);
    int lb = strlen(pb);
    if (la != lb) return la - lb;
    return strcmp(pa, pb);
}

int main() {
    int n;
    scanf("%d", &n);

    char **arr = malloc(sizeof(char*) * n);
    int count = 0;

    // 남아 있는 개행 제거
    getchar();

    for (int i = 0; i < n; i++) {
        char buf[51];
        fgets(buf, sizeof(buf), stdin);
        buf[strcspn(buf, "\n")] = '\0';

        // 빈 줄이면 다시 입력
        if (buf[0] == '\0') {
            i--;
            continue;
        }

        // 중복 확인
        int duplicate = 0;
        for (int j = 0; j < count; j++) {
            if (strcmp(arr[j], buf) == 0) {
                duplicate = 1;
                break;
            }
        }
        if (!duplicate) {
            arr[count] = malloc(strlen(buf) + 1);
            strcpy(arr[count], buf);
            count++;
        }
    }

    qsort(arr, count, sizeof(char*), cmp);

    for (int i = 0; i < count; i++) {
        printf("%s\n", arr[i]);
        free(arr[i]);
    }
    free(arr);
    return 0;
}