#include <iostream>
#include <map>
#include <vector>
#include <cstring>
// 
int main()
{
    int r;
    std::cin>>r;
    for(int i=0;i<r;i++){
        int init=0, ares, vert;
        std::map<int, std::vector <int>> *camino= new std::map<int, std::vector<int>>;
        std::string va;
        std::cin>>init;
        // 
        std::cin.clear();
        std::cin.ignore(2147483647,'\n');
        // 
        std::getline(std::cin,va);
        char*split=std::strtok(&va[0]," ");
        for(int j=0;split!=NULL;j++){
            (j==0)?vert=std::stoi(split):ares=std::stoi(split);
            split=std::strtok(NULL," ");
        }
        std::vector< std::vector<int>> matrix(vert);
        for(int j=0;j<vert;j++){
            camino->operator[](j)={};
            matrix.insert(matrix.begin()+j,{j,0,0});
        }
        for(int j=0;j<ares;j++){
            std::string trem;
            int p1,p2;
            std::getline(std::cin,trem);
            char*dividir=std::strtok(&trem[0]," ");
            for(int k=0;dividir!=NULL;k++){
                (k==0)?p1=std::stoi(dividir):p2=std::stoi(dividir);
                dividir=std::strtok(NULL," ");
            }
            camino->operator[](p1).push_back(p2);
            camino->operator[](p2).push_back(p1);
        }
        auto saul=[&matrix, camino, init]()->int{
            int dis=1, e1=0, posi=init, palpite,p=0;
            bool andar, caminhos_dis;
            std::vector<int> v;
            matrix[posi][2]=1;
            matrix[posi][1]=-1;
            while(true){
                ++p;
                v=camino->at(posi);
                for(auto k:v){
                    andar =matrix[k][2]==0;
                    (matrix[k][1]==0)?matrix[k][1]=dis:matrix[k][1];
                    if(andar){
                        posi=k;
                        break;
                    }
                }
                if(andar){
                    ++dis;
                    matrix[posi][2]=1;
                } else{
                    --dis;
                    palpite=matrix[posi][1];
                    v=camino->at(posi);
                    for(auto k:v){
                        if(matrix[k][1]<palpite){
                            palpite=matrix[k][1];
                            posi=k;
                        }
                    }
                    for(auto k:camino->at(posi)){
                        caminhos_dis=matrix[k][2]==0;
                    }
                    if(posi==init&&caminhos_dis==false){
                        break;
                    }
                }
            }
            return p;
        };
        int lala=saul();
        std::cout<<lala<<std::endl;
        delete camino;
        camino=NULL;
        matrix.clear();
    }
    return 0;
}