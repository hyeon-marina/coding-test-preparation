import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        char[][] board = new char[N][M];
        for (int i = 0; i < N; i++) {
            board[i] = br.readLine().toCharArray();
        }

        int ans = Integer.MAX_VALUE;
        for (int i = 0; i + 8 <= N; i++) {
            for (int j = 0; j + 8 <= M; j++) {
                ans = Math.min(ans, countRepaint(board, i, j));
            }
        }
        System.out.println(ans);
    }

    static int countRepaint(char[][] board, int sy, int sx) {
        int cnt1 = 0;  // W 시작
        int cnt2 = 0;  // B 시작
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
        return Math.min(cnt1, cnt2);
    }
}