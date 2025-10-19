import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());
        int[] count = new int[10001];

        for (int i = 0; i < N; i++) {
            int num = Integer.parseInt(br.readLine());
            count[num]++;
        }

        for (int num = 1; num <= 10000; num++) {
            for (int j = 0; j < count[num]; j++) {
                bw.write(num + "\n");
            }
        }
        bw.flush();
        bw.close();
        br.close();
    }
}