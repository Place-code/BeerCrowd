import java.util.Scanner;
//
public class _1002{//1002
	public final static double pi=3.14159;
	public static void main(String args[]){
		Scanner scan=new Scanner(System.in);
		double area=scan.nextDouble();
		System.out.printf("A=%.4f%n",(Math.pow(area,2)*pi));
		scan.close();
	}
}

