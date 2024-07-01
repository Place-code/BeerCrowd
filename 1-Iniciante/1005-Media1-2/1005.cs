using System;

public class HelloWorld
{
    public static void Main(string[] args)
    {
        Console.WriteLine($"MEDIA = {(double.Parse(Console.ReadLine()) * 3.5 + double.Parse(Console.ReadLine()) * 7.5)/11:f5}");
    }
}