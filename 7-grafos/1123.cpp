#include<iostream>
#include<vector>
#include<utility>
#include<queue>
//
int main(){
	for(;;){
		int init[4],inps[3];	
		std::cin>>init[0]>>init[1]>>init[2]>>init[3];
		if(init[0]==0)
				break;
		std::vector<std::vector<int>>list_adj(init[0]),weight_rounds(init[0]);
		std::vector<int>weight(init[0],-1);
		for(int i=0;i<init[1];++i){
			std::cin>>inps[0]>>inps[1]>>inps[2];
			//
			list_adj[inps[0]].push_back(inps[1]);
			list_adj[inps[1]].push_back(inps[0]);
			//
			weight_rounds[inps[0]].push_back(inps[2]);
			weight_rounds[inps[1]].push_back(inps[2]);
		}
		weight[init[3]]=0;
		std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>,std::greater<std::pair<int,int>>>fila;
		fila.push({0,init[3]});
		--init[2];
		while(!fila.empty()){	
			int new_int=fila.top().second,e=0;
			fila.pop();
			for(int analysis:list_adj[new_int]){
				if(weight[analysis]>weight[new_int]+weight_rounds[new_int][e]|weight[analysis]==-1){
					if(new_int>init[2]|analysis==new_int+1)						
						weight[analysis]=weight[new_int]+weight_rounds[new_int][e];
					if(analysis!=init[2]&&(new_int>init[2]|analysis==new_int+1)){
						fila.push({weight[analysis],analysis});
					}
				}
				++e;
			}
		}
		std::cout<<weight[init[2]]<<"\n";
	}
}
