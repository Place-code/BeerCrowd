using System;

public class HelloWorld
{
    public static void Main(string[] args)
    {
        for(int i =0; i<4008; i++){
            string[] ent = Console.ReadLine().Split(' ');
             double[] entradas = {double.Parse(ent[0]),double.Parse(ent[1]),double.Parse(ent[2])};
             Array.Sort(entradas);
             double p, r, v, s;
             
             p=(entradas[0]+entradas[1]+entradas[2])/2;
             
             r=Math.Pow(((Math.Pow((p*(p-entradas[0])*(p-entradas[1])*(p-entradas[2])), 0.5))/p),2)*3.1415926535897;
             
             v=(Math.Pow((p*(p-entradas[0])*(p-entradas[1])*(p-entradas[2])), 0.5))-r;
             
             s=Math.Pow(((entradas[0]*entradas[1]*entradas[2])/(v+r)/4), 2)*3.1415926535897-(v+r);
             
             Console.WriteLine($"{Math.Round(s, 4):f4} {Math.Round(v,4):f4} {Math.Round(r,4):f4}");
             
        }
    }
}