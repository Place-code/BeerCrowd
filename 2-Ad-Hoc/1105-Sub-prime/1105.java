import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		int nbanks, nfare, d, v, c;
		boolean isable;
		Scanner scan = new Scanner(System.in);
		while (true) {
		    nbanks = scan.nextInt();
		    nfare = scan.nextInt();
            if (nbanks == 0 && nfare == 0) break;
		    int[] banks = new int[nbanks];
		    for (int i = 0; i < nbanks; ++i) {
		        banks[i] = scan.nextInt();
		    }
		    for (int i = 0; i < nfare; ++i) {
		        d = scan.nextInt();
		        c = scan.nextInt();
		        v = scan.nextInt();
		        banks[d-1] -= v;
		        banks[c-1] += v;
		    }
		    isable = true;
		    for (int i = 0; i < nbanks; ++i) {
		        if (banks[i] < 0) {
		            isable = false;
		            break;
		        }
		    }
		    if (isable) {
		        System.out.println("S");
		    }
		    else {
		        System.out.println("N");
		    }
		}
	}
}