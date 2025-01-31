#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<limits>
//
auto compare=[](std::pair<int,int>&a,std::pair<int,int>&b){
	return a.second>b.second;
};
std::vector<std::vector<int>>matrix;
int origin,destiny;
int Dijkstra(){
	std::vector<int>time(matrix.size(),std::numeric_limits<int>::max());
	time[origin]=0;
	std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>,decltype(compare)>fila(compare);
	fila.push({origin,0});
	while(!fila.empty()){
		std::pair<int,int>analyse=fila.top();
		//std::cout<<"|"<<analyse.first<<" "<<analyse.second<<"|";
		fila.pop();
		if(analyse.second>time[destiny])return time[destiny];
		for(int i=0;i<matrix.size();++i){
			if(matrix[analyse.first][i]==-1)continue;
			//std::cout<<i<<" "<<matrix[analyse.first][i]<<"/";
			if(analyse.second+matrix[analyse.first][i]<time[i]){
				time[i]=analyse.second+matrix[analyse.first][i];
				if(i!=destiny)fila.push({i,time[i]});
			}
		}
	}
	return time[destiny];
}
//
int main(){
	int vertices,edge;
	while(std::cin>>vertices>>edge&&(vertices|edge)){
		matrix.resize(vertices,{});
		for(int i=0;i<vertices;++i)matrix[i].resize(vertices,-1);
		for(int i=0;i<edge;++i){
			int v1,v2,hours;
			std::cin>>v1>>v2>>hours;
			matrix[v1-1][v2-1]=hours;
			if(matrix[v2-1][v1-1]!=-1){
				matrix[v1-1][v2-1]=0;
				matrix[v2-1][v1-1]=0;
			}
		}
		int rep;
		for(std::cin>>rep;rep>0;--rep){
			std::cin>>origin>>destiny;
			--origin;
			--destiny;
			int di=Dijkstra();
			if(di==2147483647)std::cout<<"Nao e possivel entregar a carta\n";
			else std::cout<<di<<"\n";
		}
		std::cout<<"\n";
		matrix.clear();
	}
	return 0;
}
