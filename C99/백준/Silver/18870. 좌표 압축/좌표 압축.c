#include <stdio.h>
#include <stdlib.h>

int cmp_int(const void *a, const void *b){
    int da = *(int*)a;
    int db = *(int*)b;
    if(da < db) return -1;
    else if(da > db) return 1;
    else return 0;
}

int main(){
    int N;
    scanf("%d", &N);
    int *arr = malloc(sizeof(int)*N);
    int *sorted = malloc(sizeof(int)*N);
    for(int i=0; i<N; i++){
        scanf("%d", &arr[i]);
        sorted[i] = arr[i];
    }
    qsort(sorted, N, sizeof(int), cmp_int);

    // 중복 제거 및 매핑
    // 간단히 이중 배열 + 이진탐색으로 구현 가능
    int uniqueCount = 0;
    int *uniq = malloc(sizeof(int)*N);
    uniq[0] = sorted[0];
    uniqueCount = 1;
    for(int i=1; i<N; i++){
        if(sorted[i] != uniq[uniqueCount-1]){
            uniq[uniqueCount++] = sorted[i];
        }
    }

    // 각 원소에 대해 이진탐색으로 인덱스 찾기
    for(int i=0; i<N; i++){
        int v = arr[i];
        int l = 0, r = uniqueCount - 1;
        while(l <= r){
            int m = (l + r) / 2;
            if(uniq[m] == v){
                printf("%d ", m);
                break;
            } else if(uniq[m] < v){
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
    }

    free(arr);
    free(sorted);
    free(uniq);
    return 0;
}