using System;

public class HelloWorld
{
    public static void Main(string[] args)
    {

    string nada = Console.ReadLine();
    double n1=Math.Round(double.Parse(Console.ReadLine()), 2);
    double ntot=Math.Round(double.Parse(Console.ReadLine()), 2);

    double n2 = ntot*(15.00 / 100.00);

    double tot = n1+n2;

    Console.WriteLine($"TOTAL = R$ {tot.ToString("0.00")}");
    }
}