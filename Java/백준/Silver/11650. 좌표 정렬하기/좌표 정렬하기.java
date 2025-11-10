import java.io.*;
import java.util.*;

public class Main {
    static class Point {
        int x, y;
        Point(int x, int y) { this.x = x; this.y = y; }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(br.readLine());
        Point[] arr = new Point[n];
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            arr[i] = new Point(x, y);
        }
        Arrays.sort(arr, new Comparator<Point>() {
            @Override
            public int compare(Point p1, Point p2) {
                if (p1.x != p2.x) return p1.x - p2.x;
                return p1.y - p2.y;
            }
        });
        for (Point p : arr) {
            sb.append(p.x).append(" ").append(p.y).append("\n");
        }
        System.out.print(sb.toString());
    }
}