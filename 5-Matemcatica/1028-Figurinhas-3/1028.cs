using System;

public class HelloWorld
{
    public static void Main(string[] args)
    {
        int repeat = int.Parse(Console.ReadLine());
        for(int i = 0; i<repeat; i++){
            string[] nuns=Console.ReadLine().Split(' ');
            int maior=Math.Max(int.Parse(nuns[0]), int.Parse(nuns[1]));
            int menor=Math.Min(int.Parse(nuns[0]), int.Parse(nuns[1]));
            
            int inter;
            while(menor != 0){
                inter = menor;
                menor = maior%menor;
                maior = inter;
    
            }
            Console.WriteLine(maior);
        }
    }
}