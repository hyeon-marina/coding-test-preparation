import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[] arr = new String[5];
        for (int i = 0; i < 5; i++) {
            arr[i] = sc.nextLine();
        }

        StringBuilder sb = new StringBuilder();
        for (int col = 0; col < 15; col++) {
            for (int row = 0; row < 5; row++) {
                if (col < arr[row].length()) {
                    sb.append(arr[row].charAt(col));
                }
            }
        }
        System.out.println(sb.toString());
    }
}
