#include<stdlib.h>
#include<stdio.h>
//
int x,y,**matrix;
int check(){
	for(int i=0;i<x;++i){
		int temp=1;
		for(int j=0;j<y;++j)(temp)?temp=matrix[j][i]:temp;
		if(temp)return 1;
	}
	return 0;
};
//
int main(){
	while(scanf("%i %i",&x,&y)&&x&&y){
		matrix=(int**)malloc(sizeof(int*)*y);
		for(int i=0;i<y;++i){
			matrix[i]=(int*)malloc(sizeof(int)*x);
			for(int j=0;j<x;++j){
				int temp;
				scanf("%i",&temp);
				matrix[i][j]=temp;
			}
		}
		if(check())printf("yes\n");
		else printf("no\n");
	}
	return 0;
}
