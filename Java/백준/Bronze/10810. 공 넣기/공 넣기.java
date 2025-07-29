import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt(); // 바구니의 개수
        int M = sc.nextInt(); // 작업 횟수
        int[] arr = new int[N];

        for (int m = 0; m < M; m++) {
            int i = sc.nextInt();
            int j = sc.nextInt();
            int k = sc.nextInt();
            for (int x = i-1; x < j; x++) {
                arr[x] = k;
            }
        }

        for (int x = 0; x < N; x++) {
            System.out.print(arr[x] + " ");
        }
    }
}
