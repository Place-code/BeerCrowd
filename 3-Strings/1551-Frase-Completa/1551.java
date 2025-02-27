import java.util.Scanner;
public class Main {
	public static void main (String[] args) {
		Scanner scan = new Scanner(System.in);
		char[] text = new char[1000];
		boolean[] alpha = new boolean[26];
		int cases = scan.nextInt(), sum;
        scan.nextLine();
		for (int i = 0; i < cases; ++i) {
			for (int q = 0; q < 26; ++q) {
				alpha[q] = false;
			}
			text = scan.nextLine().toCharArray();
			for (int q = 0; q < text.length; ++q) {
				if (text[q] != ' ' && text[q] != ',') {
					alpha[(int)text[q]-97] = true;
				}
			}
			sum = 0;
			for (int q = 0; q < 26; ++q) {
				if (alpha[q]) {
					++sum;
				}
			}
			if (sum == 26) {
				System.out.println("frase completa");
			}
			else if (sum >= 13) {
				System.out.println("frase quase completa");
			}
			else {
				System.out.println("frase mal elaborada");
			}
		}
	}
}