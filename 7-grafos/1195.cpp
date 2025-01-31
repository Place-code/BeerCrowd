#include<iostream>
#include<queue>
//
struct Nodos{
    int info;
    Nodos*esq,*dir;
    Nodos(int dado){
        info=dado;
        esq=dir=NULL;
    }
};
Nodos*insert(Nodos*vasculhar,int comp){
    if(vasculhar==nullptr){
        return new Nodos(comp);
    }
    if(vasculhar->info>comp){
        vasculhar->esq=insert(vasculhar->esq,comp);
    } else{
        vasculhar->dir=insert(vasculhar->dir,comp);
    }
    return vasculhar;
}
//
void pre_fixo(Nodos*nu,std::queue<int>*f){
    if(nu==nullptr){
        return;
    }
    f->push(nu->info);
    pre_fixo(nu->esq,f);
    pre_fixo(nu->dir,f);
}
//
void inoder(Nodos*nu,std::queue<int>*f){
    if(nu!=NULL){
        inoder(nu->esq,f);
        f->push(nu->info);
        inoder(nu->dir,f);
    }
}
//
void pos_fixo(Nodos*nu,int tam){
    if(nu==nullptr){
        return;
    }
    pos_fixo(nu->esq,tam+1);
    pos_fixo(nu->dir,tam+1);
    if(tam==0){
        std::cout<<nu->info<<"\n";
        return;
    }
    std::cout<<nu->info<<" ";
}
//
int main(){
    int r,loops,inp;
    std::cin>>r;
    for(int re=0;re<r;++re){
        std::queue<int>fila;
        Nodos*algo;
        std::cin>>loops;
        for(int i=0;i<loops;++i){
            std::cin>>inp;
            if(i==0){
                algo=new Nodos(inp);
            } else{
                algo=insert(algo,inp);
            }
        }
        std::cout<<"Case "<<re+1<<":\n";
        pre_fixo(algo,&fila);
        std::cout<<"Pre.: ";
        for(int i=0;i<loops-1;++i){
            std::cout<<fila.front()<<" ";
            fila.pop();
        }
        std::cout<<fila.front()<<"\n";
        fila.pop();
        inoder(algo,&fila);
        std::cout<<"In..: ";
        for(int i=0;i<loops-1;++i){
            std::cout<<fila.front()<<" ";
            fila.pop();
        }
        std::cout<<fila.front()<<"\n";
        fila.pop();
        std::cout<<"Post: ";
        pos_fixo(algo,0);
        std::cout<<"\n";
    }
    return 0;
}