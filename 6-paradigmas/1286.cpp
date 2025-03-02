#include<iostream>
#include<string.h>
//
int main(){
	int num;
	while(std::scanf("%i",&num)&&num){
		int max_weig;
		std::scanf("%i",&max_weig);
		int array[num+1][max_weig+1];
		for(size_t i=0;i<num+1;++i)
			memset(array[i],0,sizeof(array[i]));
		for(size_t i=0;i<num;++i){
			int pizza,time;
			scanf("%i %i",&time,&pizza);
			for(size_t j=0;j<max_weig+1;++j){
				if(j<pizza){
					array[i+1][j]=array[i][j];
					continue;
				}
				int max=0;
				if(array[i][j]<array[i][j-pizza]+time)
					max=array[i][j-pizza]+time;
				else
					max=array[i][j];
				array[i+1][j]=max;
			}
		}
		printf("%i min.\n",array[num][max_weig]);
	}
}
