#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    string valor;
    double n[2][3],tot;
    int e[2]={0,0};
    for(int i=0;i<2;i++){
        getline(cin,valor);
        char * split = split = strtok(&valor[0]," ");;
        while(split!= NULL)
        {
            n[e[0]][e[1]] = stof(split);
            split = strtok(NULL," ");
            ++e[1];
            if(e[1]>2){
                e[1]=0;
                ++e[0];
            }
        }
    }
    tot = n[0][1]*n[0][2]+n[1][1]*n[1][2];
    cout<<"VALOR A PAGAR: R$ ";
    printf("%5.2f%n",tot);
    cout<<"\n";
    return 0;
}