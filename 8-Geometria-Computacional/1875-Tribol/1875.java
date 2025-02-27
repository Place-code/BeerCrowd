import java.util.Scanner;

public class Main {
    public static int numerize (char team) {
        if ((int)team == 82) {
            return 0;
        }
        else if ((int)team == 71) {
            return 1;
        }
        else {
            return 2;
        }
    }
    public static void main (String[] args) {
        Scanner scan = new Scanner (System.in);
        int pitch[][] = {{2, 1}, {0, 1}, {1, 0}};
        int goals, t1, t2;
        String[] ev = new String[2];
        int cases = scan.nextInt();
        for (int i = 0; i < cases; ++i) {
            int teams[] = {0, 0, 0};
            goals = scan.nextInt();
            scan.nextLine();
            for (int j = 0; j < goals; ++j) {
                ev = scan.nextLine().split(" ");
                t1 = numerize(ev[0].charAt(0)); t2 = numerize(ev[1].charAt(0));
                if (pitch[t1][0] == t2) {
                    ++teams[t1];
                }
                else {
                    teams[t1] += 2;
                }
            }
            if (teams[0] == teams[1] && teams[1] == teams[2]) {
                System.out.print("trempate\n");
            }
            else {
                if (teams[0] > teams[1] && teams[1] >= teams[2] || teams[0] > teams[2] && teams[2] >= teams[1]) {
                    System.out.print("red\n");
                }
                else if (teams[1] > teams[0] && teams[0] >= teams[2] || teams[1] > teams[2] && teams[2] >= teams[0]) {
                    System.out.print("green\n");
                }
                else if (teams[2] > teams[0] && teams[0] >= teams[1] || teams[2] > teams[1] && teams[1] >= teams[0]) {
                    System.out.print("blue\n");
                }
                else {
                    System.out.print("empate\n");
                }
            }
        } 
    }
}