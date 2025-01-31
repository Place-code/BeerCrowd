#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//
int*incraseLengthArray(int*array,size_t oldSize,size_t newSize){
	int*newArray=(int*)malloc(sizeof(int)*newSize);
	for(int i=0;i<(int)oldSize;++i)newArray[i]=array[i];
	return newArray;
}
//
typedef struct Vector{
	int index,*array;
	size_t length;
}Vector;
struct Vector*createVector(size_t lengthIt){
	Vector*newVector=(Vector*)malloc(sizeof(Vector));
	newVector->array=(int*)malloc(sizeof(int)*lengthIt);
	newVector->index=0;
	newVector->length=lengthIt;
	return newVector;
}
void appendElementVector(Vector*ref,int newValue){
	if(ref->index>(int)ref->length){
		ref->array=incraseLengthArray(ref->array,ref->index,(int)ref->length*2);
		ref->length*=2;
	}
	ref->array[ref->index]=newValue;
	++ref->index;
}

typedef struct AdjList{
	Vector**adj;
}AdjList;
struct AdjList*createAdjList(size_t lengthAdj,size_t lengthVectors){
	AdjList*newAdj=(AdjList*)malloc(sizeof(AdjList));
	newAdj->adj=(Vector**)malloc(sizeof(Vector*)*lengthAdj);
	for(int i=0;i<(int)lengthAdj;++i)newAdj->adj[i]=createVector(lengthVectors);
	return newAdj;
}
void appendElementAdjList(AdjList*ref,int v1,int v2){
	appendElementVector(ref->adj[v1],v2);
	appendElementVector(ref->adj[v2],v1);
}
//
void displayVector(Vector*ref){
	for(int i=0;i<ref->index;++i){
		printf("%i ",ref->array[i]);
	}
}
void displayAdjList(AdjList*ref,int init,int end){
	if(init>end-1)return;
	if(ref->adj[init]->index){
		displayVector(ref->adj[init]);
		printf("\n");
	}
	displayAdjList(ref,init+1,end);
}
//
int graph[3],*amountFriends,*explored;
AdjList*list;
void subtract(int node){
	for(int i=0;i<list->adj[node]->index;++i){
		int aux=list->adj[node]->array[i];
		--amountFriends[aux];
		if(amountFriends[aux]<graph[2]&&!explored[aux]){
			explored[aux]=1;
			subtract(aux);
		}
	}
}
//
int main(){
	while(scanf("%i %i %i",&graph[0],&graph[1],&graph[2])&&getchar()!=EOF){
		list=createAdjList((size_t)graph[0]+10,(size_t)graph[0]/2);
		amountFriends=(int*)calloc(graph[0]+10,sizeof(int));
		for(int i=0;i<graph[1];++i){
			int v1,v2;
			scanf("%i %i",&v1,&v2);
			if(v1<graph[0]+1&&v2<graph[0]+1)appendElementAdjList(list,v1-1,v2-1);
			++amountFriends[v1-1];
			++amountFriends[v2-1];
		}
		explored=(int*)calloc(graph[0]+10,sizeof(int));
		for(int i=0;i<graph[0];++i){
			if(amountFriends[i]<graph[2]&&!explored[i]){
				explored[i]=1;
				subtract(i);
			}
		}
		int amountTrues=0;
		free(list);
		for(int i=0;i<graph[0];++i)(!explored[i])?++amountTrues:amountTrues;
		if(!amountTrues){
			printf("0\n");
			continue;
		}
		int index=0;
		for(int i=0,cont=0;i<graph[0];++i){
			if(!explored[i]&&cont<amountTrues-1){
				printf("%i ",i+1);
				++cont;
			}
			(!explored[i])?index=i:index;
		}
		printf("%i\n",index+1);
	}
	return 0;
}
