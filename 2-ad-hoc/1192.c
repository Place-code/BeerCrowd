#include<stdio.h>
#include<stdlib.h>
//
int main(){
	int i;
	for(scanf("%i",&i);i>0;--i){
		char inp[5];
		scanf("%s",&inp);
		if(inp[0]==inp[2])printf("%i\n",(inp[0]-'0')*(inp[2]-'0'));
		else if((int)inp[1]<91)printf("%i\n",(inp[2]-'0')-(inp[0]-'0'));
		else printf("%i\n",(inp[2]-'0')+(inp[0]-'0'));
	}
	return 0;
}
