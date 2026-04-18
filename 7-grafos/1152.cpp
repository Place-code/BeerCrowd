#include<queue>
#include<iostream>
//

struct node{
	int v1;
	int v2;
	int wg;
	node(int array[]){
		this->v1=array[0];
		this->v2=array[1];
		this->wg=array[2];
	};
};
auto compare=[](struct node&a,struct node&b){
	return a.wg>b.wg;
};

int find_cycle(int v,int*parent){
	if(parent[v]!=v){
		parent[v]=find_cycle(parent[v],parent);
	}
	return parent[v];
}
int umus(int v1,int v2,int*parent,int*rank){
	int rv1=find_cycle(v1,parent),rv2=find_cycle(v2,parent);

	if(rv1==rv2)return 0;
	if(rank[rv1]<rank[rv2]){
		parent[rv1]=rv2;
	}else if(rank[rv2]<rank[rv1]){
		parent[rv2]=rv1;
	} else{
		parent[rv2]=rv1;
		++rank[rv1];
	}
	return 1;
}

int main(){
	int vertic,edges;
	while(std::cin>>vertic>>edges&&vertic&&edges){
		std::priority_queue<struct node,std::vector<struct node>,decltype(compare)>kiwi(compare);
		int tot_size=0;
		for(int i=0;i<edges;++i){
			int array[3];
			std::cin>>array[0]>>array[1]>>array[2];
			struct node temp=node(array);
			kiwi.push(temp);
			tot_size+=array[2];
		}
		int parent[vertic],rank[vertic],safe_money=0;
		for(size_t i=0;i<vertic;++i){
			parent[i]=i;
			rank[i]=i;
		}
		while(!kiwi.empty()){
			struct node get=kiwi.top();
			kiwi.pop();
			if(!umus(get.v1,get.v2,parent,rank))continue;
			safe_money+=get.wg;
		}
		std::printf("%i\n",tot_size-safe_money);
	}
	return 0;
}
