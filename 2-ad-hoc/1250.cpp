#include<iostream>
//
int main(){
	int tst;
	for(scanf("%i",&tst);tst;--tst){
		int rep;
		scanf("%i",&rep);
		int height[rep],jump[rep];
		for(int i=0;i<rep;++i)
			scanf("%i ",&height[i]);

		char str[rep];
		scanf("%s",str);
		for(size_t i=0;i<rep;++i)
			jump[i]=(int)str[i];

		int tot=0;
		for(size_t i=0;i<rep;++i){
			if(height[i]>2&&jump[i]==(int)'J')
				++tot;
			if(height[i]<3&&jump[i]==(int)'S')
				++tot;
		}
		printf("%i\n",tot);
	}
	return 0;
}
