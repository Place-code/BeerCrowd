#include<iostream>
//
int seventyFive(std::string parameter){
	int lengthString=0,presence=0;
	for(const char analyse:parameter){
		if(analyse=='M')continue;
		++lengthString;
		(analyse=='P')?++presence:presence;
	}
	return (double)presence/(double)lengthString>=0.75;
}
//
int main(){
	int r;
	for(std::cin>>r;r>0;--r){
		int amountReps,amountFalse=0;
		std::cin>>amountReps;
		int frequency[amountReps]={};
		std::string pupil[amountReps];
		for(int i=0;i<amountReps;++i)std::cin>>pupil[i];
		for(int i=0;i<amountReps;++i){
			std::string temp;
			std::cin>>temp;
			frequency[i]=seventyFive(temp);
			(!frequency[i])?++amountFalse:amountFalse;
		}
		int index=0;
		if(!amountFalse){
			std::cout<<"\n";
			continue;
		}
		for(int i=0,tot=0;i<amountReps;++i){
			if(!frequency[i]&&tot<amountFalse-1){
				std::cout<<pupil[i]<<" ";
				++tot;
			}
			(!frequency[i])?index=i:index;
		}
		std::cout<<pupil[index]<<"\n";
	}
	return 0;
}
