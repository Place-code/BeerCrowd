using System;

public class HelloWorld
{
    public static void Main(string[] args)
    {
        string[] x = Console.ReadLine().Split(' ');
        string[] y = Console.ReadLine().Split(' ');
        
        double x1, x2, y1, y2;
        
        x1=double.Parse(x[0]);
        y1=double.Parse(x[1]);
        
        x2=double.Parse(y[0]);
        y2=double.Parse(y[1]);
        
        Console.WriteLine($"{Math.Pow(((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)), 0.5):f4}");
    }
}