#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[6];
    int enter;   // 1 if enter, 0 if leave
    int idx;     // input order
} Record;

int cmp_record(const void *a, const void *b) {
    const Record *ra = (const Record*)a;
    const Record *rb = (const Record*)b;
    int c = strcmp(ra->name, rb->name);
    if (c != 0) return c;
    // 같은 이름이면 입력 순서(시간) 오름차순
    return (ra->idx > rb->idx) - (ra->idx < rb->idx);
}

int cmp_str_desc(const void *a, const void *b) {
    const char *sa = *(const char * const *)a;
    const char *sb = *(const char * const *)b;
    return strcmp(sb, sa); // desc
}

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    Record *arr = (Record*)malloc(sizeof(Record) * n);
    for (int i = 0; i < n; i++) {
        char action[6];
        scanf("%5s %5s", arr[i].name, action);
        arr[i].enter = (action[0] == 'e') ? 1 : 0;
        arr[i].idx = i;
    }

    qsort(arr, n, sizeof(Record), cmp_record);

    char **result = (char**)malloc(sizeof(char*) * n);
    int rcnt = 0;

    int i = 0;
    while (i < n) {
        int j = i;
        int last = arr[i].enter; // idx 오름차순이므로 그룹 마지막이 진짜 마지막 기록
        while (j < n && strcmp(arr[i].name, arr[j].name) == 0) {
            last = arr[j].enter;
            j++;
        }
        if (last == 1) {
            result[rcnt] = (char*)malloc(6);
            strcpy(result[rcnt], arr[i].name);
            rcnt++;
        }
        i = j;
    }

    qsort(result, rcnt, sizeof(char*), cmp_str_desc);
    for (int k = 0; k < rcnt; k++) {
        puts(result[k]);
        free(result[k]);
    }

    free(result);
    free(arr);
    return 0;
}
