import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;
import java.util.Arrays;

public class Main {
    static class Member {
        int age;
        String name;
        int order;
        Member(int age, String name, int order) {
            this.age = age;
            this.name = name;
            this.order = order;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine().trim());
        Member[] arr = new Member[N];
        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int age = Integer.parseInt(st.nextToken());
            String name = st.nextToken();
            arr[i] = new Member(age, name, i);
        }
        Arrays.sort(arr, (m1, m2) -> {
            if (m1.age != m2.age) {
                return m1.age - m2.age;
            } else {
                return m1.order - m2.order;
            }
        });
        StringBuilder sb = new StringBuilder();
        for (Member m : arr) {
            sb.append(m.age).append(" ").append(m.name).append("\n");
        }
        System.out.print(sb.toString());
    }
}