// Resulta em resposta errada 45%
#include <iostream>
#include <stdio.h>
using namespace std;
// 
int main()
{
    float inp, res=0;
    char d[2];
    cin>>d[0];
    for(int i=0;i<12;i++){
        for(int j=0;j<12;j++){
            cin>>inp;
            (i>0&&j<i)?res+=inp:res;
        }
    }
    (d[0]=='M')?res/=66:res;
    printf("%.1f\n", res);
}