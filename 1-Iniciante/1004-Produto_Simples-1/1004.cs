using System;

public class HelloWorld
{
    public static void Main(string[] args)
    {
        Console.WriteLine($"PROD = {int.Parse(Console.ReadLine())*int.Parse(Console.ReadLine())}");
    }
}