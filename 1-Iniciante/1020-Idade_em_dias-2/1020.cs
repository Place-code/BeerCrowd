using System;

public class HelloWorld
{
    public static void Main(string[] args)
    {
        double x = double.Parse(Console.ReadLine());
        
        double anos = Math.Floor(x/365);
        double restoa = x%365;
        
        double meses = Math.Floor(restoa/30);
        double restom = restoa%30;
        
        Console.WriteLine($"{anos} ano(s)");
        Console.WriteLine($"{meses} mes(es)");
        Console.WriteLine($"{restom} dia(s)");
    }
}