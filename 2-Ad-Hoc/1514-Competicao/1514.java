import java.util.Scanner;

public class Main {
    public static void main (String[] args) {
        Scanner scan = new Scanner (System.in);
        int height, width, cnt, result;
        boolean check1, check2, check3, check4;
        while (true) {
            height = scan.nextInt();
            width = scan.nextInt();
            if (height == 0 && width == 0) break;
            int[][] matrix = new int[height][width];
            check1 = true; check2 = true; check3 = true; check4 = true;
            result = 0;
            String[] column = new String[width];
            scan.nextLine();
            for (int i = 0; i < height; ++i) {
                cnt = 0;
                column = scan.nextLine().split(" ");
                for (int j = 0; j < width; ++j) {
                    matrix[i][j] = Integer.parseInt(String.valueOf(column[j]));
                    if (matrix[i][j] == 1) {
                       ++cnt; 
                    }
                }
                if (cnt == width) {
                    check1 = false;
                }
                else if (cnt == 0) {
                    check4 = false;
                }
            }
            for (int i = 0; i < width; ++i) {
                cnt = 0;
                for (int j = 0; j < height; ++j) {
                    if (matrix[j][i] == 1) {
                        ++cnt;
                    }
                }
                if (cnt == height) {
                    check3 = false;
                }
                else if (cnt == 0) {
                    check2 = false;
                }
            }
            if (check1) ++result; 
            if (check2) ++result; 
            if (check3) ++result; 
            if (check4) ++result;
            System.out.println(result);
        }
    }
}