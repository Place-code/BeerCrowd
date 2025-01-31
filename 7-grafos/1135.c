#include<stdlib.h>
#include<stdio.h>
#include<math.h>
//

typedef struct Vector{
	int*array,index;
	size_t length;
}Vector;

struct Vector*createVector(size_t size){
	Vector*newVector=(Vector*)malloc(sizeof(Vector));
	newVector->array=(int*)malloc(size*sizeof(int));
	newVector->index=0;
	newVector->length=size;
	return newVector;
}
void appendElementVector(Vector*ref,int value){
	if((size_t)ref->index>ref->length-1){
		ref->array=realloc(ref->array,ref->length*2*sizeof(int));
		ref->length*=2;
	}
	ref->array[ref->index]=value;
	++ref->index;
}

typedef struct AdjList{
	Vector**list;
	size_t length;
}AdjList;

struct AdjList*createAdj(size_t AmountV,size_t AmountItemsV){
	AdjList*newAdj=(AdjList*)malloc(sizeof(AdjList));
	newAdj->list=(Vector**)malloc(AmountV*sizeof(Vector*));
	for(int i=0;i<(int)AmountV;++i)newAdj->list[i]=createVector(AmountItemsV);
	newAdj->length=AmountV;
	return newAdj;
}

AdjList*adj_list;
Vector*pathDFS;
int*inAdj,*indexs;
unsigned long long*weight;

void DFS(int node){
	if(!inAdj[node])return;
	for(int i=0;i<adj_list->list[inAdj[node]-1]->index;++i){
		int vertic=adj_list->list[inAdj[node]-1]->array[i];
		appendElementVector(pathDFS,node);
		(!indexs[node])?indexs[node]=pathDFS->index:indexs[node];
		DFS(vertic);
		appendElementVector(pathDFS,vertic);
		(!indexs[vertic])?indexs[vertic]=pathDFS->index:indexs[vertic];
	}
}
int logTw(int n){
	int i;
	for(i=1;(1<<(i+1))<n+1;++i){}
	return i;
}
int**logTwo(Vector*aray,int amountV){
	int**result=(int**)malloc(amountV*sizeof(int*)),logg=logTw(amountV)+1;
	for(int i=0;i<amountV;++i){
		result[i]=(int*)malloc((logg*sizeof(int)));
		result[i][0]=i;
	}
	for(int i=1;(1<<i)<amountV+1;++i){
		for(int j=0;(j+(1<<i)-1)<amountV;++j){
			if(aray->array[result[j][i-1]]<aray->array[result[j+(1<<(i-1))][i-1]])result[j][i]=result[j][i-1];
			else result[j][i]=result[j+(1<<(i-1))][i-1];
		}
	}
	return result;
}

void ProcessQ(int amountQ,int amountV){
	indexs=(int*)calloc(amountV,sizeof(int));
	pathDFS=createVector((amountV-1)*2);
	DFS(0);
	free(adj_list);
	free(inAdj);
	int**min=logTwo(pathDFS,pathDFS->index),logg=logTw(pathDFS->index)+1;
	for(int i=0;i<amountQ;++i){
		int source,destiny,ind1,ind2,tempLog;
		scanf("%i %i",&source,&destiny);
		if(indexs[source]>indexs[destiny]){
			destiny+=source;
			source=destiny-source;
			destiny-=source;
		}
		//	
		ind1=indexs[source]-1;
		ind2=indexs[destiny]-1;
		tempLog=logTw(ind2-ind1+1);
		int commonVertic=(pathDFS->array[min[ind1][tempLog]]<pathDFS->array[min[ind2-(1<<tempLog)+1][tempLog]]+1)?pathDFS->array[min[ind1][tempLog]]:pathDFS->array[min[ind2-(1<<tempLog)+1][tempLog]];
		printf("%llu",weight[source]+weight[destiny]-weight[commonVertic]*2);
		if(i<amountQ-1)printf(" ");
		else printf("\n");
	}
	free(pathDFS);
	free(indexs);
	free(weight);
}
//
int main(){
	int rep;
	while(scanf("%i",&rep)&&rep){
		int*tempRep=(int*)malloc(rep*sizeof(int)),sizeAdj=0;
		inAdj=(int*)calloc(rep,sizeof(int));
		weight=(unsigned long long*)calloc(rep,sizeof(unsigned long long));
		//
		for(int i=1;i<rep;++i){
			unsigned long long length;
			int v;
			scanf("%i %llu",&v,&length);
			if(!inAdj[v]){
				++sizeAdj;
				inAdj[v]=sizeAdj;
			}
			tempRep[i-1]=v;
			weight[i]=weight[v]+length;
		}
		adj_list=createAdj(sizeAdj,rep/sizeAdj);
		for(int i=0;i<rep-1;++i)appendElementVector(adj_list->list[inAdj[tempRep[i]]-1],i+1);
		int amountQueries;
		scanf("%i",&amountQueries);
		ProcessQ(amountQueries,rep);
	}
	return 0;
}
