import java.util.Scanner;
import java.lang.Math;

public class Main{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int r1, r2, c1x, c1y, c2x, c2y;
        while (scan.hasNext()) {
            r1 = scan.nextInt();
            c1x = scan.nextInt();
            c1y = scan.nextInt();
            r2 = scan.nextInt();
            c2x = scan.nextInt();
            c2y = scan.nextInt();
            if (Math.sqrt((c1x-c2x)*(c1x-c2x)+(c1y-c2y)*(c1y-c2y)) + r2 <= r1) {
                System.out.println("RICO");
            }
            else {
                System.out.println("MORTO");
            }
        }
	}
}