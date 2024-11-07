#include <iostream>

int main() {
    
    int ddd;
    std::cin>>ddd;
    if (ddd == 61) {
        std::cout<<"Brasilia"<<std::endl;
    }
    else if (ddd == 71) {
        std::cout<<"Salvador"<<std::endl;
    }
    else if (ddd == 11) {
        std::cout<<"Sao Paulo"<<std::endl;
    }
    else if (ddd == 21) {
        std::cout<<"Rio de Janeiro"<<std::endl;
    }
    else if (ddd == 32) {
        std::cout<<"Juiz de Fora"<<std::endl;
    }
    else if (ddd == 19) {
        std::cout<<"Campinas"<<std::endl;
    }
    else if (ddd == 27) {
        std::cout<<"Vitoria"<<std::endl;
    }
    else if (ddd == 31) {
        std::cout<<"Belo Horizonte"<<std::endl;
    }
    else {
        std::cout<<"DDD nao cadastrado"<<std::endl;
    }
    return 0;
}