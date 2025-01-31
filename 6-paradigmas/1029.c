#include<stdio.h>
//
int call=0,repetion=0;
int fibonacci(int x){
	if(x==1|!x){
		(x)?++call:call;
		return 1;
	}
	++repetion;
	return fibonacci(x-1)+fibonacci(x-2);
}
//
int main(){
	int r;
	for(scanf("%i",&r);r>0;--r){
		int fi;
		scanf("%i",&fi);
		if(fi==1){
			printf("fib(1) = 1 calls = 1\n");
		}else{
			fibonacci(fi);
			printf("fib(%i) = %i calls = %i\n",fi,repetion*2,call);
		}
		repetion=call=0;
	}
	return 0;
}
