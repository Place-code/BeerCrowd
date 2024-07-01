using System;

public class HelloWorld
{
    public static void Main(string[] args)
    {
        int tamanho = int.Parse(Console.ReadLine());
        
        int[] l = new int [tamanho];
        for(int g=0; g<tamanho;g++){
            l[g]=int.Parse(Console.ReadLine());
        }
        int bgl = l[0];
        int p =0;
        foreach(int i in l){
            if(i==bgl){
                p++;
                if(bgl==1){
                    bgl=2;
                }
                else{
                    bgl=1;
                }
                
            }
        }
        Console.WriteLine(p);
    }   
}