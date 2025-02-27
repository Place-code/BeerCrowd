import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int people = scan.nextInt();
        float bottle = scan.nextFloat();
        float bowl = scan.nextFloat();
        scan.nextLine();
        String[] contestants = scan.nextLine().split(" ");
        int dose = (int) (bottle/bowl);
        float result = (float)(bottle-bowl*dose);
        if (result == 0) {
            --dose;
            result = (float)(bottle-bowl*dose);
        }
        System.out.printf("%s %.1f\n", contestants[dose%people], result);
    }
}