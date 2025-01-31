#include<iostream>
#include<cstring>
#include<cmath>
//
int store[10][10]={},digitsA[10],digitsB[10],lengthA,lengthB;
void splitNumber(int x,int receiver[],int&storeLength){
	storeLength=0;
	while(x){
		receiver[storeLength]=x%10;
		x/=10;
		++storeLength;
	}
}
int minusZeros(int lengthNumber){
	int result=0;
	for(int i=0;i<lengthNumber+1;++i)result+=std::pow(10,i);
	return result-1;
}
int regenerateNumber(int storeDigits[],int index){
	int result=0;
	for(int i=0;i<index+1;++i)result+=storeDigits[i]*std::pow(10,i);
	return result;
}
int*interval(int index,int tight,int storeDigits[],int digit){
	if(index<0){
		int*rest=(int*)calloc(10,sizeof(int));
		rest[digit]=1;
		return rest;
	}
	if(store[index][digit]&&!tight)return store[index];
	int rep=(tight)?storeDigits[index]:9,*amountDigits=(int*)calloc(10,sizeof(int));
	for(int i=0;i<rep+1;++i){
		int newTight=(i==storeDigits[index])?tight:0;
		int*temp=interval(index-1,newTight,storeDigits,i);
		for(int j=0;j<10;++j)amountDigits[j]+=temp[j];
		if(newTight&&index)amountDigits[i]+=regenerateNumber(storeDigits,index-1)+1;
		else if(index)amountDigits[i]+=std::pow(10,index);
	}
	for(int i=0;i<10&&!tight;++i)store[index][i]+=amountDigits[i];
	return amountDigits;
}
//
int main(){
	int a,b;
	memset(store,sizeof(store),0);
	while(std::cin>>a>>b&&(a|b)){	
		//
		lengthB=0;
		splitNumber(b,digitsB,lengthB);
		int*tempB=interval(lengthB-1,1,digitsB,0);
		(lengthB>1)?tempB[0]-=minusZeros(lengthB-1):tempB[0];
		splitNumber(a,digitsA,lengthA);
		//
		lengthA=0;
		splitNumber(a-1,digitsA,lengthA);
		int*tempA=interval(lengthA-1,1,digitsA,0);
		(lengthA>1)?tempA[0]-=minusZeros(lengthA-1):tempA[0];
		for(int i=0;i<9;++i)std::cout<<tempB[i]-tempA[i]<<" ";
		std::cout<<tempB[9]-tempA[9]<<"\n";
	}
}
