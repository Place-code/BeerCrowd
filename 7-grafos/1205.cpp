#include<algorithm>
#include<iostream>
#include<cstring>
#include<utility>
#include<cstdio>
#include<vector>
#include<queue>
#include<cmath>
//
auto compare=[](std::pair<int,int>&a,std::pair<int,int>&b){
	return a.second<b.second;
};
std::vector<std::vector<int>>listAdj;
int*germans;
int dijkstra(int init,int end,int bullets,int amountVertices){
	std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>,decltype(compare)>fila(compare);
	int amountBullets[amountVertices];
	std::fill_n(amountBullets,amountVertices,-1);
	amountBullets[init]=bullets-germans[init];
	fila.push({init,amountBullets[init]});
	while(!fila.empty()){
		std::pair<int,int>top=fila.top();
		fila.pop();
		if(top.second<amountBullets[end]+1)return amountBullets[end];
		for(const int analyse:listAdj[top.first]){
			if(amountBullets[analyse]<top.second-germans[analyse]){
				amountBullets[analyse]=top.second-germans[analyse];
				if(analyse!=end)fila.push({analyse,amountBullets[analyse]});
			}
		}
	}
	return amountBullets[end];
}
//
int main(){
	int inp[3],index=0;
	float prob;
	while(std::cin>>inp[0]>>inp[1]>>inp[2]>>prob){
		listAdj.resize(inp[0]);
		for(int i=0;i<inp[1];++i){
			int v1,v2;
			std::cin>>v1>>v2;
			listAdj[v1-1].push_back(v2-1);
			listAdj[v2-1].push_back(v1-1);
		}
		germans=(int*)calloc(inp[0],sizeof(int));
		int interval=1;
		std::cin>>interval;
		for(int i=0,temp;i<interval;++i){
			std::cin>>temp;
			++germans[temp-1];
		}
		int init,end;
		std::cin>>init>>end;
		std::printf("%.3lf\n",std::pow(prob,double(inp[2]-dijkstra(init-1,end-1,inp[2],inp[0]))));
		listAdj.clear();	
		free(germans);
		++index;
	}
	return 0;
}
