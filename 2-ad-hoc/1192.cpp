#include<iostream>
//
int main(){
	int i=0;	
	for(std::cin>>i;i>0;--i){
		std::string inp;
		std::cin>>inp;
		if(inp[0]==inp[2])std::cout<<(inp[0]-'0')*(inp[2]-'0');
		else if((int)inp[1]<91)std::cout<<(inp[2]-'0')-(inp[0]-'0');
		else std::cout<<(inp[2]-'0')+(inp[0]-'0');
		std::cout<<"\n";
	}
	return 0;
}
