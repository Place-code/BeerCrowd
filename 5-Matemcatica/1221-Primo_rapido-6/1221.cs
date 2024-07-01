using System;

public class HelloWorld
{
    public static void Main(string[] args)
    {
        int repeat=int.Parse(Console.ReadLine());
        for(int g=0; g<repeat; g++){
            long num=long.Parse(Console.ReadLine());
            double hh=Math.Pow(num, 0.5);
            long hg = (long)Math.Round(hh);
            string result="Prime";
            for(long i=3; i<hg+1; i++){
                if(num%i==0){
                    result="Not Prime";
                }
            }
            Console.WriteLine(result);
            
        }
            
    }
}