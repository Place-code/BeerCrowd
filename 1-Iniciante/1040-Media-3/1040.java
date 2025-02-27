import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        float media = 0;
        for (int i = 0; i < 3; ++i) {
            media += scan.nextFloat()*(i+2);
        }
        media += scan.nextDouble();
        media /= 10;
        System.out.printf("Media: %.1f\n", media);
        if (media >= 5 && media < 6.9) {
            System.out.println("Aluno em exame.");
            float ex = scan.nextFloat();
            System.out.println("Nota do exame: " + ex);
            media = (media + ex) / 2;
            if (media >= 5) {
                System.out.println("Aluno aprovado.");
            }
            else {
                System.out.println("Aluno reprovado.");
            }
            System.out.printf("Media final: %.1f\n", media);
        }
        else if (media >= 7) {
            System.out.println("Aluno aprovado.");
        }
        else {
            System.out.println("Aluno reprovado.");
        }
    }
}