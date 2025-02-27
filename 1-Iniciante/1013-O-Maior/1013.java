import java.util.Scanner;
import java.lang.Math;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int a = scan.nextInt();
        int b = scan.nextInt();
        int c = scan.nextInt();
        int maiorAB = (a+b+Math.abs(a-b))/2;
        if (maiorAB > c) {
            System.out.printf("%d eh o maior\n", maiorAB);   
        }
        else {
            System.out.printf("%d eh o maior\n", c);
        }
    }
}