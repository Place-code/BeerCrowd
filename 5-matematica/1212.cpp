#include <iostream>
#include <cstring>
// 
int main()
{
    while(true){
        std::string ns,*mum=new std::string[2];
        std::getline(std::cin,ns);
        char*split=std::strtok(&ns[0]," ");
        for(int i=0;split!=NULL;i++){
            mum[i]=split;
            split=strtok(NULL," ");
        }
        if(mum[0]=="0"&&mum[1]=="0"){
            break;
        }
        // 
        auto carry=[mum]()->int{
            int siz, subir=0, tem=0, el_camino=0, loc=0;
            bool um_maior=true;
            if(mum[0].length()>=mum[1].length())
            {
                siz=mum[1].length();
                um_maior=false;
            }else{
                siz=mum[0].length();
            }
            for(int i=0;i<2;i++){
                for(int j=0;j<int(mum[i].length()/2);j++){
                    char *ax = new char[1];
                    ax[0]=mum[i][mum[i].length()-j-1];
                    mum[i][mum[i].length()-j-1]=mum[i][j];
                    mum[i][j]=ax[0];
                    delete[] ax;
                    ax=NULL;
                }
            }
            for(int i=0;i<siz;i++){
                (mum[1][i]-'0'+mum[0][i]-'0'+tem>9)?tem=1:tem=0;
                (tem!=0)?subir++:subir;
                ++el_camino;
            }
            (um_maior)?loc=1:loc=0;
            while(tem==1){
                if(el_camino>mum[loc].length()){break;}
                (mum[loc][el_camino]-'0'+tem>9)?tem=1:tem=0;
                (tem!=0)?subir++:subir;
                ++el_camino;
            }
            return subir;
        };
        auto x=carry();
        if(x==0){
            std::cout<<"No carry operation."<<std::endl;
        } else if(x==1){
            std::cout<<"1 carry operation."<<std::endl;
        } else{
            std::cout<<x<<" carry operations."<<std::endl;
        }
        delete[] mum;
        mum=NULL;
    }
    return 0;
}