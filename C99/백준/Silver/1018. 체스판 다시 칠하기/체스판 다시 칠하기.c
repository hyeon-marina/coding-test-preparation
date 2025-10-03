#include <stdio.h>
#include <limits.h>

char board[50][51];

int min(int a, int b) {
    return a < b ? a : b;
}

int countRepaint(int sy, int sx) {
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            char c = board[sy + i][sx + j];
            if ((i + j) % 2 == 0) {
                if (c != 'W') cnt1++;
                if (c != 'B') cnt2++;
            } else {
                if (c != 'B') cnt1++;
                if (c != 'W') cnt2++;
            }
        }
    }
    return min(cnt1, cnt2);
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        scanf("%s", board[i]);
    }
    int ans = INT_MAX;
    for (int i = 0; i + 8 <= N; i++) {
        for (int j = 0; j + 8 <= M; j++) {
            int cur = countRepaint(i, j);
            if (cur < ans) ans = cur;
        }
    }
    printf("%d\n", ans);
    return 0;
}