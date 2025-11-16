#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int age;
    char name[101];
    int order;
} Member;

int cmp(const void *a, const void *b) {
    Member *m1 = (Member *)a;
    Member *m2 = (Member *)b;
    if (m1->age != m2->age) {
        return m1->age - m2->age;
    } else {
        return m1->order - m2->order;
    }
}

int main(void) {
    int N;
    scanf("%d", &N);
    Member *arr = malloc(sizeof(Member) * N);
    for (int i = 0; i < N; i++) {
        scanf("%d %100s", &arr[i].age, arr[i].name);
        arr[i].order = i;
    }
    qsort(arr, N, sizeof(Member), cmp);
    for (int i = 0; i < N; i++) {
        printf("%d %s\n", arr[i].age, arr[i].name);
    }
    free(arr);
    return 0;
}