using System;
public class HelloWorld
{
    public static void Main(string[] args)
    {
        double b = double.Parse(Console.ReadLine());
        double t = double.Parse(Console.ReadLine());
        
        double te = ((b+t)*70)/2;
        
        if(te == 5600){
            Console.WriteLine(0);
        }
        
        else if(te>5600){
            Console.WriteLine(1);
        }
        else{
            Console.WriteLine(2);
        }
    }
}