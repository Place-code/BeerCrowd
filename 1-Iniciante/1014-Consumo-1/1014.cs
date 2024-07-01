using System;

public class HelloWorld
{
    public static void Main(string[] args)
    {
        double x = double.Parse(Console.ReadLine());
        double y = double.Parse(Console.ReadLine());
        
        Console.WriteLine($"{x/y:f3} km/l");
    }
}