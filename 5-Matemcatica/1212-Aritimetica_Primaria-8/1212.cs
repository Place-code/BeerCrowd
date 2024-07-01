using System;

public class HelloWorld
{
    public static void Main(string[] args)
    {
        while(true){
            int e=0;
            int count1=0;
            
            string l1 = "";
            string l2 = "";
            
            string[] input = Console.ReadLine().Split(' ');
    
            if (input[0] == "0" && input[1]=="0"){
                break;
            }
            foreach(char id in input[0]){
                l1=l1+id;
            }
            foreach(char ik in input[1]){
                l2=l2+ik;
            }
            
            for(int i=0; i<9-input[0].Length; i++){
                l1=l1.Insert(0, "0");
            }
            for(int i=0; i<9-input[1].Length; i++){
                l2=l2.Insert(0, "0");
            }
            for (int j=8; j>-1; j--){
                
                int n1=int.Parse(Convert.ToString(l1[j]));
                int n2=int.Parse(Convert.ToString(l2[j]));
                if (n1+n2+e >9){
                    e=1;
                    count1+=1;
                
                }
                else{
                    e=0;
                }
            }
            if (count1==0){
                Console.WriteLine("No carry operation.");
            }
            
            else if (count1==1){
                Console.WriteLine("{0} carry operation.", count1);
            }
            else{
                Console.WriteLine("{0} carry operations.", count1);
            }
            
        }
    }
}