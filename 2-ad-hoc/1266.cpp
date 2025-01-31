#include<iostream>
//
int main(){
	for(;;){
		int length,tot=0,cont=0,one=0,temp,index=0;
		std::cin>>length;
		int array[length];
		if(!length)break;
		for(int i=0;i<length;++i){
			std::cin>>temp;
			array[i]=temp;
			(temp&&one)?tot+=cont/2:tot;
			(temp)?one=1:one;
			(temp)?index=i+1:index;
			(!temp)?++cont:cont=0;
		}
		cont=0;
		for(int i=0,analysis;i<length+1;++i){
			analysis=i<length-index?array[index+i]:array[i-length+index];
			if(analysis) break;
			cont+=1;
		}
		tot+=cont/2;
		std::cout<<tot<<"\n";
	}
	return 0;
}
