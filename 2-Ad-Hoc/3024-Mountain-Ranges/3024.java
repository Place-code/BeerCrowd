import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int points = scan.nextInt();
		int quota = scan.nextInt();
		int ant = scan.nextInt();
		int curr, index = 0, cnt[] = new int[points], max = 0;
		boolean onsequence = false;
		for (int i = 0; i < points-1; ++i) {
		    curr = scan.nextInt();
		    if (curr - ant <= quota) {
		        onsequence = true;
		    }
		    else {
		        onsequence = false;
		        ++index;
		    }
		    if (onsequence) ++cnt[index];
		    ant = curr;
		}
		for (int i = 0; i < points; ++i) {
		    if (max < cnt[i]) max = cnt[i];
		}
		System.out.println(max+1);
	}
}
