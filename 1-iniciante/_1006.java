import java.util.Scanner;
//
public class _1006{
	public static void main(String args[]){
		double x[]={0,0,0};
		Scanner scan=new Scanner(System.in);
		x[0]=scan.nextDouble();
		x[1]=scan.nextDouble();
		x[2]=scan.nextDouble();
		scan.close();
		System.out.printf("MEDIA = %.1f%n",(x[0]*2+x[1]*3+x[2]*5)/10);
	}
}
