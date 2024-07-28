#include<iostream>
#include<cstring>
#include <map>
#include <vector>
// 
int main(){
    std::string inp,root;
    int r,bin;
    char*split,*divi;
    std::map<char,std::vector<char>>*tree;
    std::vector<std::string>*no;
    std::cin>>r;
    // 
    std::cin.clear();
    std::cin.ignore(2147483647,'\n');
    // 
    for(int i=0;i<r;++i){
        tree=new std::map<char,std::vector<char>>;
        no=new std::vector<std::string>;
        split=new char;
        std::getline(std::cin,inp);
        split=std::strtok(&inp[0]," ");
        for(int j=0;split!=NULL;++j){
            if(j>0){
                no->push_back(split);
            }
            split=std::strtok(NULL," ");
        }
        // 
        for(auto j:*no){
            for(char k:j){
                tree->insert(tree->end(),std::pair<char,std::vector<char>>(k,{}));
            }
        }
        divi=new char;
        divi=std::strtok(&no[1][0][0],&no[0][0][0]);
        for(int i=0;divi!=NULL;++i){
            root=divi;
            bin=0;
            for(auto cc:root){
                ++bin;
                
            }
        }
        delete divi;
        divi=NULL;
        // for(auto treco:*tree){
        //     std::cout<<treco.first<<" ";
        //     for(char bgl:treco.second){
        //         std::cout<<bgl<<" ";
        //     }
        //     std::cout<<std::endl;
        // }
        delete tree,split,no;
        tree=NULL;
        no=NULL;
        split=NULL;
    }
    return 0;
}