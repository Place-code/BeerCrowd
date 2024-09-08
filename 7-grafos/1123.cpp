#include<iostream>
#include<vector>
#include<map>
#include<cstring>
// 
int main(){
    int v[4];
    std::vector<std::vector<int>>*info;
    std::map<std::string,std::vector<std::string>>*camino;
    std::string inp;
    char*split;
    while(true){
        std::getline(std::cin,inp);
        split=new char;
        split=std::strtok(&inp[0]," ");
        for(int i=0;split!=NULL;++i){
            v[i]=std::atoi(split);
            split=std::strtok(NULL," ");
        }
        if(v[0]==0&&v[1]==0&&v[2]==0&&v[3]==0){
            break;
        }
        std::vector<int>tam(v[0]);
        info=new std::vector<std::vector<int>>(v[0],tam);
        camino=new std::map<std::string,std::vector<std::string>>;
        for(int i=0;i<v[0];++i){
            camino->insert(camino->end(),std::pair<std::string,std::vector<std::string>>(std::to_string(i),{}));
        }
        for(int i=0;i<v[1];++i){
            delete split;
            split=NULL;
            split=new char;
            inp.clear();
            std::getline(std::cin,inp);
            split=std::strtok(&inp[0]," ");
            int *d=(int*)calloc(3,sizeof(int));
            for(int j=0;split!=NULL;++j){
                d[j]=std::atoi(split);
                split=std::strtok(NULL," ");
            }
            // 
            info->operator[](d[1]).at(d[0])=d[2];
            info->operator[](d[0]).at(d[1])=d[2];
            // 
            camino->operator[](std::to_string(d[0])).push_back(std::to_string(d[1]));
            camino->operator[](std::to_string(d[1])).push_back(std::to_string(d[0]));
            free(d);
        }
        std::cout<<"======"<<std::endl;
        for(auto bgl:*camino){
            std::cout<<bgl.first<<" ";
            for(auto trens:bgl.second){
                std::cout<<trens<<" ";
            }
            std::cout<<std::endl;
        }
        std::cout<<std::endl;
        for(auto j:*info){
            for(int k:j){
                std::cout<<k<<" ";
            }
            std::cout<<std::endl;
        }
        std::cout<<"======"<<std::endl;
        auto caminhao=[v,camino,info]()->int{
            int e,di;
            std::string or_des[2];
            or_des[0]=std::to_string(v[3]);
            or_des[1]=std::to_string(v[2]-1);
            std::vector<int>pedagio;
            bool pode;
            std::map<std::string,std::vector<std::string>>fila;
            fila.insert(std::pair<std::string,std::vector<std::string>>(or_des[0],{}));
            pedagio.push_back(0);
            while(fila.size()>0){
                e=0;
                for(auto index:fila){
                    for(int i=0;i<camino->operator[](index.first).size();++i){
                        for(auto j:fila){
                            std::cout<<j.first<<" ";
                            for(auto k:j.second){
                                std::cout<<k<<" ";
                            }
                            std::cout<<std::endl;
                        }
                        pode=true;
                        if(index.first!=or_des[1]|std::stoi(index.first)>std::stoi(or_des[1])){
                            for(std::string ana:index.second){
                                if(ana==camino->operator[](index.first).at(i)){
                                    pode=false;
                                } else{
                                    pode=true;
                                    break;
                                }
                            }
                        } else if(index.first==or_des[1]){
                            pode=false;
                        }
                        if(pode){
                            pedagio[e]+=info->operator[](std::stoi(index.first)).at(std::stoi(camino->operator[](index.first).at(i)));
                            fila[index.first].push_back(index.first);
                            if(std::stoi(index.first)<std::stoi(or_des[1])){
                                auto mover=fila.extract(index.first);
                                mover.key()=std::to_string(std::stoi(index.first)+1);
                                fila.insert(std::move(mover));
                                break;
                            }else if(i<0){
                                auto mover=fila.extract(index.first);
                                mover.key()=camino->operator[](index.first).at(i);
                                std::cout<<camino->operator[](index.first).at(i)<<std::endl;
                                fila.insert(std::move(mover));
                            } else if(i>0){
                                fila.insert(fila.end(),std::pair<std::string,std::vector<std::string>>(camino->operator[](index.first).at(i),index.second));
                                pedagio.push_back(pedagio[e]);
                            }
                        } else{
                            fila.erase(index.first);
                        }
                    }
                    std::cout<<"====="<<std::endl;
                    ++e;
                }
            }
            return 0;
        };
        caminhao();
        delete camino;
        delete info;
        camino=NULL;
        info=NULL;
    }
    return 0;
}