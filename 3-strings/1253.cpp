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
        string cesar=" ";
        int coiso=0, e=0;
        getline(cin,cesar);
        cin>>coiso;
        // 
        cin.clear();
        cin.ignore(2147483647, '\n');
        // 
        for(int j=0;j<cesar.length();j++){
            int conver=int(cesar[j])-coiso;
            if(conver<65){
                int pasos=int(cesar[j])-65+1;
                conver=90-(coiso-pasos);
            }
            cout<<char(conver);
        }
        cout<<"\n";
    }
    return 0;
}