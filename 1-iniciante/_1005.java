import java.util.Scanner;
//
public class _1005{
	public static void main(String args[]){
		double x[]={0.0,0.0};
		Scanner scan=new Scanner(System.in);
		x[0]=scan.nextDouble();
		x[1]=scan.nextDouble();
		scan.close();
		System.out.printf("MEDIA = %.5f%n",(x[0]*3.5+x[1]*7.5)/11);
	}
}
