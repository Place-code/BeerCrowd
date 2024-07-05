#include <iostream>
#include <vector>
#include <map>
#include <cstring>
// 
int main()
{
    int n_n=0;
    std::string trem;
    std::cin>>n_n;
    std::vector<std::vector<int>> li(n_n);
    // 
    std::cin.clear();
    std::cin.ignore(2147483647,'\n');
    // 
    for(int i=0;i<n_n;i++){
        std::getline(std::cin,trem);
        char*split=std::strtok(&trem[0]," ");
        for(int j=0;j<n_n;j++){
            li[i].push_back(std::stoi(split));
            split=std::strtok(NULL," ");
        }
    }
    auto contar=[li,n_n]()->std::vector<std::map<int, int>>{
        std::vector<std::map<int,int>> palavrao(3);
        int s1,s2,s3=0,e;
        // Linha por linha
        for(int i=0;i<n_n;i++){
            s1=0,s2=0,e=0;
            for(auto j:li[i]){
                s1+=j;
                (e==i)?s3+=j:s3;
                ++e;
            }
            for(int j=0;j<n_n;j++){
                s2+=li[j][i];
            }
            palavrao[0].insert(std::pair<int,int>(i,s1));
            palavrao[1].insert(std::pair<int,int>(i,s2));
        }
        palavrao[2].insert(std::pair<int,int>(s3,s3));
        return palavrao;
    };
    auto vv=contar();
    vv.erase(vv.end());
    int palpite, v1, v2=0,cor[3],e=0;
    // for(auto i:vv){
    //     for(auto j:i){
    //         std::cout<<j.first<<" "<<j.second<<std::endl;
    //     }
    // }
    for(auto i:vv){
        for(auto j:i){
            palpite=-1;
            v1=j.second;
            for(auto k:i){
                (k.second==v1)?++palpite:--palpite;
            }
            if(palpite<0){
                cor[e]=j.first;
                cor[2]=v1;
                ++e;
                break;
            } else{
                v2=j.second;
            }
        }
    }
    std::cout<<v2-(v1-li[cor[0]][cor[1]])<<" "<<li[cor[0]][cor[1]]<<std::endl;
    return 0;
}