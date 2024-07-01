using System; 

class URI {

    static void Main(string[] args) { 
        double n;
        
        n=double.Parse(Console.ReadLine());
        double n1=Math.Pow(n, 3);
        Console.WriteLine("VOLUME = {0:0.###}",(4/3.0)*3.14159*n1);
    }

}