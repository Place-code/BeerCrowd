#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//
int**pieces,**board;
void translate(char string[],int index){
	pieces[index][0]=(string[0]=='W')?0:(string[0]=='P')?1:(string[0]=='T')?2:(string[0]=='B')?3:4;
	pieces[index][1]=((int)string[1]-97)*10+string[2]-'0'-1;
	board[pieces[index][1]%10][(pieces[index][1])/10]=2;
}
void intersectionHorizontal(int xy){
	int x=xy/10,y=xy%10;
	for(int i=x,j=y-1;j>-1;--j){
		if(board[j][i]>1){
			++board[j][i];
			break;
		}
		board[j][i]=1;
	}
	for(int i=x,j=y+1;j<8;++j){
		if(board[j][i]>1){
			++board[j][i];
			break;
		}
		board[j][i]=1;
	}
	for(int i=x-1,j=y;i>-1;--i){
		if(board[j][i]>1){
			++board[j][i];
			break;
		}
		board[j][i]=1;
	}
	for(int i=x+1,j=y;i<8;++i){
		if(board[j][i]>1){
			++board[j][i];
			break;
		}
		board[j][i]=1;
	}
}
void intersectionVertical(int xy){
	int x=xy/10,y=xy%10;
	for(int i=x-1,j=y-1;i>-1&&j>-1;--i,--j){
		if(board[j][i]>1){
			++board[j][i];
			break;
		}
		board[j][i]=1;
	}
	for(int i=x+1,j=y-1;i<8&&j>-1;++i,--j){
		if(board[j][i]>1){
			++board[j][i];
			break;
		}
		board[j][i]=1;
	}
	for(int i=x+1,j=y+1;i<8&&j<8;++i,++j){
		if(board[j][i]>1){
			++board[j][i];
			break;
		}
		board[j][i]=1;
	}
	for(int i=x-1,j=y+1;i>-1&&j<8;--i,++j){
		if(board[j][i]>1){
			++board[j][i];
			break;
		}
		board[j][i]=1;
	}
}
void intersectionKing(int xy){
	for(int i=0;i<3;++i){
		int x=xy/10-1,y=xy%10-1+i;
		if(y<0|y>7)continue;
		for(int j=0;j<3;++j){
			if(x+j<0|x+j>7|(x+j)*10+y==xy)continue;
			board[y][x+j]=1;
		}
	}
}
void intersectionPawn(int xy){
	if(xy%10-1<0)return;
	if(xy/10-1>-1)board[xy%10-1][xy/10-1]=1;
	if(xy/10+1<8)board[xy%10-1][xy/10+1]=1;
}
void InIntersection(int amountPieces){
	for(int i=0;i<amountPieces;++i){
		if(pieces[i][0]==0)intersectionKing(pieces[i][1]);
		else if(pieces[i][0]==1)intersectionPawn(pieces[i][1]);
		else if(pieces[i][0]==2|pieces[i][0]==4)intersectionHorizontal(pieces[i][1]);
		if(pieces[i][0]==3|pieces[i][0]==4)intersectionVertical(pieces[i][1]);
	}
	for(int i=0;i<amountPieces;++i){
		board[pieces[i][1]%10][pieces[i][1]/10]-=2;
	}
}
//
int notInCheck(int xy){
	for(int i=0;i<3;++i){
		int x=xy/10-1,y=xy%10-1+i;
		if(y<0|y>7)continue;
		for(int j=0;j<3;++j){
			if(x+j<0|x+j>7)continue;
			if(!board[y][x+j])return 1;
		}
	}
	return 0;
}
//
int main(){
	int rep;
	while(scanf("%i",&rep)&&getchar()!=EOF){
		board=(int**)malloc(sizeof(int*)*8);
		pieces=(int**)malloc(sizeof(int*)*rep);
		for(int i=0;i<8;++i)board[i]=(int*)calloc(8,sizeof(int));
		for(int i=0;i<rep;++i){
			char temp[6];
			scanf("%s",&temp);
			pieces[i]=(int*)malloc(sizeof(int)*2);
			translate(temp,i);
		}
		InIntersection(rep);
		char King[5];
		scanf("%s",&King);
		if(notInCheck(((int)King[1]-97)*10+King[2]-'0'-1))printf("NAO\n");
		else printf("SIM\n");
	}
	return 0;
}
