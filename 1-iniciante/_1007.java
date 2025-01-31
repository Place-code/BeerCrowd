import java.util.Scanner;
//
public class _1007{
	public static void main(String args[]){
		int x[]={0,0,0,0};
		Scanner scan=new Scanner(System.in);
		for(int i=0;i<4;++i)x[i]=scan.nextInt();
		scan.close();
		System.out.print("DIFERENCA = "+(x[0]*x[1]-x[2]*x[3])+"\n");
	}
}
