#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//
int main(){
    char*inp=(char*)calloc(128,sizeof(char)),*aux;
    int r,v_tam;
    scanf("%i",&r);
    getchar();
    for(int i=0;i<r;++i){
        fgets(inp,128,stdin);
        v_tam=strlen(inp)-2;
        for(int i=0;i<v_tam+1;++i){
            if(i<v_tam/2+1)
                aux=&inp[v_tam/2-i];
            else
                aux=&inp[v_tam-(i-v_tam/2-1)];
            printf("%c",*aux);
        }
        printf("\n");
    }
    return 0;
}