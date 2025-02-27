import java.util.Scanner;

public class Main {
    public static void main (String[] args) {
        Scanner scan = new Scanner (System.in);
        int r = scan.nextInt();
        int gas = scan.nextInt();
        System.out.println((int)(gas / ((4*3.1415*r*r*r)/3)));
    }
}