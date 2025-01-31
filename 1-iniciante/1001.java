import java.util.Scanner;

public class Main{
	public static void main(String[] args){
		int x[]={0,0};
		Scanner scan=new Scanner(System.in);
		x[0]=scan.nextInt();
		x[1]=scan.nextInt();
		scan.close();
		System.out.print("X = "+(x[0]+x[1])+"\n");
	}
}
