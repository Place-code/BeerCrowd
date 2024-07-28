#include <iostream>
#include <cstring>
#include <vector>
// 
int main(){
    int epa,tot,h_pas,m_pas;
    std::string inp;
    std::vector<std::vector<int>> valor;
    char *split;
    while(true){
        epa=0;
        tot=0;
        std::getline(std::cin,inp);
        split=std::strtok(&inp[0]," ");
        valor.push_back({});
        for(int i=0;split!=NULL;++i){
            valor[valor.size()-1].push_back(std::atoi(split));
            if(*split=='0'){
                ++epa;
            }
            if(valor[valor.size()-1].size()>1){
                valor.push_back({});
            }
            split=std::strtok(NULL," ");
        }
        if(epa>3){
            break;
        }
        h_pas=valor[1][0]-valor[0][0];
        (h_pas<0)?h_pas+=23:h_pas;
        m_pas=valor[1][1]-valor[0][1];
        if(m_pas<0){
            m_pas+=60;
            --h_pas;
        }
        std::cout<<h_pas*60+m_pas<<std::endl;
        valor.clear();
        inp.clear();
    }
    return 0;
}