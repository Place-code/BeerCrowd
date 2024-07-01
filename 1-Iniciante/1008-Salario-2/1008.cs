using System;

public class HelloWorld
{
    public static void Main(string[] args)
    {
        var n1 = Console.ReadLine();
        
        double n2 = double.Parse(Console.ReadLine());
        double n3 = double.Parse(Console.ReadLine());
        
        Console.WriteLine ($"NUMBER = {n1}");
        Console.WriteLine ($"SALARY = U$ {n2*n3:f2}");
    }
}