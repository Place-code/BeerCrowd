#include<iostream>
#include<cstring>
#include <math.h>
using namespace std;

int main()
{
    while(true){
        string inp;
        int *p[3];
        float *h;
        getline(cin,inp);
        char *split=strtok(&inp[0]," ");
        if(split==NULL){
            break;
        } else{
            for(int i=0;i<=2;i++){
                p[i]=new int;
                *p[i]=stoi(split);
                split=strtok(NULL," ");
            }
            h= new float;
            *h=pow((pow(*p[0],2)+144),0.5);
            if(*h/ *p[2]<=12.0/ *p[1]){
                cout<<"S";
            } else{
                cout<<"N";
            }
        }
        cout<<"\n";
    }
    // cout<<"\n";
    return 0;
}