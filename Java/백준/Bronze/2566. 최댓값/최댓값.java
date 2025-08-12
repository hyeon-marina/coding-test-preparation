import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[][] arr = new int[9][9];
        int max = arr[0][0], maxRow = 1, maxCol = 1; // 1-based index

        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                arr[i][j] = sc.nextInt();
                if(arr[i][j] > max) {
                    max = arr[i][j];
                    maxRow = i + 1;
                    maxCol = j + 1;
                }
            }
        }
        System.out.println(max);
        System.out.println(maxRow + " " + maxCol);
    }
}
