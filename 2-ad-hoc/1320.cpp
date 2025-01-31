#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
//
//Nem com tempo de 3s isso passa :(
//
int start,end,*storeT,*storeQ;
int inRange(int lengthStore){
	int modEnd=(end<0)?end*-1:end;
	std::vector<int>in;
	std::queue<int>fila;
	fila.push(start);
	while(!fila.empty()){
		if(std::find(in.begin(),in.end(),fila.front())!=in.end()){
			fila.pop();
			continue;
		}
		in.push_back(fila.front());
		std::cout<<fila.front()<<" ";
		for(int i=0;i<lengthStore;++i){
			if(storeT[i]*2-fila.front()==end)return 1;
			int deli=storeT[i]*2-fila.front();
			(deli<0)?deli*=-1:deli;
			if(std::find(in.begin(),in.end(),storeT[i]*2-fila.front())!=in.end()|deli>modEnd)continue;
			fila.push(storeT[i]*2-fila.front());
			std::cout<<storeT[i]*2-fila.front()<<"|";
		}
		fila.pop();
	}
	return 0;
}
//
int main(){
	int t,q;
	while(std::cin>>t>>q&&t&&q){
		storeT=(int*)malloc(sizeof(int)*t);
		for(int i=0;i<t;++i){
			int temp;
			std::cin>>temp;
			storeT[i]=temp;
		}
		storeQ=(int*)malloc(sizeof(int)*q);
		for(int i=0;i<q;++i){
			std::cin>>start>>end;
			storeQ[i]=inRange(t);
		}
		for(int i=0;i<q-1;++i){
			if(storeQ[i])std::cout<<"Y ";
			else std::cout<<"N ";
		}
		if(storeQ[q-1])std::cout<<"Y\n";
		else std::cout<<"N\n";
	}
	return 0;
}
