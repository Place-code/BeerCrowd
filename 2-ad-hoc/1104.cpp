#include<iostream>
#include<vector>
//
int main(){
    std::vector<std::vector<int>>*cartas;
    char*split;
    int v[2]={1,1},*v_atual,*v_ant,*e1,*e2,tot,op[2];
    while(std::cin>>v[0]>>v[1]&&v[0]!=0&&v[1]!=0){
        cartas=new std::vector<std::vector<int>>(2);
        for(int j=0;j<2;++j){
            v_ant=new int(0);
            v_atual=new int;
            for(int i=0;i<v[j];++i){
                std::cin>>*v_atual;
                if(*v_atual!=*v_ant){cartas->operator[](j).insert(cartas->operator[](j).end(),*v_atual);}
                *v_ant=*v_atual;
            }
            delete v_ant;
            delete v_atual;
        }
        if(cartas->operator[](0).size()<=cartas->operator[](1).size()){
            op[0]=0;
            op[1]=1;
        } else{
            op[1]=0;
            op[0]=1;
        }
        e1=new int(cartas->operator[](op[0]).size()-1);
        e2=new int(cartas->operator[](op[1]).size()-1);
        tot=0;
        for(;*e1>=0&&*e2>=0;){
            if(cartas->operator[](op[0])[*e1]<cartas->operator[](op[1])[*e2]){
                --*e2;
                for(*e2;cartas->operator[](op[0])[*e1]<cartas->operator[](op[1])[*e2]&&*e2>=0;--*e2){}
                if(cartas->operator[](op[0])[*e1]!=cartas->operator[](op[1])[*e2]){
                    ++tot;
                    --*e1;
                } else{
                    --*e1;
                    --*e2;
                }
            } else if(cartas->operator[](op[0])[*e1]>cartas->operator[](op[1])[*e2]){
                for(*e1;cartas->operator[](op[0])[*e1]>cartas->operator[](op[1])[*e2]&&*e1>=0;--*e1){
                    ++tot;
                }
                if(cartas->operator[](op[0])[*e1]>cartas->operator[](op[1])[*e2]){
                    ++tot;
                } else if(cartas->operator[](op[0])[*e1]==cartas->operator[](op[1])[*e2]){
                    --*e1;
                    --*e2;
                }
            } else{
                --*e1;
                --*e2;
            }   
        }
        std::cout<<tot+*e1+1<<std::endl;
        delete e1,e2;
        e1=e2=NULL;
    }
    return 0;
}