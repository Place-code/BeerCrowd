//15%wrong ???
using System;
using System.Collections.Generic;

public class HelloWorld
{
    public static void Main(string[] args)
    {
        int repeat = int.Parse(Console.ReadLine());
        
        double soma = 0;
        
        double cont =0;
        
        for(int i=0; i<repeat; i++){
            string[] x = Console.ReadLine().Split(' ');
            int[] nx = new int[x.Length-1];
            for(int g =0; g<x.Length-2;g++){
                nx[g]=int.Parse(x[g+1]);
                soma+=double.Parse(x[g+1]);
            }
            double media = soma/nx.Length;    
            foreach(int onu in nx){
                if(onu>media){
                    cont++;
                }
            }
            Console.WriteLine("{0:f3}%", Math.Round(cont/nx.Length*100, 3));
        }
    }
}