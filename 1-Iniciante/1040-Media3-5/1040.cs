using System; 

class URI {

    static void Main(string[] args) { 
    
        string[] valores = Console.ReadLine().Split(' ');
        
        double valor1, valor2, valor3, valor4;

        valor1=double.Parse(valores[0])*2;
        valor2=double.Parse(valores[1])*3;
        valor3=double.Parse(valores[2])*4;
        valor4=double.Parse(valores[3]);
        Console.WriteLine($"Media: {Math.Round((valor1+valor2+valor3+valor4)/10, 1):f1}");
        if((valor1+valor2+valor3+valor4)/10>=7){
            Console.WriteLine("Aluno aprovado.");
        }
        else if((valor1+valor2+valor3+valor4)/10<5){
            Console.WriteLine("Aluno reprovado.");
        }
        else{
            Console.WriteLine("Aluno em exame.");
            
            double nova_nota = double.Parse(Console.ReadLine());
            Console.WriteLine($"Nota do exame: {nova_nota:f1}");
            
            if ((((valor1+valor2+valor3+valor4)/10)+nova_nota)/2>=5){
                Console.WriteLine("Aluno aprovado.");
            }
            else{
                Console.WriteLine("Aluno reprovado.");
            }
            
            
            Console.WriteLine($"Media final: {Math.Round((((valor1+valor2+valor3+valor4)/10)+nova_nota)/2, 1):f1}");
        }
        
        
    
    }

}