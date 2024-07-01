using System;

public class HelloWorld
{
    public static void Main(string[] args)
    {
        int x = int.Parse(Console.ReadLine());
        int y = int.Parse(Console.ReadLine());
        int z = int.Parse(Console.ReadLine());
        int[] l = {y, z, x-y-z};
        Array.Sort(l);
        Console.WriteLine(l[2]);
    }
}