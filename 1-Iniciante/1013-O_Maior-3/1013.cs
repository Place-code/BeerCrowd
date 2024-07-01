using System;

public class HelloWorld
{
    public static void Main(string[] args)
    {
        string[] x = Console.ReadLine().Split(' ');
        int[] l = {int.Parse(x[0]), int.Parse(x[1]), int.Parse(x[2])};
        Array.Sort(l);
        Console.WriteLine($"{l[2]} eh o maior");
    }
}