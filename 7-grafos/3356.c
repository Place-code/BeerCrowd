#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//
typedef struct Queue{
	int value;
	struct Queue*next;
}Queue;

struct Queue*createNodeQueue(int value){
	Queue*newQueue=(Queue*)malloc(sizeof(Queue));
	newQueue->value=value;
	newQueue->next=NULL;
	return newQueue;
}
	
struct Queue*appendElementQueue(Queue*ref,int newValue){
	ref->next=createNodeQueue(newValue);
	ref=ref->next;
	return ref;
}
//
typedef struct Vector{
	int*array;
	int index;
	int key;
	size_t lenght;
	struct Vector*plus;
}Vector;

struct Vector*createVector(size_t lenght){
	Vector*newVector=(Vector*)malloc(sizeof(Vector));
	newVector->array=calloc(lenght,sizeof(int));
	newVector->index=0;
	newVector->lenght=lenght;
	newVector->plus=NULL;
	return newVector;
}

void incraseLenghtVector(Vector*ref){
	if(!ref->plus){
		ref->plus=createVector(ref->lenght);
		return;
	}
	incraseLenghtVector(ref->plus);
}

void appendElementVector(Vector*ref,int value){
	if(ref->index<(int)ref->lenght){
		ref->array[ref->index]=value;
		++ref->index;
		return;
	}
	if(!ref->plus)incraseLenghtVector(ref);
	appendElementVector(ref->plus,value);
}

int acessElementVector(Vector*ref,int index){
	if(index<(int)ref->lenght-1){
		return ref->array[index];
	}
	acessElementVector(ref->plus,index-(int)ref->lenght);
}
//
typedef struct Map{
	Vector***hesh;
	int lenght;
	size_t lenghtMaximum;
}Map;

struct Map*createMap(size_t lenghtMap,size_t maxString,size_t lenghtChar){
	Map*newMap=(Map*)malloc(sizeof(Map));
	newMap->hesh=(Vector***)malloc(sizeof(Vector**)*lenghtMap);
	for(int i=0;i<lenghtMap;++i){
		newMap->hesh[i]=(Vector**)malloc(sizeof(Vector*)*maxString);
		for(int j=0;j<maxString;++j)newMap->hesh[i][j]=createVector(lenghtChar);
	}
	newMap->lenghtMaximum=lenghtMap;
	newMap->lenght=0;
	return newMap;
}

int weightString(char temp[]){
	int r=0;
	for(int i=0;i<strlen(temp);++i){
		r+=(int)temp[i]-65;
	}
	return r;
}

void appendElementMap(Map*ref,char string[]){
	int tot=weightString(string),index;
	for(index=0;ref->hesh[tot%ref->lenghtMaximum][index]->array[0];++index){}
	for(int i=0;i<strlen(string);++i)ref->hesh[tot%ref->lenghtMaximum][index]->array[i]=(int)string[i];
	ref->hesh[tot%ref->lenghtMaximum][index]->key=ref->lenght;
	ref->hesh[tot%ref->lenghtMaximum][index]->index=strlen(string);
	++ref->lenght;
}
int getKey(Map*ref,char string[]){
	int tot=weightString(string),index;
	for(index=0;ref->hesh[tot%ref->lenghtMaximum][index]->array[0];++index){
		int stop=1;
		for(int j=0;j<strlen(string);++j){
			if(ref->hesh[tot%ref->lenghtMaximum][index]->array[j]!=(int)string[j]){
				stop=0;
				break;
			}
		}
		if(stop)break;
	}
	return ref->hesh[tot%ref->lenghtMaximum][index]->key;
}
int inMap(Map*ref,char string[]){
	int tot=weightString(string);
	for(int i=0;ref->hesh[tot%ref->lenghtMaximum][i]->array[0];++i){
		int equals=1;
		for(int j=0;j<strlen(string);++j){
			if(ref->hesh[tot%ref->lenghtMaximum][i]->array[j]!=string[j]){
				equals=0;
				break;
			}
		}
		if(equals)return 1;
	}
	return 0;
}
//
typedef struct AdjList{
	Vector**adj;
	size_t lenght;
}AdjList;

struct AdjList*createAdjList(size_t lenght,size_t lenghtVector){
	AdjList*newAdj=(AdjList*)malloc(sizeof(AdjList));
	newAdj->adj=(Vector**)malloc(sizeof(Vector*)*lenght);
	for(int i=0;i<(int)lenght;++i)newAdj->adj[i]=createVector(lenghtVector);
	newAdj->lenght=lenght;
	return newAdj;
}

//
void displayVector(Vector*ref){
	for(int i=0;i<ref->index;++i){
		printf("%i ",ref->array[i]);
	}
	if(ref->plus)displayVector(ref->plus);
	else printf("\n");
}
void displayQueue(Queue*ref){
	if(!ref->next){
		printf("%i\n",ref->value);
		return;
	}
	printf("%i ",ref->value);
	displayQueue(ref->next);
}
void displayMap(Map*ref){
	for(int i=0,j;i<ref->lenghtMaximum;++i){
		for(j=0;ref->hesh[i][j]->array[0];++j){
			for(int k=0;k<ref->hesh[i][j]->index;++k){
				printf("%c",(char)ref->hesh[i][j]->array[k]);
				//tst[k]=(char)ref->hesh[i][j]->array[k];
			}
			printf("|");
		}
		if(j)printf("\n");
	}
}
void displayAdjList(AdjList*ref,int init){
	if(init>(int)ref->lenght-1){
		return;
	}
	if(ref->adj[init]->index){
		printf("%i-",init);
		displayVector(ref->adj[init]);
	}
	displayAdjList(ref,init+1);
}
//
int *explored;
Map*translate;
AdjList*adj;
int bfs(Queue*currentQueue){
	Queue*aux=createNodeQueue(-1),*auxAux=aux;
	while(currentQueue){
		//printf("|%i\n",currentQueue->value);
		for(int i=0;i<adj->adj[currentQueue->value]->index;++i){
			int vertices=adj->adj[currentQueue->value]->array[i];
			if(explored[vertices])return 1;
			//printf("%i-",vertices);
			auxAux=appendElementQueue(auxAux,vertices);
			explored[vertices]=1;
		}
		currentQueue=currentQueue->next;
	}
	aux=aux->next;
	if(!aux)return 0;
	bfs(aux);
}
//
int main(){
	int inps[3];
	scanf("%i %i %i",&inps[0],&inps[1],&inps[2]);
	translate=createMap(inps[0],inps[0],20);
	adj=createAdjList((size_t)inps[0],4);
	for(int i=0;i<inps[1];++i){
		int c;
		char inp[3][20];
		scanf("%s %s %s",&inp[0],&inp[1],&inp[2]);
		while((c=getchar())!='\n'&&c!=EOF){}
		for(int j=0;j<3;++j)
			if(!inMap(translate,inp[j]))appendElementMap(translate,inp[j]);
		appendElementVector(adj->adj[getKey(translate,inp[2])],getKey(translate,inp[0]));
		appendElementVector(adj->adj[getKey(translate,inp[2])],getKey(translate,inp[1]));
	}
	//displayMap(translate);
	//displayAdjList(adj,0);
	for(int i=0;i<inps[2];++i){
		char tst[2][20];
		scanf("%s %s",&tst[0],&tst[1]);
		//printf("%i %i\n",getKey(translate,tst[0]),getKey(translate,tst[1]));
		explored=calloc(inps[0],sizeof(int));
		explored[getKey(translate,tst[0])]=1;
		explored[getKey(translate,tst[1])]=1;
		Queue*fila=createNodeQueue(getKey(translate,tst[0])),*auxFila=fila;
		auxFila=appendElementQueue(auxFila,getKey(translate,tst[1]));
		if(bfs(fila))printf("verdadeiro\n");
		else printf("falso\n");
		free(explored);
		free(fila);
	}
	return 0;
}
