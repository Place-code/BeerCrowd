#include<iostream>
#include<cstring>
#include<vector>
// 
int main(){
    std::string inp;
    char*split;
    std::vector<std::string>*mapa;
    bool em;
    int v[2],xyp[3],posi[2],quant;
    for(;;){
        std::getline(std::cin,inp);
        split=new char;
        split=std::strtok(&inp[0]," ");
        for(int i=0;split!=NULL;++i){
            (i<2)?v[i]=std::atoi(split):v[i];
            split=std::strtok(NULL," ");
        }
        if(v[0]==0&&v[1]==0){
            break;
        }
        quant=0;
        inp.clear();
        mapa=new std::vector<std::string>(v[0]);
        for(int i=0;i<v[0];++i){
            std::getline(std::cin,inp);
            mapa->operator[](i)=inp;
            if(inp.find('N')|inp.find('S')|inp.find('O')|inp.find('L')){
                char*l;
                for(int j=0;j<inp.length();++j){
                    l=&inp[j];
                    if(std::isalpha(int(inp[j]))){
                        (*l=='O')?xyp[2]=2:(*l=='L')?xyp[2]=4:(*l=='N')?xyp[2]=1:xyp[2]=3;
                        xyp[0]=j;
                        xyp[1]=i;
                        break;
                    }
                }
            }
            inp.clear();
        }
        inp.clear();
        std::getline(std::cin,inp);
        for(int i=0;i<inp.length();++i){
            if(inp[i]=='D'){
                --xyp[2];
                (xyp[2]<1)?xyp[2]+=4:xyp[2];
            } else if(inp[i]=='E'){
                ++xyp[2];
                (xyp[2]>4)?xyp[2]-=4:xyp[2];
            } else if(inp[i]=='F'){
                int*p=&xyp[2];
                if(*p==1|*p==3){
                    (*p==1)?posi[1]=-1:posi[1]=1;
                    posi[0]=1;
                } else if(*p==2|*p==4){
                    (*p==2)?posi[1]=-1:posi[1]=1;
                    posi[0]=0;
                }
                xyp[posi[0]]+=posi[1];
                // std::cout<<posi[1]<<std::endl;
                // std::cout<<xyp[0]<<" "<<xyp[1]<<" "<<xyp[2]<<" "<<inp[i]<<std::endl;
                if(xyp[0]>v[1]-1|xyp[1]<0|xyp[1]>v[0]-1|xyp[0]<0){
                    (posi[1]==-1)?xyp[posi[0]]+=1:xyp[posi[0]]-=1;
                } else if(mapa->operator[](xyp[1]).at(xyp[0])=='#'){
                    (posi[1]==-1)?xyp[posi[0]]+=1:xyp[posi[0]]-=1;
                } else if(mapa->operator[](xyp[1]).at(xyp[0])=='*'){
                    ++quant;
                    mapa->operator[](xyp[1]).at(xyp[0])='.';
                }
            }
            // std::cout<<xyp[0]<<" "<<xyp[1]<<" "<<xyp[2]<<" "<<inp[i]<<std::endl;
        }
        std::cout<<quant<<std::endl;
        delete mapa;
        delete split;
        mapa=NULL;
        split=NULL;
    }
    return 0;
}