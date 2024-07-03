#include <iostream>
#include <vector>
// 
int main()
{
    int n,p;
    auto ener=[](int nn,int par)->int{
        int andar=0;
        std::vector<int> mm;
        bool ment=true;
        while(ment){
            for(int i=0;i<nn;i++){
                mm.push_back(i+1);
            }
            for(int i=0;i<nn;i++){
                // std::cout<<mm[andar]<<" ";
                (i==nn-1 && mm[andar]==13)?ment=false:ment;
                if(i!=nn-1 && mm[andar]==13){
                    // std::cout<<i;
                    break;
                }
                mm.erase(mm.begin()+andar);
                for(int j=1;j<=par;j++){
                    andar++;
                    (andar>=mm.size())?andar-=mm.size():andar;
                }
            }
            (ment)?par++:par;
            // std::cout<<std::endl;
            // std::cout<<mm.size()<<std::endl;
            // std::cout<<mm[andar]<<" "<<par<<std::endl;
            mm.clear();
            andar=0;
        }
        std::cout<<par+1<<std::endl;
        return par;
    };
    ener(100000,0);
    return 0;
}