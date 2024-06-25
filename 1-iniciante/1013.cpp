#include <iostream>
#include <cstring>
using namespace std;

int main(){
    int lis_n[3],i=0,palpite=0;
    string inp_str;
    getline(cin,inp_str);
    char * split=strtok(&inp_str[0]," ");
    while (split!=NULL)
    {
        lis_n[i]=stoi(split);
        split = strtok(NULL," ");
        ++i;
    }
    for(int j=0;j<3;j++){
        if (lis_n[j]>palpite){
            palpite=lis_n[j];
        }
    }
    cout<<palpite<<" eh o maior"<<endl;
    return 0;
}