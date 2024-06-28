#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
// 
int main()
{
    int r=0;
    cin>>r;
    cin.clear();
    cin.ignore(2147483647,'\n');
    for(int i=0;i<r;i++){
        auto cripi = [](string cifra)->int{
            string trem;
            for(char i:cifra){
                bool verd=(isalpha(i))?true:false;
                if(verd){
                    auto ascii=int(i);
                    ascii+=3;
                    trem+=char(ascii);
                } else{
                    trem+=i;
                }
            }
            int tam=trem.length();
            for(int i=0;i<int(tam/2);i++){
                char trans=trem[i];
                trem[i]=trem[(tam-i-1)];
                trem[(tam-i-1)]=trans;
            }
            for(int i=int(tam/2);i<tam;i++){
                auto ascii=int(trem[i]);
                ascii-=1;
                trem[i]=char(ascii);
            }
            cout<<trem<<endl;
            return 0;
        };
        string ci;
        getline(cin,ci);
        // 
        // cin.clear();
        // cin.ignore(2147483647,'\n');
        // 
        cripi(ci);
    }
    return 0;
}