#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int cmp_str(const void *a, const void *b) {
    const char *sa = *(const char **)a;
    const char *sb = *(const char **)b;
    return strcmp(sa, sb);
}

int main(void) {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    char **heard = (char **)malloc(sizeof(char*) * n);
    for (int i = 0; i < n; i++) {
        char buf[21];
        scanf("%20s", buf);
        heard[i] = (char *)malloc(strlen(buf) + 1);
        strcpy(heard[i], buf);
    }

    qsort(heard, n, sizeof(char*), cmp_str);

    char **ans = (char **)malloc(sizeof(char*) * (n < m ? n : m));
    int ans_cnt = 0;

    for (int i = 0; i < m; i++) {
        char buf[21];
        scanf("%20s", buf);
        char *key = buf;
        char **found = (char **)bsearch(&key, heard, n, sizeof(char*), cmp_str);
        if (found != NULL) {
            ans[ans_cnt] = (char *)malloc(strlen(buf) + 1);
            strcpy(ans[ans_cnt], buf);
            ans_cnt++;
        }
    }

    qsort(ans, ans_cnt, sizeof(char*), cmp_str);

    printf("%d\n", ans_cnt);
    for (int i = 0; i < ans_cnt; i++) {
        printf("%s\n", ans[i]);
        free(ans[i]);
    }

    for (int i = 0; i < n; i++) free(heard[i]);
    free(heard);
    free(ans);
    return 0;
}
