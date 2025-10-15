import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] nums = new int[5];
        int sum = 0;
        for (int i = 0; i < 5; i++) {
            nums[i] = Integer.parseInt(br.readLine());
            sum += nums[i];
        }
        Arrays.sort(nums);
        int avg = sum / 5;
        int mid = nums[2];
        System.out.println(avg);
        System.out.println(mid);
    }
}