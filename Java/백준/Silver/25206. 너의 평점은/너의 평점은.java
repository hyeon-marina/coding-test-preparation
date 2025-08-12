import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        double totalPoints = 0.0;
        double totalCredits = 0.0;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Map<String, Double> map = new HashMap<>();
        map.put("A+", 4.5); map.put("A0", 4.0);
        map.put("B+", 3.5); map.put("B0", 3.0);
        map.put("C+", 2.5); map.put("C0", 2.0);
        map.put("D+", 1.5); map.put("D0", 1.0);
        map.put("F", 0.0);

        for (int i = 0; i < 20; i++) {
            String[] arr = br.readLine().split(" ");
            double credit = Double.parseDouble(arr[1]);
            String grade = arr[2];
            if (grade.equals("P")) continue;
            totalPoints += credit * map.get(grade);
            totalCredits += credit;
        }
        System.out.println(totalPoints / totalCredits);
    }
}
