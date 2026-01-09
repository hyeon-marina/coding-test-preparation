import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        HashSet<String> heard = new HashSet<>(n * 2);
        for (int i = 0; i < n; i++) {
            heard.add(br.readLine().trim());
        }

        ArrayList<String> ans = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            String name = br.readLine().trim();
            if (heard.contains(name)) ans.add(name);
        }

        Collections.sort(ans);

        StringBuilder sb = new StringBuilder();
        sb.append(ans.size()).append('\n');
        for (String s : ans) sb.append(s).append('\n');
        System.out.print(sb.toString());
    }
}
