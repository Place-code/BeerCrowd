import java.util.Scanner;
//
public class _1003{
	public static void main(String args[]){
		int x[]={0,0};
		Scanner scan=new Scanner(System.in);
		x[0]=scan.nextInt();
		x[1]=scan.nextInt();
		System.out.print("SOMA = "+(x[0]+x[1])+"\n");
		scan.close();
	}
}
