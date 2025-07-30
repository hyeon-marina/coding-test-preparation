import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        int[] arr = new int[N];

        // 바구니 초기화
        for (int i = 0; i < N; i++) {
            arr[i] = i + 1;
        }

        // M번 교환
        for (int k = 0; k < M; k++) {
            int i = sc.nextInt() - 1;
            int j = sc.nextInt() - 1;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }

        for (int i = 0; i < N; i++) {
            System.out.print(arr[i] + " ");
        }
        sc.close();
    }
}
