using System;

public class HelloWorld
{
    public static void Main(string[] args)
    {
        string[] osnun = Console.ReadLine().Split(' ');
        double a = double.Parse(osnun[0]);
        double b = double.Parse(osnun[1]);
        double c = double.Parse(osnun[2]);
        double p = 3.14159;
        Console.WriteLine($"TRIANGULO: {(a*c)/2:f3}");
        Console.WriteLine($"CIRCULO: {p*(c*c):f3}");
        Console.WriteLine($"TRAPEZIO: {((a+b)*c)/2:f3}");
        Console.WriteLine($"QUADRADO: {b*b:f3}");
        Console.WriteLine($"RETANGULO: {a*b:f3}");
        
    }
}