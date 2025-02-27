import java.util.Scanner;

public class Main {
    public static void main (String[] args) {
        int cases, dx, dy, hx, hy;
        Scanner scan = new Scanner(System.in);
        while (true) {
            cases = scan.nextInt();
            if (cases == 0) break;
            dx = scan.nextInt();
            dy = scan.nextInt();
            for (int i = 0; i < cases; ++i) {
                hx = scan.nextInt();
                hy = scan.nextInt();
                if (hx == dx || hy == dy) {
                    System.out.println("divisa");
                }
                else {
                    if (hx > dx) {
                        if (hy > dy) {
                            System.out.println("NE");
                        }
                        else {
                            System.out.println("SE");
                        }
                    }
                    else {
                        if (hy > dy) {
                            System.out.println("NO");
                        }
                        else {
                            System.out.println("SO");
                        }
                    }
                }
            }
        }
    }
}