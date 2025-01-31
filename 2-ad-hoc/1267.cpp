#include<iostream>
//
int**matrix,x,y;
int check(){
	for(int i=0;i<x;++i){
		int temp=1;
		for(int j=0;j<y;++j)temp=(!matrix[j][i])?0:temp;
		if(temp)return 1;
	}
	return 0;
}
//
int main(){
	while(std::cin>>x>>y&&x&&y){
		matrix=(int**)malloc(y*sizeof(int*));
		for(int i=0;i<y;++i){
			matrix[i]=(int*)malloc(x*sizeof(int));
			for(int j=0;j<x;++j){
				int temp;
				std::cin>>temp;
				matrix[i][j]=temp;
			}
		}
		if(check())std::cout<<"yes\n";
		else std::cout<<"no\n";
		free(matrix);
	}
	return 0;
}
