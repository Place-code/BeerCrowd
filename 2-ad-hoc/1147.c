#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//
int main(){
    char*inp;
    int**tabuleiro,*cavalo,*movis;
    for(int cont=1;;++cont){
        for(int i=0;i<9;++i){
            inp=(char*)malloc(3*sizeof(char));
            scanf("%s",inp);
            if(inp[0]=='0')
                break;
            if(i==0){
                cavalo=(int*)malloc(2*sizeof(int));
                cavalo[0]=inp[0]-'0'-1;
                cavalo[1]=(int)inp[1]-97;
                tabuleiro=(int**)malloc(8*sizeof(*tabuleiro));
                for(int j=0;j<8;++j){
                    tabuleiro[j]=(int*)calloc(8,sizeof(**tabuleiro));
                }
            } else if(inp[0]-'0'>1){
                (int)inp[1]-96<=7?tabuleiro[inp[0]-'0'-2][(int)inp[1]-96]=1:tabuleiro[0][0];
                (int)inp[1]-98>=0?tabuleiro[inp[0]-'0'-2][(int)inp[1]-98]=1:tabuleiro[0][0];
            }
            free(inp);
        }
        if(inp[0]=='0')
            break;
        movis=(int*)calloc(1,sizeof(*movis));
        for(int i=0;i<2;++i){
            if(cavalo[0]+2-i<=7){
                (tabuleiro[cavalo[0]+2-i][cavalo[1]+1+i]==0&&cavalo[1]+1+i<=7)?++*movis:*movis;
                (tabuleiro[cavalo[0]+2-i][cavalo[1]-1-i]==0&&cavalo[1]-1-i>=0)?++*movis:*movis;
            }
            if(cavalo[0]-2+i>=0){
                (tabuleiro[cavalo[0]-2+i][cavalo[1]+1+i]==0&&cavalo[1]+1+i<=7)?++*movis:*movis;
                (tabuleiro[cavalo[0]-2+i][cavalo[1]-1-i]==0&&cavalo[1]-1-i>=0)?++*movis:*movis;
            }
        }
        printf("Caso de Teste #%i: %i movimento(s).\n",cont,*movis);
        free(movis);
        free(tabuleiro);
    }
    return 0;
}