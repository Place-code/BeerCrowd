using System;

public class HelloWorld
{
    public static void Main(string[] args)
    {
        double x = double.Parse(Console.ReadLine());
        
        double[] notas = {100.0, 50.0, 20.0, 10.0, 5.0, 2.0, 1.0};
        
        Console.WriteLine((int)x);
        
        foreach(double i in notas){
            
            if(x>=i){
                string z=Convert.ToString(i).Replace('.', ',');
                
                Console.WriteLine($"{Math.Floor(x/i):f0} nota(s) de R$ {z},00");
                x-=i*(int)(x/i);
            }
            else{
                string z=Convert.ToString(i).Replace('.', ',');
                Console.WriteLine($"0 nota(s) de R$ {z},00");
            }
            
        }
    }
}