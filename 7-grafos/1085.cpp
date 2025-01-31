#include<algorithm>
#include<iostream>
#include<limits>
#include<vector>
#include<queue>
#include<map>
//
struct Threesome{
	int id[3];
	Threesome(int v1,int v2,int v3){
		id[0]=v1;
		id[1]=v2;
		id[2]=v3;
	}
	//
	int first(){return id[0];}
	int second(){return id[1];}
	int third(){return id[2];}
};

auto compare=[](Threesome&a,Threesome&b){
	return a.second()>b.second();
};

std::map<std::string,int>translateV;
std::vector<std::vector<int>>list_adj,weightV,weightI;

int Dijkstra(){
	std::priority_queue<Threesome,std::vector<Threesome>,decltype(compare)>fila(compare);
	//
	int*minVertic=(int*)malloc(list_adj.size()*sizeof(int)),**minEdge=(int**)malloc(list_adj.size()*sizeof(int*));//,**explored=(int**)malloc(list_adj.size()*sizeof(int*));
	std::fill(minVertic,minVertic+list_adj.size(),std::numeric_limits<int>::max());
	for(int i=0;i<list_adj.size();++i){
		minEdge[i]=(int*)malloc(26*sizeof(int));
		//explored[i]=(int*)calloc(list_adj[i].size(),sizeof(int));
		std::fill(minEdge[i],minEdge[i]+26,std::numeric_limits<int>::max());
	}
	minVertic[0]=0;
	fila.push(Threesome(0,0,27));
	while(!fila.empty()){
		Threesome auxQ=fila.top();
		if(auxQ.second()>minVertic[1])return minVertic[1];
		fila.pop();
		//std::cout<<auxQ.first()<<"-"<<auxQ.second()<<"-"<<auxQ.third()<<"\n";
		for(int i=0;i<list_adj[auxQ.first()].size();++i){
			int auxVertic=list_adj[auxQ.first()][i],auxWeig=weightV[auxQ.first()][i],auxI=weightI[auxQ.first()][i];
			//std::cout<<auxVertic<<" "<<auxWeig<<" "<<weightI[auxQ.first()][i]<<"|";
			if(auxI==auxQ.third())continue;
			if(minEdge[auxVertic][auxI]>auxQ.second()+auxWeig){
				(auxQ.second()+auxWeig<minVertic[auxVertic])?minVertic[auxVertic]=auxQ.second()+auxWeig:minVertic[auxVertic];
				if(auxVertic!=1)fila.push(Threesome(auxVertic,auxQ.second()+auxWeig,auxI));
				minEdge[auxVertic][auxI]=auxWeig+auxQ.second();
			}
		}
	}
	return minVertic[1];
}
//
int main(){
	int rep;
	while(std::cin>>rep&&rep){
		std::string source,destiny;
		std::cin>>source>>destiny;
		//
		translateV[source]=0;
		list_adj.push_back(std::vector<int>(0));
		weightV.push_back(std::vector<int>(0));
		weightI.push_back(std::vector<int>(0));

		translateV[destiny]=1;
		list_adj.push_back(std::vector<int>(0));
		weightV.push_back(std::vector<int>(0));
		weightI.push_back(std::vector<int>(0));
		//
		for(int i=0;i<rep;++i){
			std::string v1,v2,edge;
			std::cin>>v1>>v2>>edge;
			//
			std::cin.clear();
			std::cin.ignore(2147483647,'\n');
			//
			if(translateV.find(v1)==translateV.end()){
				translateV[v1]=translateV.size();
				list_adj.push_back(std::vector<int>(0));
				weightV.push_back(std::vector<int>(0));
				weightI.push_back(std::vector<int>(0));
			}
			if(translateV.find(v2)==translateV.end()){
				translateV[v2]=translateV.size();
				list_adj.push_back(std::vector<int>(0));
				weightV.push_back(std::vector<int>(0));
				weightI.push_back(std::vector<int>(0));
			}
			int indV1=translateV[v1],indV2=translateV[v2];
			list_adj[indV1].push_back(indV2);
			list_adj[indV2].push_back(indV1);
			//
			weightV[indV1].push_back(edge.length());
			weightV[indV2].push_back(edge.length());
			//
			weightI[indV1].push_back((int)edge[0]-97);
			weightI[indV2].push_back((int)edge[0]-97);
		}
		int result=Dijkstra();
		if(result==2147483647)std::cout<<"impossivel\n";
		else std::cout<<result<<"\n";
		//
		translateV.clear();
		list_adj.clear();
		weightV.clear();
		weightI.clear();
	}
	return 0;
}
