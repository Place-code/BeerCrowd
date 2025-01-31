import java.util.Scanner;
//
public class _1007{
	public static void main(String args[]){
		int x[]={0,0};
		double y;
		Scanner scan=new Scanner(System.in);
		x[0]=scan.nextInt();
		x[1]=scan.nextInt();
		System.out.printf("NUMBER = %d%nSALARY = U$%.2f ",x[0],x[1]*scan.nextDouble());
	}
}
