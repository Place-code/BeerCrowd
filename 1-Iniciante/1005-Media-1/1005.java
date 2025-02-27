import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.printf("MEDIA = %.5f\n", (scan.nextDouble()*3.5+scan.nextDouble()*7.5)/11);
    }
}