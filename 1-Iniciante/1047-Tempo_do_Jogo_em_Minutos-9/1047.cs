using System;

public class HelloWorld
{
    public static void Main(string[] args)
    {
        string[] perde = Console.ReadLine().Split(' ');
        int[] per = {int.Parse(perde[0]),int.Parse(perde[1]),int.Parse(perde[2]),int.Parse(perde[3])};
        int hrs, minu;
        if(per[0]<=per[2]){
            hrs=per[2]-per[0];
            
            minu=per[3]-per[1];
            if(per[1]>per[3]){
                hrs-=1;
                minu=60-(per[1]-per[3]);
            }
            if(per[0] == per[1] & per[0] == per[2] & per[0]==per[3]){
                hrs=24;
                minu=0;
            }
        }
        else{
            hrs = (24-per[0])+per[2];
            minu= per[3]-per[1];
            if (per[1]>per[3]){
                hrs-=1;
                minu=60-(per[1]-per[3]);
            }
            
        }
        if (hrs==-1){
            hrs=23;
        }
        Console.WriteLine($"O JOGO DUROU {hrs} HORA(S) E {minu} MINUTO(S)");
        
    }
}