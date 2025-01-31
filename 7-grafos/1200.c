#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//
typedef struct NodeBT{
	int value;
	struct NodeBT*right,*left;
}NodeBT;
struct NodeBT*initializateBT(int valueNode){
	NodeBT*newBT=(NodeBT*)malloc(sizeof(NodeBT));
	newBT->value=valueNode;
	newBT->right=NULL;
	newBT->left=NULL;
	return newBT;
}
void insertBT(NodeBT*ref,int newValue){
	if(newValue<ref->value+1&&!ref->left){
		ref->left=initializateBT(newValue);
		return;
	}
	if(newValue>ref->value&&!ref->right){
		ref->right=initializateBT(newValue);
		return;
	}
	//
	if(newValue<ref->value+1)insertBT(ref->left,newValue);
	else insertBT(ref->right,newValue);
}
int searchBT(NodeBT*ref,int sValue){
	if(!ref)return 0;
	if(ref->value==sValue)return 1;
	int result=0;
	(sValue<ref->value+1)?result=searchBT(ref->left,sValue):(sValue>ref->value)?result=searchBT(ref->right,sValue):result;
	return result;
}
//
int*display,lengthBT,Index;
void preOrder(NodeBT*ref){
	if(!ref)return;
	display[Index]=ref->value;
	++Index;
	preOrder(ref->left);
	preOrder(ref->right);
}
void inOrder(NodeBT*ref){
	if(!ref)return;
	inOrder(ref->left);
	display[Index]=ref->value;
	++Index;
	inOrder(ref->right);
}
void postOrder(NodeBT*ref){
	if(!ref)return;
	postOrder(ref->left);
	postOrder(ref->right);
	display[Index]=ref->value;
	++Index;
}
void displayPath(NodeBT*ref,char type[]){
	display=(int*)malloc(sizeof(int)*lengthBT);
	Index=0;
	if(type[0]=='I')inOrder(ref);
	else if(type[0]=='P'&&type[1]=='R')preOrder(ref);
	else postOrder(ref);
	for(int i=0;i<lengthBT-1;++i)printf("%c ",(char)display[i]);
	printf("%c\n",(char)display[lengthBT-1]);
	free(display);
}
void commandInsert(NodeBT*ref,int value){
	if(!lengthBT)ref->value=value;
	else insertBT(ref,value);
}
//
int main(){
	char inp[20];
	NodeBT*binaryT=initializateBT(0);
	lengthBT=0;
	while(fgets(inp,20,stdin)){
		char extract[2][10],*split,*ex=inp;
		strcpy(extract[1]," ");
		for(int i=0;split=strtok_r(ex," ",&ex);++i)strcpy(extract[i],split);
		//
		if(!strcmp(extract[1]," "))displayPath(binaryT,extract[0]);
		else if(!strcmp(extract[0],"I"))commandInsert(binaryT,(int)extract[1][0]);
		else if(searchBT(binaryT,(int)extract[1][0]))printf("%c existe\n",extract[1][0]);
		else printf("%c nao existe\n",extract[1][0]);
		(!strcmp(extract[0],"I"))?++lengthBT:lengthBT;
	}
	return 0;
}
