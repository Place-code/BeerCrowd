import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int[] coord = new int[4];
        Scanner scan = new Scanner(System.in);
        while (true) {
            for (int i = 0; i < 4; ++i) {
                coord[i] = scan.nextInt();
            }
            if (coord[0] == 0 && coord[1] == 0 && coord[2] == 0 && coord[3] == 0) {
                break;   
            }
            else if (coord[0] == coord[2] && coord[1] == coord[3]) {
                System.out.println("0");
            }
            else if (((coord[0] - coord[1] == coord[2] - coord[3]) || (coord[0] + coord[1] == coord[2] + coord[3])) || (coord[0] == coord[2] || coord[1] == coord[3])) {
                System.out.println("1");
            }
            else {
                System.out.println("2");
            }
        }   
    }
}