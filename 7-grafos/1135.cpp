#include<algorithm>
#include<iostream>
#include<limits>
#include<vector>
#include<cmath>
#include<cstdio>
//
std::vector<std::vector<int>>adj_list;
std::vector<int>pathDFS;
unsigned long long*weight;
int*indexs,*isIn;

void dfs(int node){
	if(!isIn[node])return;
	for(int i=0;i<adj_list[isIn[node]-1].size();++i){
	    int vertic=adj_list[isIn[node]-1][i];
		pathDFS.push_back(node);
		if(!indexs[node])indexs[node]=pathDFS.size();
		dfs(vertic);
		pathDFS.push_back(vertic);
        if(!indexs[vertic])indexs[vertic]=pathDFS.size();
	}
}
int**preprocess(std::vector<int>array,int n){
	int**result=(int**)malloc(n*sizeof(int*));
	std::cout<<std::log2(n)<<"\n";
	for(int i=0;i<n;++i){
		result[i]=(int*)malloc((int(std::log2(n))+1)*sizeof(int));
		result[i][0]=i;
	}
	for(int i=1;(1<<i)<n+1;++i){
		for(int j=0;(j+(1<<i)-1)<n;++j){
			if(array[result[j][i-1]]<array[result[j+(1<<(i-1))][i-1]])result[j][i]=result[j][i-1];
			else result[j][i]=result[j+(1<<(i-1))][i-1];
		}
	}
	//std::cout<<"pre\n";
	return result;
}
void commonRMQ(int amountQ,int size){
    indexs=(int*)calloc(size,sizeof(int));
	dfs(0);
	adj_list.clear();
	free(isIn);
	int**min=preprocess(pathDFS,pathDFS.size());
	for(int i=0;i<amountQ;++i){
		int source,destiny,temp,commonVertic,init,end;
		std::scanf("%i %i",&source,&destiny);
		if(indexs[source]>indexs[destiny]){
			destiny+=source;
			source=destiny-source;
			destiny-=source;
        }
		init=indexs[source]-1;
		end=indexs[destiny]-1;
		temp=(int)std::log2(end-init+1);
		(pathDFS[min[init][temp]]<pathDFS[min[end-(1<<temp)+1][temp]]+1)?commonVertic=pathDFS[min[init][temp]]:commonVertic=pathDFS[min[end-(1<<temp)+1][temp]];
		//std::printf("%llu",weight[source]+weight[destiny]-weight[commonVertic]*2);
		//if(i<amountQ-1)std::printf(" ");
		//else std::printf("\n");
	}
	pathDFS.clear();
}
//
int main(){
	int rep;
	while(std::cin>>rep&&rep){
		weight=(unsigned long long*)calloc(rep,sizeof(unsigned long long));
		isIn=(int*)calloc(rep,sizeof(int));
		for(int i=1;i<rep;++i){
		    unsigned long long length;
			int v;
			std::scanf("%i %llu",&v,&length);
			if(!isIn[v]){
				adj_list.push_back(std::vector<int>(0));
				isIn[v]=adj_list.size();
			}
			weight[i]=weight[v]+length;
			adj_list[isIn[v]-1].push_back(i);
		}
		int**queries,amountQ;
		std::cin>>amountQ;
		commonRMQ(amountQ,rep);
	}
	return 0;
}
