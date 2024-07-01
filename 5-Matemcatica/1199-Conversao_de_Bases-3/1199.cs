using System;

public class HelloWorld
{
    public static void Main(string[] args)
    {
        while (true){
            string num = Console.ReadLine();
            if (num=="-1"){
                break;
            
            }
            bool Hexa = false;
            try{
                if (num[1] == 'x'){
                    Hexa = true;
                }
                else{
                    Hexa=false;
                }
            }
            catch(Exception ex){
                Hexa = false;
                
            }

            if (Hexa){
                int value = Convert.ToInt32(num, 16);
                Console.WriteLine(value);
            }
            else{
                int num1=int.Parse(num);
                string value1 = num1.ToString("X");
                Console.WriteLine("0x{0}",value1);

            }
            
            }
            
        }
    }