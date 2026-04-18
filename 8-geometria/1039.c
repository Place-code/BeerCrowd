#include<math.h>
#include<stdio.h>
#include<string.h>
//
int module(int x,int y){
	if(x<y)return y-x;
	return x-y;
}

int main(){
	int hunter[3],flower[3];
	while(scanf("%i %i %i %i %i %i",&hunter[0],&hunter[1],&hunter[2],&flower[0],&flower[1],&flower[2])!=EOF){
		double d=pow(pow(module(hunter[1],flower[1]),2)+pow(module(hunter[2],flower[2]),2),0.5);
		if((double)hunter[0]>=d+(double)flower[0])printf("RICO\n");
		else printf("MORTO\n");
	}
	return 0;
}
