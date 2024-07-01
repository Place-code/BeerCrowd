using System; 

class URI {

    static void Main(string[] args) { 
        string x = Console.ReadLine();
        int c =0;
        foreach(char i in x){
            if (i=='O'){
                c++;
            }
        }
        if (c != 1){
            Console.WriteLine("?");
        }
        else{
            for(int j =0; j<2; j++){
                if(x[j] == 'X' & x[j+1] == 'X'){
                    Console.WriteLine("Alice");
                    c=1;
                }
            }
            if (x=="XOX"){
                Console.WriteLine("*");
            }
        }

    }

}