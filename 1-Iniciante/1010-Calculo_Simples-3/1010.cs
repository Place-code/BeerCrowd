using System;

public class HelloWorld
{
    public static void Main(string[] args)
    {
        string[] a = Console.ReadLine().Split(' ');
        double a1 = double.Parse(a[1]);
        double a2 = double.Parse(a[2]);
        
        string[] b = Console.ReadLine().Split(' ');
        double b1 = double.Parse(b[1]);
        double b2 = double.Parse(b[2]);
        
        Console.WriteLine($"VALOR A PAGAR: R$ {a1*a2+b1*b2:f2}");
    }
}