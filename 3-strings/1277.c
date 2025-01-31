#include<stdio.h>
//
int seventyFive(char string[]){
	int lengthString=0,presence=0;
	for(int i=0;string[i]!='\0';++i){
		if(string[i]=='M')continue;
		(string[i]=='P')?++presence:presence;
		++lengthString;
	}
	return (double)presence/(double)lengthString>=0.75;
}
//
int main(){
	int r;
	for(scanf("%i",&r);r>0;--r){
		int amountStudents,amountFalse=0;
		scanf("%i",&amountStudents);
		int frequency[amountStudents];
		char pupil[amountStudents][60];
		for(int i=0;i<amountStudents;++i)scanf("%s",&pupil[i]);
		for(int i=0;i<amountStudents;++i){
			char temp[1024];
			scanf("%s",&temp);
			frequency[i]=seventyFive(temp);
			(!frequency[i])?++amountFalse:amountFalse;
		}
		if(!amountFalse){
			printf("\n");
			continue;
		}
		int index=0;
		for(int i=0,tot=0;i<amountStudents;++i){
			if(!frequency[i]&&tot<amountFalse-1){
				printf("%s ",pupil[i]);
				++tot;
			}
			(!frequency[i])?index=i:index;
		}
		printf("%s\n",pupil[index]);
	}
	return 0;
}
