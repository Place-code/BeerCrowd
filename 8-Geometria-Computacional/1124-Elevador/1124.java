import java.util.Scanner;
import java.lang.Math;

public class Main{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int width, height, r1, r2;
        while (true) {
            width = scan.nextInt();
            height = scan.nextInt();
            r1 = scan.nextInt();
            r2 = scan.nextInt();
            if (width == 0 && height == 0 && r1 == 0 && r2 == 0) break;
            if (r1*2 <= width && r2*2 <= width && r1*2 <= height && r2*2 <= height && Math.sqrt(Math.pow(height-r1-r2, 2)+Math.pow(width-r1-r2, 2)) >= r1+r2) {
                System.out.println("S");
            }
            else {
                System.out.println("N");
            }
        }
	}
}