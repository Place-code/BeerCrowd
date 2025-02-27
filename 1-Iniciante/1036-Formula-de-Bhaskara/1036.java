import java.util.Scanner;
import java.lang.Math;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        double a = scan.nextDouble();
        double b = scan.nextDouble();
        double c = scan.nextDouble();
        double dt = b*b-4*a*c;
        if (dt < 0 || a == 0) {
            System.out.println("Impossivel calcular");
        }
        else {
            System.out.printf("R1 = %.5f\n", (-b+Math.sqrt(dt))/(2*a));
            System.out.printf("R2 = %.5f\n", (-b-Math.sqrt(dt))/(2*a));
        }
    }
}