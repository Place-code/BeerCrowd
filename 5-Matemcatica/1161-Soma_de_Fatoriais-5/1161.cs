using System;

public class HelloWorld
{
    public static void Main(string[] args)
    {
        while (true){
            try{
                string[] nuns = Console.ReadLine().Split(' ');
                int nu1=int.Parse(nuns[0]);
                long nun1=(long)nu1;
                for(long i=nun1-1; i>0; i-=1){
                    nun1*=i;
                }
                int nu2=int.Parse(nuns[1]);
                long nun2 =(long)nu2;
                for(long i=nun2-1; i>0; i-=1){
                    nun2*=i;
                }
                if (nun1 ==0){
                    nun1=1;
                }
                if (nun2 ==0){
                    nun2=1;
                }
                long result=nun1+nun2;
                Console.WriteLine(result);
            }
            catch(Exception ex){
                break;
            }
        }
    }
}