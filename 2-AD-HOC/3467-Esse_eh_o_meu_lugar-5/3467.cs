using System; 

class URI {

    static void Main(string[] args) { 

        while (true){
            try{
                string val = Console.ReadLine();
                if (val[2] == 'L'){
                    Console.WriteLine("Esse eh o meu lugar");
                }
                else{
                    Console.WriteLine("Oi, Leonard");
                }
            }
            
            catch{
                break;
                
            }
        }

    }

}