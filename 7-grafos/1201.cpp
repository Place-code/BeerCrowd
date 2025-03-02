#include<iostream>
#include<cstring>
#include<queue>
//
struct Node{
	int root;
	struct Node*left,*right;
	Node(int value){
		this->root=value;
		this->left=nullptr;
		this->right=nullptr;
	}
};
struct Node*create_node(int value_node){
	Node*new_node=(struct Node*)malloc(sizeof(struct Node));
	new_node->root=value_node;
	new_node->left=nullptr;
	new_node->right=nullptr;

	return new_node;
}
void append_BTS(struct Node**tree,int value){
	if(*tree==nullptr){
		(*tree)=create_node(value);
		return;
	}
	if((*tree)->root<value)
		append_BTS(&((*tree)->right),value);
	else
		append_BTS(&((*tree)->left),value);
}
Node*get_last_left(Node*tree){
	if(tree==nullptr||tree->right==nullptr)
		return tree;
	return get_last_left(tree->right);
}
Node*get_successor(Node*current){
	current=current->left;
	return get_last_left(current);
}
void delete_BTS(struct Node**tree,int value){
	if((*tree)==nullptr)
		return;
	if((*tree)->root==value){
		if((*tree)->left==nullptr){
			(*tree)=(*tree)->right;
		}else if((*tree)->right==nullptr){
			(*tree)=(*tree)->left;
		}else{
			Node*suc=get_successor((*tree));
			(*tree)->root=suc->root;
			delete_BTS(&((*tree)->left),suc->root);
		}
		return;
	}

	if((*tree)->root<value)
		delete_BTS(&((*tree)->right),value);
	else 
		delete_BTS(&((*tree)->left),value);
}
int search_BTS(struct Node*tree,int value){
	if(tree==nullptr)
		return 0;
	if(tree->root==value)
		return 1;

	if(tree->root>value)
		return search_BTS(tree->left,value);
	else
		return search_BTS(tree->right,value);
}
void pre_order(struct Node*tree,std::queue<int>&out){
	if(tree==nullptr)
		return;
	out.push(tree->root);
	pre_order(tree->left,out);
	pre_order(tree->right,out);
}
void in_order(struct Node*tree,std::queue<int>&out){
	if(tree==nullptr)
		return;
	in_order(tree->left,out);
	out.push(tree->root);
	in_order(tree->right,out);
}
void post_order(struct Node*tree,std::queue<int>&out){
	if(tree==nullptr)
		return;
	post_order(tree->left,out);
	post_order(tree->right,out);
	out.push(tree->root);
}
void display_queue(std::queue<int>&ref){
	while(ref.size()>1){
		std::printf("%i ",ref.front());
		ref.pop();
	}
	std::printf("%i\n",ref.front());
	ref.pop();
}
void display_order(char*order_type,Node*tree){
	std::queue<int>temp;
	if(!std::strcmp(order_type,"INFIXA"))
		in_order(tree,temp);
	if(!std::strcmp(order_type,"PREFIXA"))
		pre_order(tree,temp);
	if(!std::strcmp(order_type,"POSFIXA"))
		post_order(tree,temp);
	display_queue(temp);
}

int main(){
	std::string line;
	Node*tree=nullptr;
	while(std::getline(std::cin,line)){
		char*token=std::strtok(&line[0]," "),str[100];
		std::strcpy(str,token);
		token=std::strtok(NULL," ");
		if(!token){
			display_order(str,tree);
			continue;
		}
		int value=-1;
		value=std::atoi(token);
		if(!std::strcmp(str,"I"))
			append_BTS(&tree,value);
		if(!std::strcmp(str,"R"))
			delete_BTS(&tree,value);

		if(!std::strcmp(str,"P")&&search_BTS(tree,value))
			std::printf("%i existe\n",value);
		else if(!std::strcmp(str,"P"))
			std::printf("%i nao existe\n",value);
	}
	return 0;
}
