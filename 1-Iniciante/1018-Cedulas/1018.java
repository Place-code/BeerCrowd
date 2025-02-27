import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int bills[] = {100, 50, 20, 10, 5, 2, 1};
        int val = scan.nextInt();
        System.out.println(val);
        for (int i = 0; i <= 6; ++i) {
            System.out.printf("%d nota(s) de R$ %d,00\n", val/bills[i], bills[i]);
            val -= (val/bills[i])*bills[i];
        }
    }
}