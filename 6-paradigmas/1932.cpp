#include<iostream>
#include<vector>
//
int main(){
	int days,quote;
	std::scanf("%i %i",&days,&quote);
	int array[days],dp[days];
	for(size_t i=0;i<(size_t)days;++i)
		std::scanf("%i",arrays[i]);
	std::fill(dp,dp+sizeof(dp),-1);

	for(int i=1;i<days;++i){
		dp[i]=std::max(array[i]-dp[i-1],array[i]-array[i-1]);
	}

