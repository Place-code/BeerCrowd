#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
// 
int main()
{
    int r;
    cin>>r;
    // 
    cin.clear();
    cin.ignore(2147483647,'\n');
    // 
    for(int i=0;i<r;i++){
        string num;
        getline(cin,num);
        int prin=0;
        auto leds=[num]()->int
        { 
            int luz=0;
            for(char j:num){
                int p=j-'0';
                (p==1)?luz+=2:(p==2|p==3|p==5)?luz+=5:(p==4)?luz+=4:(p==6|p==9|p==0)?luz+=6:(p==7)?luz+=3:luz+=7;
            }
            return luz;
        };
        prin=leds();
        cout<<prin<<" leds"<<endl;
    };
    cout<<"\n";
    return 0;
}
    