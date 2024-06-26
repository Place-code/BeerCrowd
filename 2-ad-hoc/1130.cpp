
#include <iostream>
#include <string>
using namespace std;

int main(){
    int x=1;
    cin>>x;
    while(x!=0){
        string jogo;
        cin>>jogo;
        int xs[2]={0,0},e=0;
        for(int i=0;i<jogo.length();i++){
            if(jogo[i]=='X'){
                xs[e]=i;
                ++e;
            }
            if(xs[1]!= 0){
                // cout<<xs[0]<<" "<<xs[1]<<endl;
                if(xs[1]-xs[0]<=2){
                    cout<<"S"<<endl;
                    break;
                } else{
                    xs[0]=xs[1];
                    xs[1]=0;
                }
                --e;
            }
            // cout<<jogo[i]<<endl;
        }
        cin>>x;
    }
}