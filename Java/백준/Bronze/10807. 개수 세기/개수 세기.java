import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt(); // 정수의 개수
        int[] arr = new int[n];

        // 배열에 값 입력
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        int v = sc.nextInt(); // 찾으려는 정수
        int count = 0;

        // v 개수 세기
        for (int j = 0; j < n; j++) {
            if (arr[j] == v) {
                count++;
            }
        }
        System.out.println(count);
    }
}
