#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
//
#define INIT_ARRAY(arr,size,value)\
   	for(int i=0;i<size;++i)arr[i]=value;
//
typedef struct Vector{
	int*array,index;
	size_t length;
}Vector;

struct Vector*createVector(size_t length){
	Vector*newVector=(Vector*)malloc(sizeof(Vector));
	newVector->array=calloc(length,sizeof(int));
	newVector->index=0;
	newVector->length=length;
	return newVector;
}

int*incraseSizeArray(int*array,size_t oldSize,size_t newSize){
	int*newArray=(int*)calloc(newSize,sizeof(int));
	for(int i=0;i<oldSize;++i)newArray[i]=array[i];
	return newArray;
}

void swapArray(int*array,int index1,int index2){
	array[index1]+=array[index2];
	array[index2]=array[index1]-array[index2];
	array[index1]-=array[index2];
}

void appendElementVector(Vector*ref,int newValue){
	if(ref->index>(int)ref->length-1){
		ref->array=incraseSizeArray(ref->array,ref->length,ref->length*2);
		ref->length*=2;
	}
	ref->array[ref->index]=newValue;
	++ref->index;
}

typedef struct AdjList{
	Vector**adj;
	size_t length;
}AdjList;

struct AdjList*createAdjList(size_t lengthAdjList,size_t lengthVector){
	AdjList*newAdjList=(AdjList*)malloc(sizeof(AdjList));
	newAdjList->adj=(Vector**)malloc(sizeof(Vector*)*lengthAdjList);
	newAdjList->length=lengthAdjList;
	for(int i=0;i<lengthAdjList;++i)newAdjList->adj[i]=createVector(lengthVector);
	return newAdjList;
}

void appendElementsAdjList(AdjList*ref,int v1,int v2){
	appendElementVector(ref->adj[v1],v2);
	appendElementVector(ref->adj[v2],v1);
}
//
int*heapWeight,*heapVertic,Index,length;


void shiftUp(int index){
	if(!index||heapWeight[(index-1)/2]>heapWeight[index])return;
	swapArray(heapWeight,(index-1)/2,index);
	swapArray(heapVertic,(index-1)/2,index);
	shiftUp((index-1)/2);
}

void shiftDown(int index){
	int temp=index;
	if(heapWeight[index*2+1]>heapWeight[temp]&&index*2+1<Index)temp=index*2+1;
	if(heapWeight[index*2+2]>heapWeight[temp]&&index*2+2<Index)temp=index*2+2;
	if(temp!=index){
		swapArray(heapWeight,index,temp);
		swapArray(heapVertic,index,temp);
		shiftDown(temp);
	}
}

void insertHeap(int newVertic,int newWeight){
	if(Index>length-1){
		heapWeight=incraseSizeArray(heapWeight,length,length*2);
		heapVertic=incraseSizeArray(heapVertic,length,length*2);
		length*=2;
	}
	heapWeight[Index]=newWeight;
	heapVertic[Index]=newVertic;
	shiftUp(Index);
	++Index;
}

int*extractMin(){
	int*result=malloc(sizeof(int)*2);
	result[0]=heapVertic[0];
	result[1]=heapWeight[0];
	--Index;
	heapVertic[0]=heapVertic[Index];
	heapWeight[0]=heapWeight[Index];
	shiftDown(0);
	return result;
}
//
void displayVector(Vector*ref){
	for(int i=0;i<ref->index;++i){
		printf("%i ",ref->array[i]);
	}
	printf("\n");
}
void displayAdjList(AdjList*ref,int index){
	if(index>(int)ref->length-1)return;
	if(ref->adj[index]->index){
		printf("%i ",index);
		displayVector(ref->adj[index]);
	}
	displayAdjList(ref,index+1);
}
//
AdjList*lenin;
int*germans;
int Dijkstra(int init,int end,int bullets,int amountVertices){
	int*amountBullets=(int*)malloc(sizeof(int)*amountVertices);
	INIT_ARRAY(amountBullets,amountVertices,-1);
	amountBullets[init]=bullets-germans[init];
	heapWeight=malloc(amountVertices*sizeof(int));
	heapVertic=malloc(amountVertices*sizeof(int));
	Index=0;
	length=amountVertices;
	insertHeap(init,amountBullets[init]);
	while(Index){
		int*extract=extractMin();
		//printf("|%i %i|",extract[0],extract[1]);
		if(extract[1]<amountBullets[end]+1)break;
		for(int i=0;i<lenin->adj[extract[0]]->index;++i){
			int aux=lenin->adj[extract[0]]->array[i];
			if(amountBullets[aux]<extract[1]-germans[aux]){
				amountBullets[aux]=extract[1]-germans[aux];
				if(aux!=end)insertHeap(aux,amountBullets[aux]);
			}
		}
	}
    free(heapVertic);
    free(heapWeight);
	//printf("%i-\n",amountBullets[end]);
	return amountBullets[end];
}
//
int main(){
	int inps[3],index=0;
	float prob,tsts[100];
	while(scanf("%i %i %i %f",&inps[0],&inps[1],&inps[2],&prob)&&getchar()!=EOF){
		lenin=createAdjList(inps[0],inps[0]/2);
		for(int i=0;i<inps[1];++i){
			int v1,v2,c;
			scanf("%i %i",&v1,&v2);
			appendElementsAdjList(lenin,v1-1,v2-1);
		}
		//displayAdjList(lenin,0);	
		germans=(int*)calloc(inps[0],sizeof(int));
		int repetion,temp;	
		scanf("%i",&repetion);
		for(int i=0;i<repetion;++i){
			scanf("%i",&temp);
			++germans[temp-1];
		}
		int source,destiny;
		scanf("%i %i",&source,&destiny);
		tsts[index]=pow(prob,(double)inps[2]-Dijkstra(source-1,destiny-1,inps[2],inps[0]));
		printf("%.3lf\n",pow(prob,(double)inps[2]-Dijkstra(source-1,destiny-1,inps[2],inps[0])));
		free(lenin);
		++index;
	}
	for(int i=0;i<index;++i)printf("%.3lf ",tsts[i]);
	return 0;
}
