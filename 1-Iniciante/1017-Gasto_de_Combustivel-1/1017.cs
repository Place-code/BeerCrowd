using System;

public class HelloWorld
{
    public static void Main(string[] args)
    {
        double x=double.Parse(Console.ReadLine());
        double x1=double.Parse(Console.ReadLine());
        double distancia = x1*x;
        Console.WriteLine($"{distancia/12:f3}");
    }
}