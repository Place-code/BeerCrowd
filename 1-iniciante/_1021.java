import java.util.Scanner;
//
public class Main{
	public static void main(String args[]){
		Scanner scan=new Scanner(System.in);
		double x=scan.nextDouble();
		System.out.printf("NOTAS:%n%.0f nota(s) de R$ 100.00%n%.0f nota(s) de R$ 50.00%n%.0f nota(s) de R$ 20.00%n%.0f nota(s) de R$ 10.00%n%.0f nota(s) de R$ 5.00%n%.0f nota(s) de R$ 2.00%n",x/100-x%100/100,x%100/50-x%100%50/50,x%100%50/20-x%100%50%20/20,x%100%50%20/10-x%100%50%20%10/10,x%100%50%20%10/5-x%100%50%20%10%5/5,x%100%50%20%10%5/2-x%100%50%20%10%5%2/2);
		x=x%100%50%20%10%5%2;
		System.out.printf("MOEDAS:%n%.0f moeda(s) de R$ 1.00%n%.0f moeda(s) de R$ 0.50%n%.0f moeda(s) de R$ 0.25%n%.0f moeda(s) de R$ 0.10%n%.0f moeda(s) de R$ 0.05%n%.0f moeda(s) de R$ 0.01%n",x-x%1,x%1/0.5-x%1%0.5/0.5,x%1%0.5/0.25-x%1%0.5%0.25/0.25,x%1%0.5%0.25/0.1-x%1%0.5%0.25%0.1/0.1,x%1%0.5%0.25%0.1/0.05-x%1%0.5%0.25%0.1%0.05/0.05,x%1%0.5%0.25%0.1%0.05/0.01);
	}
}
