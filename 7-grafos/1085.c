#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//
typedef struct Vector{
	int*array;
	size_t index,length;
}Vector;
struct Vector*createVector(size_t length){
	Vector*newVector=(Vector*)malloc(sizeof(Vector));
	newVector->array=(int*)malloc(length*sizeof(int));
	newVector->index=0;
	newVector->length=length;
	return newVector;
}
void appendElementVector(Vector*ref,int value){
	if(ref->index>ref->length-1){
		ref->array=(int*)realloc(ref->array,sizeof(int)*ref->length*2);
		ref->length*=2;
	}
	ref->array[ref->index]=value;
	++ref->index;
}
//
struct Vector*createEdge(int value[],size_t length){
	Vector*edge=createVector(length);
	for(size_t i=0;i<length;++i)edge->array[i]=value[i];
	edge->index=length;
	return edge;
}
typedef struct Vertices{
	Vector**vertexs;
	size_t lengthVertic,indexVertic;
}Vertices;
struct Vertices*createNode(){
	Vertices*newVertic=malloc(sizeof(Vertices));
	newVertic->vertexs=malloc(sizeof(Vector*));
	newVertic->indexVertic=0;
	newVertic->lengthVertic=1;
	return newVertic;
}
void appendEdge(Vertices*ref,int values[],int sizeValues){
	if(ref->indexVertic>ref->lengthVertic-1){
		ref->vertexs=realloc(ref->vertexs,sizeof(Vector*)*ref->lengthVertic*2);
		ref->lengthVertic*=2;
	}
	ref->vertexs[ref->indexVertic]=createEdge(values,sizeValues);
	++ref->indexVertic;
}
typedef struct AdjList{
	Vertices**adj;
	size_t length;
}AdjList;
struct AdjList*createAdjList(size_t lengthV){
	AdjList*newAdj=(AdjList*)malloc(sizeof(AdjList));
	newAdj->adj=malloc(sizeof(Vertices*)*lengthV);
	for(size_t i=0;i<lengthV;++i)newAdj->adj[i]=createNode();
	newAdj->length=lengthV;
	return newAdj;
}
typedef struct HashTable{
	Vertices**hash;
	size_t lengthHash,indexHash;
}HashTable;
struct HashTable*createHash(size_t lengthHash){
	HashTable*newHash=malloc(sizeof(HashTable));
	newHash->hash=malloc(sizeof(Vertices*)*lengthHash);
	for(size_t i=0;i<lengthHash;++i)newHash->hash[i]=createNode();
	newHash->lengthHash=lengthHash;
	newHash->indexHash=0;
	return newHash;
}
void appendStringHash(HashTable*ref,char string[]){
	int index=0,array[strlen(string)+1];
	for(size_t i=0;i<strlen(string);++i){
		index+=(int)string[i];
		array[i+1]=(int)string[i];
	}
	array[0]=ref->indexHash;
	index%=ref->lengthHash;
	appendEdge(ref->hash[index],array,strlen(string)+1);
	++ref->indexHash;
}
int indexStringInHash(HashTable*ref,char string[]){
	int index=0,array[strlen(string)];
	for(size_t i=0;i<strlen(string);++i){
		index+=(int)string[i];
		array[i]=(int)string[i];
	}
	for(size_t i=0;i<ref->hash[index%ref->lengthHash]->indexVertic;++i){
		Vector*aux=ref->hash[index%ref->lengthHash]->vertexs[i];
		if(aux->index-1!=strlen(string))continue;
		int is=1;
		for(size_t j=0;j<aux->index-1;++j){
			if(aux->array[j+1]!=array[j]){
				is=0;break;
			}
		}
		if(is)return aux->array[0]+1;
	}
	return 0;
}
void swap(Vertices*ref,int id1,int id2){
	Vector*aux=ref->vertexs[id1];
	ref->vertexs[id1]=ref->vertexs[id2];
	ref->vertexs[id2]=aux;
}
void shiftUp(Vertices*heap,size_t index){
	if(!index)return;
	if(heap->vertexs[(index-1)/2]->array[1]<heap->vertexs[index]->array[1])return;
	swap(heap,index,(index-1)/2);
	shiftUp(heap,(index-1)/2);
}
void shiftDown(Vertices*heap,size_t index){
	size_t temp=index;
	(index*2+1<heap->indexVertic&&heap->vertexs[index*2+1]->array[1]<heap->vertexs[temp]->array[1])?temp=index*2+1:temp;
	//
	(index*2+2<heap->indexVertic&&heap->vertexs[index*2+2]->array[1]<heap->vertexs[temp]->array[1])?temp=index*2+2:temp;
	if(temp!=index){
		swap(heap,index,temp);
		shiftDown(heap,temp);
	}
}
void insertHeap(Vertices*ref,int values[],int lengthValues){
	if(ref->indexVertic>ref->lengthVertic-1){
		ref->vertexs=realloc(ref->vertexs,sizeof(Vertices*)*ref->lengthVertic*2);
		ref->lengthVertic*=2;
	}
	ref->vertexs[ref->indexVertic]=createEdge(values,lengthValues);
	shiftUp(ref,ref->indexVertic);
	++ref->indexVertic;
}
Vector*extractHeap(Vertices*ref){
	Vector*result=ref->vertexs[0];
	--ref->indexVertic;
	ref->vertexs[0]=ref->vertexs[ref->indexVertic];
	shiftDown(ref,0);
	return result;
}
AdjList*list; // vertex,strlen(word),initial_letter
// 
int Dijkstra(size_t amount_itens){
	Vertices*queue=createNode();
	int temp[]={0,0,0},**min=malloc(sizeof(int*)*(amount_itens+1)),*minVertic=malloc(sizeof(int)*amount_itens);
	for(size_t i=0;i<amount_itens;++i){
		min[i]=malloc(sizeof(int)*27);
		minVertic[i]=2147483647;
		for(size_t j=0;j<27;++j)min[i][j]=2147483647;
	}
	insertHeap(queue,temp,3);
	minVertic[0]=0;
	while(queue->indexVertic){
		int*arrayQ=extractHeap(queue)->array;
		//printf("%i %i %i-\n",arrayQ[0],arrayQ[1],arrayQ[2]);
		if(arrayQ[1]>minVertic[1]-1)return minVertic[1];
		for(size_t i=0;i<list->adj[arrayQ[0]]->indexVertic;++i){
			int*auxInt=list->adj[arrayQ[0]]->vertexs[i]->array;
			//
			int auxV=auxInt[0],auxW=auxInt[1],auxI=auxInt[2];
			//printf("%i %i %i|",auxV,auxW,auxI);
			if(arrayQ[2]==auxI)continue;
			if(min[auxV][auxI]>arrayQ[1]+auxW){
				min[auxV][auxI]=arrayQ[1]+auxW;
				if(min[auxV][auxI]<minVertic[auxV])minVertic[auxV]=min[auxV][auxI];
				if(auxV!=1){
					int t[]={auxV,min[auxV][auxI],auxI};
					insertHeap(queue,t,3);
				}
			}
		}
	}
	return minVertic[1];
}
//
int main(){
	int rep,cc;
	while(scanf("%i",&rep)&&rep){
		while((cc=getchar())!='\n'&&cc!=EOF){}
		char init1[120],init2[120];
		HashTable*translate=createHash(rep*2);
		scanf("%s %s",init1,init2);
		while((cc=getchar())!='\n'&&cc!=EOF){}
		appendStringHash(translate,init1);
		appendStringHash(translate,init2);
		list=createAdjList(rep*2+10);
		for(int i=0;i<rep;++i){
			int v1,v2,c;
			char inp1[120],inp2[120],inp3[120];
			scanf("%s %s %s",inp1,inp2,inp3);
			while((c=getchar())!='\n'&&c!=EOF){}
			if(!indexStringInHash(translate,inp1))appendStringHash(translate,inp1);
			v1=indexStringInHash(translate,inp1)-1;
			if(!indexStringInHash(translate,inp2))appendStringHash(translate,inp2);
			v2=indexStringInHash(translate,inp2)-1;
			//
			//printf("%i %i %i V`s\n",v1,v2,i);
			int array[]={v2,strlen(inp3),(int)inp3[0]-96};
			appendEdge(list->adj[v1],array,3);
			array[0]=v1;
			appendEdge(list->adj[v2],array,3);
		}
		/*
		for(size_t i=0;i<translate->indexHash;++i){
			if(!list->adj
		*/
		int temp=Dijkstra(translate->indexHash);
		if(temp==2147483647)printf("impossivel\n");
		else printf("%i\n",temp);
		free(list);
	}
	return 0;
}
