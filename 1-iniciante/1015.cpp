#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;

int main(){
    string inp_str;
    float n[2][2];
    float tot;
    for(int i=0;i<2;i++){
        getline(cin,inp_str);
        char *split = strtok(&inp_str[0]," ");
        for(int j=0;j<2;j++){
            n[i][j]=stof(split);
            split=strtok(NULL," ");
        }
    }
    tot = pow((n[1][0]-n[0][0]),2)+pow((n[1][1]-n[0][1]),2);
    if (tot<0){
        tot*=-1;
    }
    printf("%5.4f%n",pow(tot,0.5));
    return 0;
}