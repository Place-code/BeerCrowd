import java.util.Scanner;

public class Main {
    public static int flavious (int n, int k) {
        int i = 1, ans = 0;
        while (i <= n) {
            ans = (ans + k) % i;
            ++i;
        }
        return ans+1;
    }
    public static void main (String[] args) {
        Scanner scan = new Scanner(System.in);
        int len = scan.nextInt();
        for (int i = 1; i <= len; ++i) {
            System.out.printf("Case %d: %d\n", i, flavious(scan.nextInt(), scan.nextInt()));
        }
    }
}