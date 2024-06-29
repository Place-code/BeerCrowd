using System;

public class HelloWorld
{
    public static void Main(string[] args)
    {
        string[] sbdc = Console.ReadLine().Split(' ');
        
        int a = int.Parse(sbdc[0]);
        int b = int.Parse(sbdc[1]);
        
        int ko = a / b;
        string jk =Convert.ToString(ko);
        string[] dk = jk.Split('.');
        string kj = dk[0];
        int q = int.Parse(kj);
        int r = a % b;
        if (r < 0 & b > 0){
            r += b;
            q -= 1;
        }
        else if (r < 0 & b < 0){
            r -= b;
            q += 1;
        }
        Console.WriteLine("{0} {1}", q, r);
    }
}