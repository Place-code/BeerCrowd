#include<iostream>
#include<vector>
//
std::vector<std::vector<int>>adj;
int graph[3],*amountFriends,*explored;
void subtract(int node){
	//std::cout<<node<<" ";
	for(const int vertices:adj[node]){
		--amountFriends[vertices];
		if(amountFriends[vertices]<graph[2]&&!explored[vertices]){
			explored[vertices]=1;
			subtract(vertices);
		}
	}
}
//
int main(){
	while(std::cin>>graph[0]>>graph[1]>>graph[2]){
		adj.resize(graph[0]+10,{});
		amountFriends=(int*)calloc(graph[0]+10,sizeof(int));
		for(int i=0;i<graph[1];++i){
			int v1,v2;
			std::cin>>v1>>v2;
			adj[v1-1].push_back(v2-1);
			adj[v2-1].push_back(v1-1);
			++amountFriends[v1-1];
			++amountFriends[v2-1];
		}
		explored=(int*)calloc(graph[0],sizeof(int));
		for(int i=0;i<graph[0];++i){
			if(amountFriends[i]<graph[2]&&!explored[i]){
				explored[i]=1;
				subtract(i);
			}
		}
		//std::cout<<"OK\n";
		int amountTrues=0;
		for(int i=0;i<graph[0];++i)(!explored[i])?++amountTrues:amountTrues;
		adj.clear();
		if(!amountTrues){
			std::cout<<"0\n";
			continue;
		}
		int index=0;
		for(int i=0,cont=0;i<graph[0];++i){
			if(!explored[i]&&cont<amountTrues-1){
				std::cout<<i+1<<" ";
				++cont;
			}
			(!explored[i])?index=i:index;
		}
		std::cout<<index+1<<"\n";
	}
	return 0;
}

