#include<iostream>
#include<cstring>
//
int isAWord(char*string){
	if((int)string[0]==46)return 0;
	int i;
	for(i=0;string[i]!='\n'&&string[i]!='\0';++i){
		if((int)string[i]==46&&(string[i+1]=='\n'|string[i+1]=='\0'))break;
		else if(((int)string[i]<65|(int)string[i]>90)&&((int)string[i]<97|(int)string[i]>122))return 0;
	}
	int length=0;
	for(int j=0;string[j]!='\n'&&string[j]!='\0'&&string[j]!='.';++j){
		++length;
	}
	return length;
}
//
int main(){
	std::string inp;
	while(std::getline(std::cin,inp)){
		if(!std::cin)break;
		char*split=std::strtok(&inp[0]," ");
		int average=0,tots=0;
		while(split!=NULL){
			int temp=isAWord(split);
			if(temp){
				average+=temp;
				++tots;
			}
			split=std::strtok(NULL," ");
		}
		(!average)?average=1:average;
		(!tots)?tots=1:tots;
		int result=int((double)average/(double)tots);
		//std::cout<<result<<" "<<average<<"\n";
		if(result<4)std::cout<<"250\n";
		else if(result<6)std::cout<<"500\n";
		else std::cout<<"1000\n";
	}
	return 0;
}
