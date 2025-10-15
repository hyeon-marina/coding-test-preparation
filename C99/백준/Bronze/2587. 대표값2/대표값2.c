#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int*)a) - (*(int*)b);
}

int main() {
    int nums[5];
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        scanf("%d", &nums[i]);
        sum += nums[i];
    }
    qsort(nums, 5, sizeof(int), cmp);
    int avg = sum / 5;
    int mid = nums[2];
    printf("%d\n%d\n", avg, mid);
    return 0;
}