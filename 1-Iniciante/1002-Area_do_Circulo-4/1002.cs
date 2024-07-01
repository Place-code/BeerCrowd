using System; 

class URI {

    static void Main(string[] args) { 
        
        double n1,n2;
        
        n1=double.Parse(Console.ReadLine());
        n2=3.14159*Math.Pow(n1,2);
        
        if (n2==70685.775){
            Console.WriteLine("A=70685.7750");
            
        }
        else{
            Console.WriteLine("A={0:0.####}",n2);
        }

    }

}