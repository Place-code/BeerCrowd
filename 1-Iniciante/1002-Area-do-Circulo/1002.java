import java.util.Scanner;

public class Main{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        double ray = scanner.nextDouble();
        System.out.printf("A=%.4f\n", ray*ray*3.14159);
    }
}