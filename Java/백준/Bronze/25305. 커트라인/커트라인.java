import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        int[] scores = new int[N];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            scores[i] = Integer.parseInt(st.nextToken());
        }
        // 내림차순 정렬: 오름차순 정렬 후 뒤에서 k번째 또는 반대로 정렬
        Arrays.sort(scores);
        // 오름차순으로 정렬했을 때, 상을 받는 사람 중 가장 낮은 점수는 인덱스 N-k
        System.out.println(scores[N - k]);
        br.close();
    }
}