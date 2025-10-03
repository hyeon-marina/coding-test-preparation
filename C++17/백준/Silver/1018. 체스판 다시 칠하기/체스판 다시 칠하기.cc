#include <bits/stdc++.h>
using namespace std;

int countRepaint(const vector<string>& board, int sy, int sx) {
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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<string> board(N);
    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }

    int ans = INT_MAX;
    for (int i = 0; i + 8 <= N; i++) {
        for (int j = 0; j + 8 <= M; j++) {
            ans = min(ans, countRepaint(board, i, j));
        }
    }
    cout << ans << "\n";
    return 0;
}