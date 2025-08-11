import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int count = 0;

        for (int i = 0; i < N; i++) {
            String word = br.readLine();
            if (isGroupWord(word)) {
                count++;
            }
        }
        System.out.println(count);
    }

    public static boolean isGroupWord(String word) {
        boolean[] visited = new boolean[26];
        char prev = 0;

        for (int i = 0; i < word.length(); i++) {
            char curr = word.charAt(i);
            if (curr != prev) {
                if (visited[curr - 'a']) {
                    return false;
                }
                visited[curr - 'a'] = true;
                prev = curr;
            }
        }
        return true;
    }
}
