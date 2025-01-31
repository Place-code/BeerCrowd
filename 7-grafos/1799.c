#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//
typedef struct Vector{// Um array aceitavel
	int*array;
	size_t index,length;
}Vector;
struct Vector*createVector(size_t lengthVector){
	Vector*new_vector=malloc(sizeof(Vector));
	new_vector->array=malloc(sizeof(int)*lengthVector);
	new_vector->index=0;
	new_vector->length=lengthVector;
	return new_vector;
}
void appendElementVector(Vector*ref,int new_value){
	if(ref->index>ref->length-1){
		ref->array=realloc(ref->array,sizeof(int)*ref->length*2);
		ref->length*=2;
	}
	ref->array[ref->index]=new_value;
	++ref->index;
}
int popElementVector(Vector*ref){
	--ref->index;
	return ref->array[ref->index];
}
typedef struct Array_V{// Array de Arrays
	Vector**array_V;
	size_t indexArray_V,lengthArray_V;
}Array_V;
struct Array_V*create_ArrayVectors(size_t length){
	Array_V*new_array=malloc(sizeof(Array_V));
	new_array->array_V=malloc(sizeof(Vector*)*length);
	new_array->indexArray_V=0;
	new_array->lengthArray_V=length;
	return new_array;
}
void appendElementArrayV(Array_V*ref,int values[],size_t size_values){
	if(ref->indexArray_V>ref->lengthArray_V-1){
		ref->array_V=realloc(ref->array_V,sizeof(Vector*)*ref->lengthArray_V*2);
		ref->lengthArray_V*=2;
	}
	ref->array_V[ref->indexArray_V]=createVector(size_values);
	for(size_t i=0;i<size_values;++i)ref->array_V[ref->indexArray_V]->array[i]=values[i];
	ref->array_V[ref->indexArray_V]->index=size_values;
	++ref->indexArray_V;
}
typedef struct HashTable{
	Array_V**hash;
	size_t max_len,c_len;
}HashTable;
struct HashTable*createHash(size_t length_hash){
	HashTable*newHash=malloc(sizeof(HashTable));
	newHash->hash=malloc(sizeof(Array_V*)*length_hash);
	for(size_t i=0;i<length_hash;++i)newHash->hash[i]=create_ArrayVectors(1);
	newHash->max_len=length_hash;
	newHash->c_len=0;
	return newHash;
}
void insert_string_inHashTable(HashTable*ref,char args[]){
	int array[strlen(args)+1],index=0;
	for(size_t i=0;i<strlen(args);++i){
		index+=(int)args[i];
		array[i+1]=(int)args[i];
	}
	array[0]=ref->c_len;
	index%=ref->max_len;
	appendElementArrayV(ref->hash[index],array,strlen(args)+1);
	++ref->c_len;
}
int search_string_inHashTable(HashTable*ref,char args[]){
	int array[strlen(args)],index=0;
	for(size_t i=0;i<strlen(args);++i){
		array[i]=(int)args[i];
		index+=(int)args[i];
	}
	index%=ref->max_len;
	for(size_t i=0;i<ref->hash[index]->indexArray_V;++i){
		Vector*aux=ref->hash[index]->array_V[i];
		if(aux->index-1!=strlen(args))continue;
		int equals=1;
		for(size_t j=0;j<aux->index-1;++j){
			if(aux->array[j+1]!=array[j]){
				equals=0;
				break;
			}
		}
		if(equals)return aux->array[0]+1;
	}
	return 0;
}
//
int bfs(int init,int destiny){
	Vector*queue=createVector(1);
	int*explored=calloc(adj->lengthArray_V,sizeof(int));
	explored[init]=1;
	appendElementVector(queue,init);
	for(int i=0;queue->index;++i){
		Vector*requeue=createVector(1);
		while(queue->index){
			int c_vertex=popElementVector(queue);
			if(c_vertex==destiny)return i;
			for(size_t j=0;j<adj->array_V[c_vertex]->index;++j){
				int aux=adj->array_V[c_vertex]->array[j];
				if(explored[aux])continue;
				appendElementVector(requeue,aux);
				explored[aux]=1;
			}
		}
		queue=requeue;
	}
	return 0;
}
//
int main(){
	int vertexs,edges;
	scanf("%i %i",&vertexs,&edges);
	adj=create_ArrayVectors(vertexs+3);
	for(size_t i=0;i<vertexs+3;++i)adj->array_V[i]=createVector(1);
	HashTable*translate=createHash(edges);
	//
	insert_string_inHashTable(translate,"Entrada");
	insert_string_inHashTable(translate,"*");
	insert_string_inHashTable(translate,"Saida");
	//
	for(int i=0;i<edges;++i){
		char v1[120],v2[120];
		scanf("%s %s",v1,v2);
		//printf("%s %s\n",v1,v2);
		if(!search_string_inHashTable(translate,v1)){
			insert_string_inHashTable(translate,v1);
		}
		if(!search_string_inHashTable(translate,v2)){
			insert_string_inHashTable(translate,v2);
		}
		int id1=search_string_inHashTable(translate,v1),id2=search_string_inHashTable(translate,v2);
		appendElementVector(adj->array_V[id1-1],id2-1);
		appendElementVector(adj->array_V[id2-1],id1-1);
	}
	printf("%i\n",bfs(0,1)+bfs(1,2));
	return 0;
}
