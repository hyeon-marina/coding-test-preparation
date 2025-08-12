#include <stdio.h>

int main() {
    int arr[9][9];
    int max = -1, row = 1, col = 1; // 위치 1-based

    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            scanf("%d", &arr[i][j]);
            if (arr[i][j] > max) {
                max = arr[i][j];
                row = i + 1;
                col = j + 1;
            }
        }
    }
    printf("%d\n%d %d\n", max, row, col);
    return 0;
}
