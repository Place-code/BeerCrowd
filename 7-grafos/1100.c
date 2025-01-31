#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//
typedef struct Queue{
	int value;
	struct Queue*next;
}Queue;

struct Queue*createQueue(int value){
	Queue*newQueue=(Queue*)malloc(sizeof(Queue));
	newQueue->value=value;
	newQueue->next=NULL;
	return newQueue;
}

struct Queue*appendElement(Queue*ref,int element){
	ref->next=createQueue(element);
	ref=ref->next;
	return ref;
}

void swap(Queue*ref0,Queue*ref1){
	Queue*temp=ref0;
	while(ref1){
		temp->next=createQueue(ref1->value);
		temp=temp->next;
		ref1=ref1->next;
	}
}

int end,init,**board;
int*actionKnight(int x,int y){
	int*aux=malloc(sizeof(int)*8),index=0;
	memset(aux,-1,sizeof(int)*8);
	for(int i=0;i<2;++i){
		if(x+i+1<8&&y+2-i<8&&!board[y+2-i][x+i+1]){
			aux[index]=(x+i+1)*10+y+2-i;
			board[y+2-i][x+i+1]=1;
			++index;
		}
		if(x+i+1<8&&y-2+i>-1&&!board[y-2+i][x+i+1]){
			aux[index]=(x+i+1)*10+y-2+i;
			board[y-2+i][x+i+1]=1;
			++index;
		}
	}
	for(int i=0;i<2;++i){
		if(x-i-1>-1&&y+2-i<8&&!board[y+2-i][x-i-1]){
			aux[index]=(x-i-1)*10+y+2-i;
			board[y+2-i][x-i-1]=1;
			++index;
		}
		if(x-i-1>-1&&y-2+i>-1&&!board[y-2+i][x-i-1]){
			aux[index]=(x-i-1)*10+y-2+i;
			board[y-2+i][x-i-1]=1;
			++index;
		}
	}
	return aux;
}
Queue*fila;
void bfs(int cont){
	Queue*aux=createQueue(-1),*auxAux=aux;
	while(fila){
		int*prin=actionKnight((fila->value-fila->value%10)/10,fila->value%10);
		if(fila->value==end){
			printf("To get from %c%i to %c%i takes %i knight moves.\n",(char)((init-init%10)/10+97),init%10+1,(char)((end-end%10)/10+97),end%10+1,cont);
			return;
		}
		for(int i=0;i<8;++i){
			if(prin[i]==-1)break;
			//printf("%c%i\n",(char)((prin[i]-prin[i]%10)/10+97),prin[i]%10);
			auxAux=appendElement(auxAux,prin[i]);
		}
		fila=fila->next;
	}
	aux=aux->next;
	if(!aux)return;
	free(fila);
	fila=createQueue(aux->value);
	aux=aux->next;
	swap(fila,aux);
	free(aux);
	bfs(cont+1);
}
//
int main(){
	char*inp=malloc(sizeof(char)*10);
	while(strlen(fgets(inp,10,stdin))>3){
		init=((int)inp[0]-97)*10+inp[1]-'0'-1;
		end=((int)inp[3]-97)*10+inp[4]-'0'-1;
		board=(int**)malloc(8*sizeof(int*));
		for(int i=0;i<8;++i)board[i]=(int*)calloc(8,sizeof(int));
		board[init%10][(init-init%10)/10]=1;
		fila=createQueue(init);
		bfs(0);
		free(board);
		free(fila);
	}
	return 0;
}
