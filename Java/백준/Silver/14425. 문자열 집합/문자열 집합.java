import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        HashSet<String> set = new HashSet<>(n * 2);

        for (int i = 0; i < n; i++) {
            set.add(br.readLine().trim());
        }

        int ans = 0;
        for (int i = 0; i < m; i++) {
            if (set.contains(br.readLine().trim())) ans++;
        }

        System.out.println(ans);
    }
}
