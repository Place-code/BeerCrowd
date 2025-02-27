import java.util.Scanner;

public class Main {
    public static void main (String[] args) {
        int ncities, nfrontiers, qnt = 0, city1, city2;
        Scanner scan = new Scanner(System.in);
        ncities = scan.nextInt();
        nfrontiers = scan.nextInt();
        boolean cities[] = new boolean[ncities];
        for (int i = 0; i < ncities; ++i) {
            cities[i] = false;
        }
        for (int i = 0; i < nfrontiers; ++i) {
            city1 = scan.nextInt();
            city2 = scan.nextInt();
            if (!cities[city1-1] && !cities[city2-1]) {
                ++qnt;
            }
            cities[city1-1] = true;
            cities[city2-1] = true;
        }
        for (int i = 0; i < ncities; ++i) {
            if (!cities[i]) ++qnt;
        }
        System.out.println(qnt);   
    }
}