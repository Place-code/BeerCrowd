#include<iostream>
#include<vector>
#include<queue>
//
void clear_queue(std::queue<int>&fila){
	std::queue<int>empty;
	std::swap(fila,empty);
}
void fill_array_BFS(int init,int*receiver,std::vector<std::vector<int>>graph){
	receiver[init]=0;
	int length=1;
	std::queue<int>fila({init}),temp;
	while(!fila.empty()){
		for(int v:graph[fila.front()]){
			if(receiver[v]!=-1)
				continue;
			temp.push(v);
			receiver[v]=length;
		}
		fila.pop();
		if(fila.empty()){
			fila=temp;
			clear_queue(temp);
			++length;
		}
	}
}
void min_both_length_BFS(int&current_len,int*length_a,int*length_b,std::vector<std::vector<int>>graph){
	std::queue<int>fila({current_len}),aux;
	while(!fila.empty()){
		for(int v:graph[fila.front()]){
			if(length_a[v]<length_a[current_len]&&length_b[v]<length_b[current_len]){
				current_len=v;
				aux.push(v);
			}
		}
		fila.pop();
		if(fila.empty()){
			fila=aux;
			clear_queue(aux);
		}
	}
}

int main(){
	int vertics,join,hotel_i,hotel_e;
	while(std::cin>>vertics>>join>>hotel_i>>hotel_e){
		std::vector<std::vector<int>>graph(vertics,std::vector<int>(0));
		--join;
		--hotel_i;
		--hotel_e;
		for(int i=0;i<vertics-1;++i){
			int v1,v2;
			std::cin>>v1>>v2;
			//std::printf("%i %i %i\n",i+1,v1,v2);
			graph[v1-1].push_back(v2-1);
			graph[v2-1].push_back(v1-1);
		}
		int explored_hotel_i[vertics],
			explored_hotel_e[vertics];
		for(int i=0;i<vertics;++i){
			explored_hotel_i[i]=-1;
			explored_hotel_e[i]=-1;
		}
		/*
		for(int i=0;i<vertics;++i){
			if(graph[i].size()<2)
				continue;
			printf("%i->",i);
			for(int v:graph[i])
				std::printf("%i ",v);
			std::printf("\n");
		}
		*/

		fill_array_BFS(hotel_i,explored_hotel_i,graph);
		fill_array_BFS(hotel_e,explored_hotel_e,graph);
		min_both_length_BFS(join,explored_hotel_i,explored_hotel_e,graph);

		if(!explored_hotel_i[join]){
			std::printf("1.000000\n");
			continue;
		}else if(!explored_hotel_e[join]){
			std::printf("0.000000\n");
			continue;
		}

		int path_hotel_i=explored_hotel_i[join],
			path_hotel_e=explored_hotel_e[join];
		std::printf("%.6lf\n",1.0-(1.0/((double)path_hotel_i+(double)path_hotel_e))*(double)path_hotel_i);
	}
	return 0;
}
