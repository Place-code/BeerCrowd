#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;
// 
int main()
{
    string inp;
    float *n=new float[4], m,m1;
    getline(cin,inp);
    char *split=strtok(&inp[0]," ");
    for(int i=0;i<4;i++){
        n[i]=stof(split);
        split=strtok(NULL, " ");
    }
    m=((n[0]*2)+(n[1]*3)+(n[2]*4)+n[3])/10;
    printf("Média: %.1f\n", m);
    fflush(stdout);
    if(m<7&&m>=5){
        cout<<"Aluno em exame."<<endl;
        cin>>m1;
        printf("Nota do exame: %.1f\n",m1);
        fflush(stdout);
        if((m+m1)/2>=5){
            cout<<"Aluno aprovado."<<endl;
        } else{
            cout<<"Aluno reprovado."<<endl;
        }
        printf("Mèdia final: %.1f\n",(m+m1)/2);
        fflush(stdout);
    } else if(m<5){
        cout<<"Aluno reprovado."<<endl;
    } else{
        cout<<"Aluno aprovado."<<endl;
    }
    return 0;
}