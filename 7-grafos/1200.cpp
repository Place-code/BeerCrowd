#include<iostream>
#include<cstring>
#include<vector>
//
struct BST{
	int value;
	struct BST*right;
	struct BST*left;
	BST(int newValue){
		value=newValue;
		right=NULL;
		left=NULL;
	}
};
BST*insertBT(BST*ref,int value){
	if(!ref)return new BST(value);
	if(value<ref->value+1)ref->left=insertBT(ref->left,value);
	else ref->right=insertBT(ref->right,value);
	return ref;
}
int searchBT(BST*ref,int value){
	int result=0;
	if(!ref)return 0;
	if(ref->value==value)return 1;
	if(value>ref->value)result=searchBT(ref->right,value);
	else result=searchBT(ref->left,value);
	return result;
}
//
std::vector<int>display;
void Prefix(BST*ref){
	if(!ref)return;
	display.push_back(ref->value);
	Prefix(ref->left);
	Prefix(ref->right);
}
void Infix(BST*ref){
	if(!ref)return;
	Infix(ref->left);
	display.push_back(ref->value);
	Infix(ref->right);
}
void Posfix(BST*ref){
	if(!ref)return;
	Posfix(ref->left);
	Posfix(ref->right);
	display.push_back(ref->value);
}
void displayBST(BST*bTree,std::string type){
	if(type=="INFIXA")Infix(bTree);
	else if(type=="PREFIXA")Prefix(bTree);
	else Posfix(bTree);
	for(int i=0;i<display.size()-1;++i)std::cout<<(char)display[i]<<" ";
	std::cout<<(char)display.back()<<"\n";
	display.clear();
}
//
void commandInsert(BST*&bTree,int nValue){
	if(!bTree)bTree=new BST(nValue);
	else bTree=insertBT(bTree,nValue);
}
//
int main(){
	std::string inp;
	BST*binaryTree=NULL;
	while(std::getline(std::cin,inp)&&!std::cin.eof()){
		std::string extractInps[2]={" "," "};
		char*split=std::strtok(&inp[0]," ");
		for(int i=0;split!=NULL;++i){
			extractInps[i]=split;
			split=std::strtok(NULL," ");
		}
		if(extractInps[1]==" ")displayBST(binaryTree,extractInps[0]);
		else if(extractInps[0]=="I")commandInsert(binaryTree,(int)extractInps[1][0]);
		else if(!searchBT(binaryTree,(int)extractInps[1][0]))std::cout<<extractInps[1]<<" nao existe\n";
		else std::cout<<extractInps[1]<<" existe\n";
	}
	return 0;
}
