using System;

public class HelloWorld
{
    public static void Main(string[] args)
    {
        double x = double.Parse(Console.ReadLine());
        double x1 = double.Parse(Console.ReadLine());
        double x2 = double.Parse(Console.ReadLine());
        Console.WriteLine($"MEDIA = {(x*2+x1*3+x2*5)/10:f1}");
    }
}