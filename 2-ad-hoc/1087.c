#include<stdio.h>
//
int end;
int moveQueen(int x,int y){
	for(int i=0;i<2;++i){
		int subX=i==0?1:0,subY=i==0?0:1;
		for(int j=0;j<8;++j)if((x*subY+j*subX)*10+y*subX+j*subY==end)return 1;
	}
	int auxX=x-y,auxY=0;
	for(;auxX<8&&auxY<8;++auxX,++auxY)if(auxX*10+auxY==end)return 1;
	auxX=x-(7-y);auxY=7;
	for(;auxX<8&&auxY>-1;++auxX,--auxY)if(auxX*10+auxY==end)return 1;
	return 0;
}

int main(){
	int x1,x2,y1,y2;
	while(scanf("%i %i %i %i",&x1,&y1,&x2,&y2)&&x1&&x2&&y1&&y2){
		if(x2==x1&&y1==y2){
			printf("0\n");
			continue;
		}
		end=(x2-1)*10+y2-1;
		if(moveQueen(x1-1,y1-1))printf("1\n");
		else printf("2\n");
	}
	return 0;
}
