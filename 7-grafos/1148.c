#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//
void swapArray(int*array,int index1,int index2){
	array[index1]+=array[index2];
	array[index2]=array[index1]-array[index2];
	array[index1]-=array[index2];
}
int*resizeArray(int*array,int newSize){
	int*newArray=realloc(array,sizeof(int)*newSize);
	return newArray;
}
void initializateArray(int*array,int valueInit,int sizeArray){
	for(int i=0;i<sizeArray;++i)array[i]=valueInit;
}
int*heapWeight,*heapVertic,Index,length;
//
void shiftUp(int index){
	if(heapWeight[index]>heapWeight[(index-1)/2]|!index)return;
	swapArray(heapWeight,index,(index-1)/2);
	swapArray(heapVertic,index,(index-1)/2);
	shiftUp((index-1)/2);
}
void shiftDown(int index){
	int temp=index;
	if(heapWeight[index*2+1]<heapWeight[index]&&index*2+1<Index)temp=index*2+1;
	if(heapWeight[index*2+2]<heapWeight[temp]&&index*2+2<Index)temp=index*2+2;
	if(temp!=index){
		swapArray(heapWeight,index,temp);
		swapArray(heapVertic,index,temp);
		shiftDown(temp);
	}
}
void insertHeap(int vertic,int weight){
	heapWeight[Index]=weight;
	heapVertic[Index]=vertic;
	if(Index>length-2){
		heapWeight=resizeArray(heapWeight,length*2);
		heapVertic=resizeArray(heapVertic,length*2);
		length*=2;
	}
	shiftUp(Index);
	++Index;
}
int*extractHeap(){
	int*result=malloc(2*sizeof(int));
	result[1]=heapWeight[0];
	result[0]=heapVertic[0];
	--Index;
	heapWeight[0]=heapWeight[Index];
	heapVertic[0]=heapVertic[Index];
	shiftDown(0);
	return result;
}
void initializationHeap(int lengthHeap){
	length=lengthHeap;
	heapWeight=malloc(sizeof(int)*length);
	heapVertic=malloc(sizeof(int)*length);
	Index=0;
}
//
int**matrix,destiny,origin;
int Dijkstra(int sizeGraph){
	int*time=malloc(sizeof(int)*sizeGraph);
	initializateArray(time,2147483647,sizeGraph);
	time[origin]=0;
	initializationHeap(sizeGraph);
	insertHeap(origin,0);
	while(Index){
		int*analyse=extractHeap();
		if(analyse[1]>time[destiny])break;
		//printf("|%i %i|",analyse[0],analyse[1]);
		for(int i=0;i<sizeGraph;++i){
			if(matrix[analyse[0]][i]==-1)continue;
			//printf("%i %i/",i,matrix[analyse[0]][i]);
			if(time[i]>analyse[1]+matrix[analyse[0]][i]){
				time[i]=analyse[1]+matrix[analyse[0]][i];
				if(i!=destiny){
					insertHeap(i,time[i]);
					//printf("OK\n");
				}
			}
		}
	}
	free(heapWeight);
	free(heapVertic);
	return time[destiny];
}
//
int main(){
	int vert,edge;
	while(scanf("%i %i",&vert,&edge)&&(vert|edge)){
		matrix=(int**)malloc(sizeof(int*)*vert);
		for(int i=0;i<vert;++i){
			matrix[i]=(int*)malloc(sizeof(int)*vert);
			initializateArray(matrix[i],-1,vert);
		}
		for(int i=0;i<edge;++i){
			int v1,v2,h;
			scanf("%i %i %i",&v1,&v2,&h);
			matrix[v1-1][v2-1]=h;
			if(matrix[v2-1][v1-1]!=-1){
				matrix[v1-1][v2-1]=0;
				matrix[v2-1][v1-1]=0;
			}
		}
		int queries;
		for(scanf("%i",&queries);queries>0;--queries){
			scanf("%i %i",&origin,&destiny);
			--origin;
			--destiny;
			int result=Dijkstra(vert);
			if(result==2147483647)printf("Nao e possivel entregar a carta\n");
			else printf("%i\n",result);
		}
		printf("\n");
	}
	return 0;
}
