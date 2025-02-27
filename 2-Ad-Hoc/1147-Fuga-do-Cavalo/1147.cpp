#include <iostream>

int main() {
    int knight[2], pawns[8][2], mov[8][2], qnt = 0, cases = 0;
    char input[3];
    while (1) {
        std::cin>>input;
        if (input[0] == '0') {
            break;
        }
        ++cases;
        knight[0] = input[0]-48;
        knight[1] = input[1]-96;
        for (int i = 0; i < 8; ++i) {
            std::cin>>input;
            pawns[i][0] = input[0]-48;
            pawns[i][1] = input[1]-96;
        }
        mov[0][0] = knight[0] - 2;
        mov[0][1] = knight[1] - 1;
        mov[1][0] = knight[0] - 1;
        mov[1][1] = knight[1] - 2;
        mov[2][0] = knight[0] + 1;
        mov[2][1] = knight[1] - 2;
        mov[3][0] = knight[0] + 2;
        mov[3][1] = knight[1] - 1;
        mov[4][0] = knight[0] + 2;
        mov[4][1] = knight[1] + 1;
        mov[5][0] = knight[0] + 1;
        mov[5][1] = knight[1] + 2;
        mov[6][0] = knight[0] - 2;
        mov[6][1] = knight[1] + 1;
        mov[7][0] = knight[0] - 1;
        mov[7][1] = knight[1] + 2;
        for (int i = 0; i < 8; ++i) {
            if (mov[i][0] > 0 && mov[i][1] > 0 && mov[i][0] < 9 && mov[i][1] < 9) {
                ++qnt;
                for (int q = 0; q < 8; ++q) {
                   if ((mov[i][0] + 1 == pawns[q][0] && mov[i][1] + 1 == pawns[q][1]) || (mov[i][0] + 1 == pawns[q][0] && mov[i][1] - 1 == pawns[q][1])) --qnt;
                }
            }
        }
        std::cout<<"Caso de Teste #"<<cases<<": "<<qnt<<" movimento(s).\n";
        qnt = 0;
    }
    return 0;
}