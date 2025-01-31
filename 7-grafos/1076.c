#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//
int steps,*explored,**matrix;
void dfs(int actualVertice){
	for(int i=0;i<4;++i){
		int temp=matrix[actualVertice][i];
		if(temp==-1)break;
		if(explored[temp])continue;
		if(!explored[temp]){
			explored[temp]=1;
			dfs(temp);
			++steps;
		}
	}
	++steps;
}
//
int main(){
	int r;
	scanf("%i",&r);
	for(r;r>0;--r){
		int init,v,e,c;
		scanf("%i",&init);
		while((c=getchar())!='\n'&&c!=EOF){}
		scanf("%i %i",&v,&e);
		matrix=(int**)malloc(sizeof(int*)*v);
		for(int i=0;i<v;++i){
			matrix[i]=(int*)malloc(sizeof(int)*4);
			for(int j=0;j<4;++j)matrix[i][j]=-1;
		}
		for(int i=0;i<e;++i){
			int vs[2];
			scanf("%i %i",&vs[0],&vs[1]);
			while((c=getchar())!='\n'&&c!=EOF){}
			for(int j=0;j<4;++j){
				if(matrix[vs[0]][j]==vs[1])break;
				if(matrix[vs[0]][j]==-1){
					matrix[vs[0]][j]=vs[1];
					break;
				}
			}
			for(int j=0;j<4;++j){
				if(matrix[vs[1]][j]==vs[0])break;
				if(matrix[vs[1]][j]==-1){
					matrix[vs[1]][j]=vs[0];
					break;
				}
			}
		}
		steps=0;
		explored=calloc(v,sizeof(int));
		explored[init]=1;
		dfs(init);
		printf("%i\n",steps-1);
		free(explored);
		free(matrix);
	}
}
