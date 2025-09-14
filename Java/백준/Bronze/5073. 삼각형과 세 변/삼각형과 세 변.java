import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;
        while ((line = br.readLine()) != null) {
            StringTokenizer st = new StringTokenizer(line);
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            if (a == 0 && b == 0 && c == 0) {
                break;
            }

            int[] sides = new int[]{a, b, c};
            Arrays.sort(sides);
            int x = sides[0], y = sides[1], z = sides[2];

            if (x + y <= z) {
                System.out.println("Invalid");
            } else {
                if (x == y && y == z) {
                    System.out.println("Equilateral");
                } else if (x == y || y == z || x == z) {
                    System.out.println("Isosceles");
                } else {
                    System.out.println("Scalene");
                }
            }
        }
        br.close();
    }
}