#include <iostream>
#include <cstring>
using namespace std;
// 
int main()
{
    int r;
    cin>>r;
    cin.clear();
    cin.ignore(2147483647, '\n');
    for(int i=0;i<r;i++){
        string cesar;
        int trem[2][50], coiso;
        getline(cin,cesar);
        cin>>coiso;
        cin.clear();
        cin.ignore(2147483647, '\n');
        for(int j=0;j<cesar.length();j++){
            int conver=int(cesar[j])-coiso;
            if(conver<65){
                coiso=int(cesar[j])-int(cesar[j]-coiso);
                conver=90-coiso;
            }
            trem[0][j]=conver;
        }
        for(int j=0;j<50;j++){
            cout<<trem[0][j]<<" ";
        }
    }
}