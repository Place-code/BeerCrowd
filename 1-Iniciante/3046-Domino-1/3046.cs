using System;

public class HelloWorld
{
    public static void Main(string[] args)
    {
        int x = int.Parse(Console.ReadLine());
        Console.WriteLine ((int)((x+1)*(x+2))/2);
    }
}