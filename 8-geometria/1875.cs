using System;

class Thousand_Eight_Hundred_Seventy_five{
	static int spore(int issuer,int receiver){
		if(issuer==(int)'R'&&receiver==(int)'G')
			return 2;
		else if(issuer==(int)'R')
			return 1;

		if(issuer==(int)'G'&&receiver==(int)'B')
			return 2;
		else if(issuer==(int)'G')
			return 1;

			if(issuer==(int)'B'&&receiver==(int)'R')
			return 2;
		else
			return 1;
	}
	static void Main(){
		int rep=Convert.ToInt32(Console.ReadLine());
		for(int i=0;i<rep;++i){
			int goals=Convert.ToInt32(Console.ReadLine());
			int []array={0,0,0};
			for(int j=0;j<goals;++j){
				String big_string=Console.ReadLine();
				String[]array_str=big_string.Split(new string[]{" "},2,StringSplitOptions.RemoveEmptyEntries);

				int str_1_chr=(int)array_str[0][0],str_2_chr=(int)array_str[1][0];
				if(str_1_chr==(int)'R')
					array[0]+=spore(str_1_chr,str_2_chr);
				if(str_1_chr==(int)'G')
					array[1]+=spore(str_1_chr,str_2_chr);
				if(str_1_chr==(int)'B')
					array[2]+=spore(str_1_chr,str_2_chr);
			}
			if(array[0]>array[1]&&array[0]>array[2])
				Console.WriteLine("red");
			else if(array[1]>array[0]&&array[1]>array[2])
				Console.WriteLine("green");
			else if(array[2]>array[0]&&array[2]>array[1])
				Console.WriteLine("blue");
			else if(array[0]==array[1]&&array[0]==array[2])
				Console.WriteLine("trempate");
			else
				Console.WriteLine("empate");
		}
	}
}
