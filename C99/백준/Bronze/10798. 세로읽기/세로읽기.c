#include <stdio.h>
#include <string.h>

int main() {
    char arr[5][16] = {0}; // 최대 15글자 + null
    for (int i = 0; i < 5; i++) {
        scanf("%s", arr[i]);
    }

    for (int col = 0; col < 15; col++) {
        for (int row = 0; row < 5; row++) {
            if (col < strlen(arr[row])) {
                printf("%c", arr[row][col]);
            }
        }
    }
    printf("\n");
    return 0;
}
