import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int[] arr = new int[N];

        for(int i = 0; i < N; i++) {
            arr[i] = sc.nextInt();
        }

        int min = arr[0];
        int max = arr[0];

        for(int i = 1; i < N; i++) {
            if(arr[i] < min) min = arr[i];
            if(arr[i] > max) max = arr[i];
        }

        System.out.println(min + " " + max);
    }
}
