#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
//
int*quotes,*array;
void fill_array(int profit,size_t current_index,size_t max_len,int price){
	if(profit<0)
		return;
	if(array[current_index])
		return;

	for(size_t i=current_index;i<max_len-1;++i){
		printf("%i|",array[i]);
		for(size_t j=i+1;j<max_len;++j){
			for(size_t k=j+1;k<max_len;++k){
				fill_array(quotes[j]-quotes[i]+profit-price,k,max_len,price);
			}
		}
		printf("\n");
	}
	if(array[current_index]<profit){
		array[current_index]=profit;
	}
}
int main(){
	int days,price;
	std::scanf("%i %i",&days,&price);

	quotes=(int*)malloc(sizeof(int)*days);
	array=(int*)malloc(sizeof(int)*days);
	memset(array,0,sizeof(int)*days);

	for(size_t i=0;i<(size_t)days;++i){
		int temp;
		scanf("%i",&temp);
		quotes[i]=temp;
	}
	fill_array(0,0,days,price);
	for(size_t i=0;i<(size_t)days;++i)
		std::printf("%i ",array[i]);
	printf("\n");
	return 0;
}

