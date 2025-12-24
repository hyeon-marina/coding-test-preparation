#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 501

int cmp_str(const void *a, const void *b) {
    const char *sa = *(const char * const *)a;
    const char *sb = *(const char * const *)b;
    return strcmp(sa, sb);
}

int main(void) {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    char **arr = (char **)malloc(sizeof(char*) * n);
    for (int i = 0; i < n; i++) {
        arr[i] = (char *)malloc(MAXLEN);
        scanf("%500s", arr[i]);
    }

    qsort(arr, n, sizeof(char*), cmp_str);

    int ans = 0;
    char query[MAXLEN];
    for (int i = 0; i < m; i++) {
        scanf("%500s", query);
        char *key = query;
        char **found = (char **)bsearch(&key, arr, n, sizeof(char*), cmp_str);
        if (found != NULL) ans++;
    }

    printf("%d\n", ans);

    for (int i = 0; i < n; i++) free(arr[i]);
    free(arr);

    return 0;
}
