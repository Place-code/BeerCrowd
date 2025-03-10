#include<stdio.h>
#include<string.h>
//
int main(){
	int r;
	for(scanf("%i",&r);r>0;--r){
		char str1[55],str2[55];
		scanf("%s %s",str1,str2);
		for(size_t i=0;i<(strlen(str1)>strlen(str2)?strlen(str1):strlen(str2));++i){
			if(i<strlen(str1))
				printf("%c",str1[i]);
			if(i<strlen(str2))
				printf("%c",str2[i]);
		}
		printf("\n");
	}

	return 0;
}
