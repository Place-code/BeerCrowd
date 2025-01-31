#include<iostream>
#include<vector>
#include<queue>
//
int**board,end,init;
std::queue<int>fila;

std::vector<int> actionHorse(int x,int y){
	std::vector<int>store;
	for(int i=0;i<2;++i){
		if(x+i+1<8&&y+2-i<8&&!board[y+2-i][x+i+1]){
			store.push_back(x+i+1+(y+2-i)*10);
			board[y+2-i][x+i+1]=1;
		}
		if(x+i+1<8&&y-2+i>-1&&!board[y-2+i][x+i+1]){
			store.push_back(x+i+1+(y-2+i)*10);
			board[y-2+i][x+i+1]=1;
		}
	}
	for(int i=0;i<2;++i){
		if(x-i-1>-1&&y+2-i<8&&!board[y+2-i][x-i-1]){
			store.push_back(x-i-1+(y+2-i)*10);
			board[y+2-i][x-i-1]=1;
		}
		if(x-i-1>-1&&y-2+i>-1&&!board[y-2+i][x-i-1]){
			store.push_back(x-i-1+(y-2+i)*10);
			board[y-2+i][x-i-1]=1;
		}
	}
	return store;
}

void bfs(int cont){
	std::queue<int>aux;
	for(;!fila.empty();){
		int x=fila.front()%10,y=(fila.front()-fila.front()%10)/10;
		//std::cout<<fila.front()<<"|";
		if(fila.front()==end){
			std::cout<<"To get from "<<char((init%10)+97)<<(init-init%10)/10+1<<" to "<<char((end%10)+97)<<(end-end%10)/10+1<<" takes "<<cont<<" knight moves.\n";
			fila=std::queue<int>();
			return;
		}
		for(int analyse:actionHorse(x,y)){
			int auxX=analyse%10,auxY=(analyse-analyse%10)/10;
			//std::cout<<char(auxX+97)<<auxY<<" "<<" ";
			aux.push(analyse);
		}
		fila.pop();
	}
	fila=aux;
	bfs(cont+1);
}
//
int main(){
	std::string inp;
	for(;std::getline(std::cin,inp)&&inp.length();){
		init=(int)inp[0]-97+(inp[1]-'0'-1)*10;
		end=((int)inp[3]-97)+(inp[4]-'0'-1)*10;
		board=(int**)malloc(8*sizeof(int*));
		for(int i=0;i<8;++i)board[i]=(int*)calloc(8,sizeof(int));
		board[(init-init%10)/10][init%10]=1;
		fila.push(init);
		bfs(0);
	}
}
