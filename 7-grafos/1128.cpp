#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
//
int BFS(int init,std::vector<std::vector<int>>graph){
	int explored[graph.size()];
	memset(explored,0,sizeof(explored));
	explored[init]=1;
	std::queue<int>fila;
	fila.push(init);

	int max=0;
	while(!fila.empty()){
		for(int vertic:graph[fila.front()]){
			if(explored[vertic])
				continue;
			fila.push(vertic);
			explored[vertic]=1;
			++max;
		}
		fila.pop();
	}
	return max;
}
void question(std::vector<std::vector<int>>graph){
	for(int i=0;(size_t)i<graph.size();++i){
		int tst=BFS(i,graph);
		if(tst+1<(int)graph.size()){
			printf("0\n");
			return;
		}
	}
	printf("1\n");
}
int main(){
	int vertic,edges;
	while(std::scanf("%i %i",&vertic,&edges)&&vertic&&edges){
		std::vector<std::vector<int>>graph(vertic,std::vector<int>(0));
		for(int i=0;i<edges;++i){
			int v1,v2,unique;
			std::scanf("%i %i %i",&v1,&v2,&unique);
			graph[v1-1].push_back(v2-1);
			if(unique==2)
				graph[v2-1].push_back(v1-1);
		}
		question(graph);
	}
	return 0;
}
