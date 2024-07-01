using System;

public class HelloWorld
{
    public static void Main(string[] args)
    {
        double[] notas = { 100.0,50.0, 20.0, 10.0, 5.0, 2.0 };
        double[] moedas = { 1.0, 0.50, 0.25, 0.10, 0.05, 0.01 };
        double n = double.Parse(Console.ReadLine());
        Console.WriteLine("NOTAS:");
        foreach (double note in notas)
        {
            if (n >= 0 && n <= 1000000.00)
            {
                int division = (int)(n / note);
                n = n % note;
                Console.WriteLine($"{division} nota(s) de R$ {note.ToString("F2")}");
                n = Math.Round( n, 2 );
            }
        }
        Console.WriteLine("MOEDAS:");
        foreach (double i in moedas)
        {
            if (n >= 0 && n <= 1000000.00)
            {
                int division = (int)(n / i);
                n = n % i;
                Console.WriteLine($"{division} moeda(s) de R$ {i.ToString("F2")}");
                n = Math.Round(n, 2);
            }
        }   
    }
}