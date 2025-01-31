#include<iostream>
#include<vector>
#include<iomanip>
//
std::vector<bool>eratosthele;
void Sieve(int lenght){
	for(int i=2;i*i<lenght+1;++i)
		if(eratosthele[i])
			for(int j=i*i;j<lenght+1;j+=i)eratosthele[j]=false;	
}

double factorial(double n){
	if(n==1)return n;
	return n*factorial(n-1);
}
//
int main(){
	int r,*analyse,biggest=0;
	std::cin>>r;
	analyse=(int*)malloc(sizeof(analyse)*r);
	for(int i=0;i<r;++i){
		std::cin>>analyse[i];
		if(analyse[i]>biggest)biggest=analyse[i];
	}
	eratosthele.resize(biggest+1);
	std::fill(eratosthele.begin(),eratosthele.end(),true);
	eratosthele[0]=eratosthele[1]=false;
	Sieve(biggest);
	for(int i=0;i<r;++i){
		if(eratosthele[analyse[i]]){
			std::cout<<analyse[i]<<"! = "<<std::fixed<<std::setprecision(0)<<factorial(analyse[i])<<"\n";
		}
	}
}
