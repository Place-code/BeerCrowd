import java.util.Scanner;

public class Main {
    public static void main (String[] args) {
        Scanner scan = new Scanner (System.in);
        int width, height, cnt;
        boolean filled;
        while (true) {
            filled = false;
            width = scan.nextInt();
            height = scan.nextInt();
            if (width == 0 && height == 0) break;
            scan.nextLine();
            int[][] matrix = new int[height][width];
            for (int i = 0; i < height; ++i) {
                String[] column = scan.nextLine().split(" ");
                for (int q = 0; q < width; ++q) {
                    matrix[i][q] = Integer.parseInt(String.valueOf(column[q]));
                }
            }
            for (int column = 0; column < width; ++column) {
                cnt = 0;
                for (int row = 0; row < height; ++row) {
                    if (matrix[row][column] == 1) {
                        ++cnt; 
                    }
                    else {
                        break;
                    }
                }
                if (cnt == height) {
                    filled = true;
                    break;
                }
            }
            if (filled) {
                System.out.println("yes");
            }
            else {
                System.out.println("no");
            }
        }
    }
}