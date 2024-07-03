#include <iostream>
#include <vector>
using namespace std;
// 
// 
int main()
{
    while(true){
        int n=0,par=0, andar=0;
        bool para=false;
        vector<int> mm;
        cin>>n;
        if(n==0){ 
            break;
        } else{
            while(true){
                for(int i=0;i<n;i++){
                    mm.push_back(i+1);
                }
                for(int i=0;i<n;i++){
                    if(i==n-1 && mm[andar]==13){
                        para=true;
                        break;
                    } else if(i!=n-1 && mm[andar]==13){
                        break;
                    }
                    mm.erase(mm.begin()+andar);
                    for(int j=0;j<par;j++){
                        andar+=1;
                        (andar>=mm.size())?andar-=mm.size():0;
                    }
                }
                if(para==false){
                    par+=1;
                }else{
                    break;
                }
                mm.clear();
                andar=0;
            }
            ++par;
            cout<<par<<endl;
            n=0;
        }
    }
    return 0;
}