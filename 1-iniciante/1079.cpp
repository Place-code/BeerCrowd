#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

int main(){
    string inp_str, r;
    getline(cin,r);
    for(int i=0;i<stoi(r);i++){
        float m_p[3]={0,0,0},m_t=0;
        getline(cin,inp_str);
        char*split=strtok(&inp_str[0]," ");
        for(int j=0;j<3;j++){
            m_p[j]=stof(split);
            split=strtok(NULL," ");
        }
        m_p[0]*=2;
        m_p[1]*=3;
        m_p[2]*=5;
        for(int j=0;j<sizeof(m_p)/sizeof(int);j++){
            m_t+=m_p[j];
        }
        m_t/=10.0;
        printf("%3.1f%",m_t);
        cout<<"\n";
    }
    return 0;
}