import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int num[] = {0, 0};
        float prod[] = {0, 0};
        for (int i = 0; i < 2; ++i) {
            scan.nextInt();
            num[i] = scan.nextInt();
            prod[i] = scan.nextFloat();
        }
        System.out.printf ("VALOR A PAGAR: R$ %.2f\n", num[0]*prod[0]+num[1]*prod[1]);
    }
}