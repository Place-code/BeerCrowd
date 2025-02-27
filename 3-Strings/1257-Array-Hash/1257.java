import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int cases, el, sum = 0;
        char[] text = new char[51];
        cases = scan.nextInt();
        for (int i = 0; i < cases; ++i) {
            el = scan.nextInt();
            for (int q  = 0; q < el; ++q) {
                text = scan.next().toCharArray();
                for (int z = 0; z < text.length; ++z) {
                    if (text[z] == '\0') {
                        break;
                    }
                    sum += (text[z] - 65) + z + q;
                }
            }
            System.out.println(sum);
            sum = 0;
        }
    }
}