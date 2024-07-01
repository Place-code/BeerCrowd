using System;

public class HelloWorld
{
    public static void Main(string[] args)
    {
        int x = int.Parse(Console.ReadLine());
        int segs=0;
        int min=0;
        int hrs=0;
        for(int i=1; i<x+1;i++){
            if(i%60==0){
                min++;
                segs=0;
            }
            else{
                segs++;
            }
            if(min%60==0 & min !=0){
                hrs++;
                min=0;
            }
        }
        Console.WriteLine($"{hrs}:{min}:{segs}");
    }
}