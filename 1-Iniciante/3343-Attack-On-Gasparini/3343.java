import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner (System.in);
		int len = 1, hit;
		int n = scan.nextInt();
		int x = scan.nextInt();
		int[] attacks = new int[n]; int[] walls = new int[n];
		int[] indexes = {0, 0, 0}; int[] damage = new int[3];
		scan.nextLine();
		String Sattacks = scan.nextLine();
		walls[0] = x;
		for (int i = 0; i < n; ++i) {
		    if (Sattacks.charAt(i) == 'P') {
		        attacks[i] = 0;
		    }
		    else if (Sattacks.charAt(i) == 'M') {
		        attacks[i] = 1;
		    }
		    else {
		        attacks[i] = 2;
		    }
		}
		damage[0] = scan.nextInt();
		damage[1] = scan.nextInt();
		damage[2] = scan.nextInt();
		for (int i = 0; i < n; ++i) {
            hit = damage[attacks[i]];
            while (walls[indexes[attacks[i]]] < hit) {
                ++indexes[attacks[i]];
                if (indexes[attacks[i]] == len) {
                    walls[len] = x;
                    ++len;
                }
            }
            walls[indexes[attacks[i]]] -= hit;
        }
        System.out.println(len);
	}
}