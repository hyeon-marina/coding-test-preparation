#include <stdio.h>

int n, m;
int arr1[101][101], arr2[101][101];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int k = 0; k < m; k++)
            scanf("%d", &arr1[i][k]);

    for (int i = 0; i < n; i++)
        for (int k = 0; k < m; k++)
            scanf("%d", &arr2[i][k]);

    for (int i = 0; i < n; i++) {
        for (int k = 0; k < m; k++)
            printf("%d ", arr1[i][k] + arr2[i][k]);
        printf("\n");
    }
    return 0;
}
