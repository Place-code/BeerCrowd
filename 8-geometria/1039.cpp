#include<cmath>
#include<cstdio>
//
int main(){
	int hunter[3],flower[3];
	while(std::scanf("%i %i %i %i %i %i",&hunter[0],&hunter[1],&hunter[2],&flower[0],&flower[1],&flower[2])!=EOF){
		double d=std::pow(std::pow(hunter[1]-flower[1],2)+std::pow(hunter[2]-flower[2],2),0.5);
		if((double)hunter[0]>=d+flower[0])std::printf("RICO\n");
		else printf("MORTO\n");
	}
	return 0;
}
