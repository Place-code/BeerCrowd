#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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

int*resizeArray(int array[],size_t oldLength,size_t newLength){
	int*newArray=calloc(newLength,sizeof(int));
	for(int i=0;i<(int)oldLength;++i)newArray[i]=array[i];	
	return newArray;
}

void appendElementVector(Vector*ref,int newValue){
	if(ref->index>(int)ref->length-1){
		ref->array=resizeArray(ref->array,ref->length,ref->length*2);
		ref->length*=2;
	}
	ref->array[ref->index]=newValue;
	++ref->index;
}
//
typedef struct AdjList{
	Vector**list;
	size_t length;
}AdjList;

struct AdjList*createAdjList(size_t lengthStruct,size_t lengthVectors){
	AdjList*newAdj=(AdjList*)malloc(sizeof(AdjList));
	newAdj->list=(Vector**)malloc(sizeof(Vector)*lengthStruct);
	newAdj->length=lengthStruct;
	for(int i=0;i<(int)lengthStruct;++i)newAdj->list[i]=createVector(lengthVectors);
	return newAdj;
}

void appendVerticesAdjList(AdjList*ref,int v1,int v2){
	appendElementVector(ref->list[v1],v2);
	appendElementVector(ref->list[v2],v1);
}
void appendWeights(AdjList*ref,int v1,int v2,int weight){
	appendElementVector(ref->list[v1],weight);
	appendElementVector(ref->list[v2],weight);
}
//
int*heap,*heapVertice,Index=0,length=0;
void shiftUp(int i){
	while(i>0&&heap[(i-1)/2]>heap[i]){
		heap[(i-1)/2]+=heap[i];
		heap[i]=heap[(i-1)/2]-heap[i];
		heap[(i-1)/2]-=heap[i];
		//
		heapVertice[(i-1)/2]+=heapVertice[i];
		heapVertice[i]=heapVertice[(i-1)/2]-heapVertice[i];
		heapVertice[(i-1)/2]-=heapVertice[i];
		i=(i-1)/2;
	}
}
void shiftDown(int i){
	int maxIndex=i;
	if((i*2)+1<Index+1&&heap[(i*2)+1]<heap[i]){
		maxIndex=(i*2)+1;
	}
	if((i*2)+2<Index+1&&heap[(i*2)+2]<heap[maxIndex]){
		maxIndex=(i*2)+2;
	}
	if(maxIndex!=i){
		heap[i]+=heap[maxIndex];
		heap[maxIndex]=heap[i]-heap[maxIndex];
		heap[i]-=heap[maxIndex];
		//
		heapVertice[i]+=heapVertice[maxIndex];
		heapVertice[maxIndex]=heapVertice[i]-heapVertice[maxIndex];
		heapVertice[i]-=heapVertice[maxIndex];
		shiftDown(maxIndex);
	}
}
void insert(int newValue,int newVertice){
	heap[Index]=newValue;
	heapVertice[Index]=newVertice;
	if(Index>length){
		length*=2;
		heap=resizeArray(heap,Index+1,length);
		heapVertice=resizeArray(heapVertice,Index+1,length);
	}
	shiftUp(Index);
	++Index;
}

int*extractMin(){
	int*result=(int*)malloc(sizeof(int)*2);
	result[0]=heap[0];
	result[1]=heapVertice[0];
	--Index;
	heap[0]=heap[Index];
	heapVertice[0]=heapVertice[Index];
	shiftDown(0);
	return result;
}
//
void displayVector(Vector*ref){
	for(int i=0;i<ref->index;++i){
		printf("%i ",ref->array[i]);
	}
}
void displayAdjList(AdjList*ref,int init){
	if(init>(int)ref->length-1)return;
	displayVector(ref->list[init]);
	if(ref->list[init]->index)printf("\n");
	displayAdjList(ref,init+1);
}
//
int vs[4],*minimum;
AdjList*adj,*weights;
void dijkstra(){
	minimum=calloc(vs[0],sizeof(int));
	minimum[vs[3]]=1;
	minimum[vs[2]-1]=-1;
	while(Index){
		int*aux=extractMin();
		if(aux[0]>minimum[vs[2]-1]-1&&minimum[vs[2]-1]!=-1)return;
		//printf("|%i %i| ",aux[1],aux[0]);
		for(int i=0;i<adj->list[aux[1]]->index;++i){
			int auxV=adj->list[aux[1]]->array[i],auxW=weights->list[aux[1]]->array[i];
			if(((aux[1]<vs[2]-2&&auxV==aux[1]+1)|aux[1]>vs[2]-1)&&(!minimum[auxV]|minimum[auxV]>aux[0]+auxW)){
				insert(aux[0]+auxW,auxV);
				//printf("/%i/",auxV);
				minimum[auxV]=aux[0]+auxW;
			}
			if(auxV==vs[2]-1&&(minimum[auxV]>aux[0]+auxW|minimum[auxV]==-1)&&(aux[1]>vs[2]-1|aux[1]==vs[2]-2)){
				minimum[auxV]=aux[0]+auxW;
			}
		}
	}
}
//
int main(){
	while(scanf("%i %i %i %i",&vs[0],&vs[1],&vs[2],&vs[3])&&vs[0]&&vs[1]&&vs[2]&&vs[3]){
		int c;
		while((c=getchar())!='\n'&&c!=EOF){}
		adj=createAdjList(vs[0],vs[0]/2);
		weights=createAdjList(vs[0],vs[0]/2);
		for(int i=0;i<vs[1];++i){
			int v1,v2,weight;
			scanf("%i %i %i",&v1,&v2,&weight);
			appendVerticesAdjList(adj,v1,v2);
			appendWeights(weights,v1,v2,weight);
		}
		while((c=getchar())!='\n'&&c!=EOF){}
		heap=calloc(vs[0],sizeof(int));
		heapVertice=calloc(vs[0],sizeof(int));
		length=vs[0];
		Index=0;
		insert(0,vs[3]);
		dijkstra();
		printf("%i\n",minimum[vs[2]-1]);
		free(heap);
		free(heapVertice);
		free(adj);
		free(weights);
	}
}
