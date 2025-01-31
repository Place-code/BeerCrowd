#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//
int isAWord(char*string){
	if(string[0]=='.')return 0;
	for(int i=0;string[i]!='\n'&&string[i]!='\0';++i){
		if(string[i]=='.'&&(string[i+1]=='\n'|string[i+1]=='\0'))break;
		else if(((int)string[i]<65|(int)string[i]>90)&&((int)string[i]<97|(int)string[i]>122))return 0;
	}
	int length=0;
	for(length=0;string[length]!='\n'&&string[length]!='\0'&&string[length]!='.';++length){}
	return length;
}
//
int main(){
	char inp[1024];
	while(fgets(inp,1024,stdin)!=NULL){
		int totString=0,totAverage=0;
		char*split,*rest=inp;
		while((split=strtok_r(rest," ",&rest))){
			int temp=isAWord(split);
			if(temp){
				totAverage+=temp;
				++totString;
			}
		}
		if(!totAverage|!totString){
			printf("250\n");
			continue;
		}
		int result=(double)totAverage/(double)totString;
		//printf("%i %i\n",result,totAverage);
		if(result<4)printf("250\n");
		else if(result<6)printf("500\n");
		else printf("1000\n");
	}
	return 0;
}
