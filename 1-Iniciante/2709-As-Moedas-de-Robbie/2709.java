import java.util.Scanner;
import java.lang.Math;

public class Main {
    public static boolean prime(int num) {
        if (num < 2) {
            return false;
        }
        for (int i = 2; i <= Math.sqrt(num); ++i) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int coins, jump;
        while (scan.hasNext()) {
            coins = scan.nextInt();
            int values[] = new int[coins+1], sum = 0;
            for (int i = 0; i < coins; ++i) {
                values[i] = scan.nextInt();
            }
            jump = scan.nextInt();
            for (int i = coins - 1; i >= 0; i -= jump) {
                sum += values[i];
            }
            if (prime(sum)) {
                System.out.println("You’re a coastal aircraft, Robbie, a large silver aircraft.");
            }
            else {
                System.out.println("Bad boy! I’ll hit you.");
            }
        }
    }
}