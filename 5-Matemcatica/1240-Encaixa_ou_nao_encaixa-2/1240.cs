using System; 

class URI {

    static void Main(string[] args) { 
        int repeticoes=int.Parse(Console.ReadLine());
        
        for (int i=0; i<repeticoes; i++){
            string[] nuns=Console.ReadLine().Split(' ');
            string nun1=nuns[0];
            string nun2=nuns[1];
            
            if (nun1.Length >=nun2.Length){
                if (nun1.Substring(nun1.Length-nun2.Length) == nun2){
                    Console.WriteLine("encaixa");
                }
                else{
                    Console.WriteLine("nao encaixa");
                }
            }
            else{
                Console.WriteLine("nao encaixa");
            }
        }
    }

}