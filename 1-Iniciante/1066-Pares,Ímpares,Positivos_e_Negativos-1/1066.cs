using System;

public class HelloWorld
{
    public static void Main(string[] args)
    {

        
        double par=0;
        double pos=0;
        double neg=0;
        
        for(int i=0;i<5;i++){
            double x =double.Parse(Console.ReadLine());
                if (x%2==0){
                    par++;
                }
                if (x<0){
                    neg++;
                }
                if (x>0){
                    pos++;
                }
            }
        Console.WriteLine($"{par} valor(es) par(es)");
        Console.WriteLine($"{5-par} valor(es) impar(es)");
        Console.WriteLine($"{pos} valor(es) positivo(s)");
        Console.WriteLine($"{neg} valor(es) negativo(s)");
        
    }
}