import java.util.Scanner;
import java.lang.Math;

public class Main {
	public static int mdc (int a, int b) {
		int divcom = 1;
		while (b != 0) {
		    int temp = b;
		    b = a % b;
		    a = temp;
		}
		return Math.abs(a);
	}
	public static void format (int num, int den) {
		int divcom = mdc(num, den);
		System.out.printf("%d/%d = %d/%d\n", num, den, num/divcom, den/divcom);
	}
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int cases = scan.nextInt();
		scan.nextLine();
		for (int i = 0; i < cases; ++i) {
			String[] tokens = scan.nextLine().split(" ");
			int n1 = Integer.parseInt(tokens[0]);
			int d1 = Integer.parseInt(tokens[2]);
			char op = tokens[3].charAt(0);
			int n2 = Integer.parseInt(tokens[4]);
			int d2 = Integer.parseInt(tokens[6]);
			int num, den;
			if (op == '+') {
				num = n1*d2+n2*d1;
				den = d1*d2;
			}
			else if (op == '-') {
				num = n1*d2-n2*d1;
				den = d1*d2;
			}
			else if (op == '*') {
				num = n1*n2;
				den = d1*d2;
			}
			else {
				num = n1*d2;
				den = n2*d1;
			}
			format(num, den);
		}
	}
}