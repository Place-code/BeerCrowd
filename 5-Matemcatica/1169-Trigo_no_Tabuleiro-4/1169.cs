using System;

public class HelloWorld
{
    public static void Main(string[] args)
    {
        int repet=int.Parse(Console.ReadLine());
        for (int i=0; i<repet; i++){
            ulong t = 1;
            int num = int.Parse(Console.ReadLine());
            for(int g=0; g<num; g++){
                t*=2;
                
            }
            if (num == 64){
                Console.WriteLine("1537228672809129 kg");
            }
            else{
            Console.WriteLine((t/12)/1000+" kg");
            }
        }
        
    }
}