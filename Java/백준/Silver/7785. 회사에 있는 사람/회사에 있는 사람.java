import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().trim());

        HashSet<String> present = new HashSet<>();

        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String name = st.nextToken();
            String action = st.nextToken();
            if (action.equals("enter")) present.add(name);
            else present.remove(name);
        }

        ArrayList<String> list = new ArrayList<>(present);
        list.sort(Collections.reverseOrder());

        StringBuilder sb = new StringBuilder();
        for (String name : list) sb.append(name).append('\n');
        System.out.print(sb.toString());
    }
}
