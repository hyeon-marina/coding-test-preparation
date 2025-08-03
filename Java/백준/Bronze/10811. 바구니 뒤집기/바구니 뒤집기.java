import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int M = sc.nextInt();

        int[] arr = new int[N];
        for (int i = 0; i < N; i++) arr[i] = i + 1;

        for (int t = 0; t < M; t++) {
            int i = sc.nextInt() - 1; // 0-based index
            int j = sc.nextInt() - 1;
            while (i < j) {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
                i++;
                j--;
            }
        }
        for (int k = 0; k < N; k++) {
            System.out.print(arr[k] + " ");
        }
    }
}
