import java.util.Scanner;
//
public class _1004{
	static public void main(String args[]){
		int x[]={0,0};
		Scanner scan=new Scanner(System.in);
		x[0]=scan.nextInt();
		x[1]=scan.nextInt();
		System.out.print("PROD = "+(x[0]*x[1])+"\n");
		scan.close();
	}
}
