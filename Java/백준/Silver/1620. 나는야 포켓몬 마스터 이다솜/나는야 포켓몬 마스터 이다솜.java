import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        String[] numToName = new String[n + 1];
        HashMap<String, Integer> nameToNum = new HashMap<>(n * 2);

        for (int i = 1; i <= n; i++) {
            String name = br.readLine().trim();
            numToName[i] = name;
            nameToNum.put(name, i);
        }

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < m; i++) {
            String q = br.readLine().trim();
            char c = q.charAt(0);
            if (c >= '0' && c <= '9') {
                int idx = Integer.parseInt(q);
                sb.append(numToName[idx]).append('\n');
            } else {
                sb.append(nameToNum.get(q)).append('\n');
            }
        }

        System.out.print(sb.toString());
    }
}
