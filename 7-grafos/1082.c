#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//
typedef struct Queue{
	int data;
	struct Queue*next;
}Queue;

struct Queue*createQueue(int value){
	Queue*newQueue=(Queue*)malloc(sizeof(Queue));
	newQueue->data=value;
	newQueue->next=NULL;
	return newQueue;
}

struct Queue*appendElementQueue(Queue*ref,int newValue){
	ref->next=createQueue(newValue);
	ref=ref->next;
}


typedef struct Vector{
	int*array;
	int index;
	size_t lenght;
}Vector;

struct Vector*createVector(size_t firstLenght){
	Vector*newVector=(Vector*)malloc(sizeof(Vector));
	newVector->array=calloc(firstLenght,sizeof(sizeof(newVector->array)));
	newVector->index=0;
	newVector->lenght=firstLenght;
	return newVector;
}

void appendElementVector(Vector*ref,int newValue){
	ref->array[ref->index]=newValue;
	++ref->index;
}

typedef struct AdjList{
	Vector**arrays;
}AdjList;

struct AdjList*createAdjList(int lenghtList,int lenghtVector){
	AdjList*newAdj=(AdjList*)malloc(sizeof(AdjList));
	newAdj->arrays=(Vector**)malloc(sizeof(Vector*)*lenghtList);
	for(int i=0;i<lenghtList;++i)newAdj->arrays[i]=createVector(lenghtVector);
	return newAdj;
}

void appendElementAdjList(AdjList*ref,int v1,int v2){
	appendElementVector(ref->arrays[v1],v2);
	appendElementVector(ref->arrays[v2],v1);
}

void displayQueue(Queue*ref){
	if(!ref->next){
		printf("%i\n",ref->data);
		return;
	}
	printf("%i ",ref->data);
	displayQueue(ref->next);
}

void displayVector(Vector*ref,int it){
	if(it>ref->index-1)return;
	printf("%i ",ref->array[it]);
}

void displayArrayList(AdjList*ref,int init,int lenght){
	if(init>lenght-1)return;
	if(ref->arrays[init]->index>0){
		printf("%i- ",init);
		displayVector(ref->arrays[init],0);
		printf("\n");
	}
	displayArrayList(ref,init+1,lenght);
}
//
int main(){
	int i,ops=0;
	for(scanf("%i",&i);i>0;--i){
		int temps[2];
		scanf("%i %i",&temps[0],&temps[1]);
		AdjList*adj=createAdjList(temps[0],27);
		for(int j=0;j<temps[1];++j){
			char vs1[3],vs2[3];
			int c,aux[2];
			scanf("%s %s",&vs1[0],&vs2[0]);
			aux[0]=(int)vs1[0]-97;aux[1]=(int)vs2[0]-97;
			while((c=getchar())!='\n'&&c!=EOF){}
			appendElementAdjList(adj,aux[0],aux[1]);
		}
		//displayArrayList(adj,0,temps[0]);
		printf("Case #%i:\n",ops+1);
		int*explored=calloc(temps[0],sizeof(int)),cont=0;
		for(int j=0;j<temps[0];++j){
			if(explored[j])continue;
			Queue*lets=createQueue(j),*auxLets=lets;
			explored[j]=1;
			int*conexion=calloc(temps[0],sizeof(int));
			conexion[j]=1;
			while(lets){
				int analysis=lets->data;
				//printf("%i ",analysis);
				for(int k=0;k<adj->arrays[analysis]->index;++k){
					int aux=adj->arrays[analysis]->array[k];
					if(explored[aux])continue;
					conexion[aux]=1;
					explored[aux]=1;
					auxLets=appendElementQueue(auxLets,aux);
				}
				lets=lets->next;
			}
			for(int k=0;k<temps[0];++k){
				if(conexion[k])printf("%c,",(char)k+97);
			}
			printf("\n");
			++cont;
		}
		printf("%i connected components\n\n",cont);
		++ops;
		free(adj);
	}
}
