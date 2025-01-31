#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<math.h>
//
int storeDigits[10][10],digitA[10],digitB[10],lengthA,lengthB;
void splitNum(int storeResult[],int number,int*length){
	*length=0;
	for(int i=0;number;++i,++*length){
		storeResult[i]=number%10;
		number/=10;
	}
}
int regenerateNum(int index,int storeNum[]){
	int resp=0;
	for(int i=0;i<index+1;++i)resp+=storeNum[i]*pow(10,i);
	return resp;
}
int minusZeros(int size){
	int result=0;
	for(int i=0;i<size+1;++i)result+=pow(10,i);
	return result-1;
}
int*interval(int tight,int index,int digit,int storeNum[]){
	if(index<0){
		int*rest=(int*)calloc(10,sizeof(int));
		return rest;
	}
	if(storeDigits[index][digit]&&!tight)return storeDigits[index];
	int rep=(tight)?storeNum[index]:9,*amountDigits=(int*)calloc(10,sizeof(int));
	for(int i=0;i<rep+1;++i){
		int newTight=(i==storeNum[index])?tight:0;
		int*temp=interval(newTight,index-1,i,storeNum);
		for(int j=0;j<10;++j)amountDigits[j]+=temp[j];
		(!newTight)?amountDigits[i]+=pow(10,index):(newTight)?amountDigits[i]+=regenerateNum(index-1,storeNum)+1:amountDigits[i];
	}
	for(int i=0;i<10&&!tight&&!storeDigits[index][9];++i)storeDigits[index][i]=amountDigits[i];
	return amountDigits;
}
//
int main(){
	int a,b;
	memset(storeDigits,0,sizeof(storeDigits));
	while(scanf("%i %i",&a,&b)&&(a||b)){
		memset(digitB,0,sizeof(digitB));
		splitNum(digitB,b,&lengthB);
		int*tempB=interval(1,lengthB-1,0,digitB);
		(lengthB>1)?tempB[0]-=minusZeros(lengthB-1):tempB[0];
		//
		memset(digitA,0,sizeof(digitA));
		splitNum(digitA,a-1,&lengthA);
		(!lengthA)?lengthA=1:lengthA;
		int*tempA=interval(1,lengthA-1,0,digitA);
		(lengthA>1)?tempA[0]-=minusZeros(lengthA-1):tempA[0];
		//
		for(int i=0;i<9;++i)printf("%i ",tempB[i]-tempA[i]);
		printf("%i\n",tempB[9]-tempA[9]);
	}
	return 0;
}
