#include<iostream>
//
// °~°
//
int**pieces,King,**board;
void translate(std::string&gross,int index){
	pieces[index][0]=(gross[0]=='P')?1:(gross[0]=='B')?2:(gross[0]=='T')?3:(gross[0]=='W')?0:4;
	pieces[index][1]=int(gross[1])-97+(gross[2]-'0'-1)*10;
	board[(pieces[index][1]-pieces[index][1]%10)/10][pieces[index][1]%10]=2;
}

void intersectionHorizont(int yx){
	int x=yx%10,y=(yx-x)/10;
	for(int auxX=x,auxY=y+1;auxY<8;++auxY){
		if(board[auxY][auxX]>1){
			++board[auxY][auxX];
			break;
		}
		board[auxY][auxX]=1;
	}
	for(int auxX=x,auxY=y-1;auxY>-1;--auxY){
		if(board[auxY][auxX]>1){
			++board[auxY][auxX];
			break;
		}
		board[auxY][auxX]=1;
	}
	for(int auxX=x+1,auxY=y;auxX<8;++auxX){
		if(board[auxY][auxX]>1){
			++board[auxY][auxX];
			break;
		}
		board[auxY][auxX]=1;
	}
	for(int auxX=x-1,auxY=y;auxX>-1;--auxX){
		if(board[auxY][auxX]>1){
			++board[auxY][auxX];
			break;
		}
		board[auxY][auxX]=1;
	}
}
void intersectionVertical(int yx){
	int x=yx%10,y=(yx-x)/10;
	for(int auxX=x-1,auxY=y-1;auxX>-1&&auxY>-1;--auxX,--auxY){
		if(board[auxY][auxX]>1){
			++board[auxY][auxX];
			break;
		}
		board[auxY][auxX]=1;
	}
	for(int auxX=x+1,auxY=y-1;auxX<8&&auxY>-1;++auxX,--auxY){
		if(board[auxY][auxX]>1){
			++board[auxY][auxX];
			break;
		}
		board[auxY][auxX]=1;
	}
	for(int auxX=x+1,auxY=y+1;auxX<8&&auxY<8;++auxX,++auxY){
		if(board[auxY][auxX]>1){
			++board[auxY][auxX];
			break;
		}
		board[auxY][auxX]=1;
	}
	for(int auxX=x-1,auxY=y+1;auxX>-1&&auxY<8;--auxX,++auxY){
		if(board[auxY][auxX]>1){
			++board[auxY][auxX];
			break;
		}
		board[auxY][auxX]=1;
	}
}
void intersectionPawn(int yx){
	int x=yx%10,y=(yx-x)/10;
	if(x-1>-1&&y-1>-1)board[y-1][x-1]=1;
	if(x+1<8&&y-1>-1)board[y-1][x+1]=1;
}
void intersectionKing(int yx){
	int x=yx%10,y=(yx-x)/10;
	if(x+1<8)board[y][x+1]=1;
	if(x-1>-1)board[y][x-1]=1;
	for(int auxX=x-1;auxX<8&&auxX<x+2&&y+1<8;++auxX)board[y+1][auxX]=1;
	for(int auxX=x-1;auxX<8&&auxX<x+2&&y-1>-1;++auxX)board[y-1][auxX]=1;
}


int notCheckmate(int yx,int size){
	for(int i=0;i<size;++i)board[(pieces[i][1]-pieces[i][1]%10)/10][pieces[i][1]%10]-=2;
	int x=yx%10,y=(yx-x)/10;
	if((!board[y][x-1]&&x-1>-1)|(!board[y][x+1]&&x+1<8)|!board[y][x])return 1;
	for(int auxX=(x-1>-1)?x-1:x;auxX<8&&auxX<x+2&&y+1<8;++auxX)if(!board[y+1][auxX])return 1;
	for(int auxX=(x-1>-1)?x-1:x;auxX<8&&auxX<x+2&&y-1>-1;++auxX)if(!board[y-1][auxX])return 1;
	return 0;
}
void inCheck(int amountPieces){
	for(int i=0;i<amountPieces;++i){
		//
		//std::cout<<pieces[i][0]<<"|";
		if(pieces[i][0]==0)intersectionKing(pieces[i][1]);
		if(pieces[i][0]==1)intersectionPawn(pieces[i][1]);
		if(pieces[i][0]==2|pieces[i][0]==4)intersectionVertical(pieces[i][1]);
		if(pieces[i][0]==3|pieces[i][0]==4)intersectionHorizont(pieces[i][1]);
		//
	}
}
//
int main(){
	int rep;
	while(std::cin>>rep){
		board=(int**)malloc(sizeof(int*)*8);
		for(int i=0;i<8;++i)board[i]=(int*)calloc(8,sizeof(int));
		pieces=(int**)malloc(sizeof(int*)*rep);
		for(int i=0;i<rep;++i){
			std::string temp;
			std::cin>>temp;
			pieces[i]=(int*)malloc(sizeof(int)*2);
			translate(temp,i);
		}
		inCheck(rep);
		/*
		std::cout<<"\n";
		for(int i=7;i>-1;--i){
			for(int j=0;j<8;++j)std::cout<<board[i][j]<<" ";
			std::cout<<"\n";
		}*/	
		std::string init;
		std::cin>>init;
		King=int(init[1])-97+(init[2]-'0'-1)*10;
		if(!notCheckmate(King,rep))std::cout<<"SIM\n";
		else std::cout<<"NAO\n";
		free(board);
	}
	return 0;
}
