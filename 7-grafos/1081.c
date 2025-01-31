#include<stdio.h>
#include<stdlib.h>
//
int**matrix,*explored,infos[2];
void dfs(int actualValue,int indentation){
	for(int i=0;i<infos[0];++i){
		if(matrix[actualValue][i]){
			for(int j=0;j<indentation;++j)printf(" ");
			printf("%i-%i",actualValue,i);
			if(!explored[i]){
				printf(" pathR(G,%i)\n",i);
				explored[i]=1;
				dfs(i,indentation+2);
			} else{
				printf("\n");
			}
		}
	}
}

int main(){
	int i,cont=0;
	for(scanf("%i",&i);i>0;--i,++cont){
		scanf("%i %i",&infos[0],&infos[1]);
		matrix=(int**)malloc(infos[0]*sizeof(int*));
		explored=malloc(infos[0]*sizeof(int));
		for(int j=0;j<infos[0];++j){
			matrix[j]=(int*)calloc(infos[0],sizeof(int));
			explored[i]=1;
		}
		for(int j=0;j<infos[1];++j){
			int v1,v2;
			scanf("%i %i",&v1,&v2);
			matrix[v1][v2]=1;
			explored[v1]=explored[v2]=0;
		}
		printf("Caso %i:\n",cont+1);
		for(int j=0;j<infos[0];++j){
			if(explored[j])continue;
			explored[j]=1;
			dfs(j,2);
			printf("\n");
		}
	}
}
