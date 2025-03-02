#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
//
struct Node{
	int ID;
	size_t init,end;
	Node(int ID,size_t start,size_t destiny){
		this->ID=ID;
		this->init=start;
		this->end=destiny;
	}
};
bool compar_Node(const Node&a,const Node&b){
	return a.init>b.init;
};
Node cat_node_heap(std::vector<Node>&heap,size_t index){
	Node res=heap[index];
	heap[index]=heap.back();
	heap.pop_back();
	std::make_heap(heap.begin(),heap.end(),compar_Node);

	return res;
}
void insert_node_heap(std::vector<Node>&heap,Node value){
	heap.push_back(value);
	std::push_heap(heap.begin(),heap.end(),compar_Node);
}

int insert_car_length(std::vector<Node>&heap,size_t car_len,size_t max_len,int ID){ 
	if(heap.empty()&&car_len-1<max_len){
		insert_node_heap(heap,Node(ID,0,car_len-1));
		return 1;
	}
	std::vector<Node>copy_heap=heap;
	size_t previous_index=0;
	while(!copy_heap.empty()){
		Node extract=cat_node_heap(copy_heap,0);
		if(extract.init-previous_index>=car_len){
			insert_node_heap(heap,Node(ID,previous_index,previous_index+car_len-1));
			return 1;
		}else if(copy_heap.empty()&&extract.end+car_len<max_len){
			insert_node_heap(heap,Node(ID,extract.end+1,extract.end+car_len));
			return 1;
		}
		previous_index=extract.end+1;
	}
	return 0;
}

int main(){
	int length,cases;
	while(std::cin>>length>>cases){
		std::cin.ignore();

		std::vector<Node>heap;
		int profit=0;
		for(int i=0;i<cases;++i){
			std::string line;
			std::getline(std::cin,line);
			char*token=strtok(&line[0]," "),str[10];
			std::strcpy(str,token);

			int ID,car_length=0;
			token=strtok(NULL," ");
			ID=std::atoi(token);
			token=strtok(NULL," ");

			if(token)
				car_length=std::atoi(token);
			if(!strcmp(str,"C")&&insert_car_length(heap,car_length,length,ID))
					profit+=10;
			if(!strcmp(str,"S")){
				auto it=find_if(heap.begin(),heap.end(),[&heap,&ID](const Node&node){return node.ID==ID;});
				if(it==heap.end())
					continue;
				*it=heap.back();
				heap.pop_back();
				std::make_heap(heap.begin(),heap.end(),compar_Node);
			}
			/*
			for(Node j:heap)
				printf("%i %li %li|",j.ID,j.init,j.end);
			printf("\n");
			*/
		}
		std::printf("%i\n",profit);
	}
	return 0;
}
