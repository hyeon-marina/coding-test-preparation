import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[][] paper = new int[100][100];

        for (int k = 0; k < N; k++) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            for (int i = x; i < x + 10; i++) {
                for (int j = y; j < y + 10; j++) {
                    paper[i][j] = 1;
                }
            }
        }
        int total = 0;
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                total += paper[i][j];
            }
        }
        System.out.println(total);
        sc.close();
    }
}
