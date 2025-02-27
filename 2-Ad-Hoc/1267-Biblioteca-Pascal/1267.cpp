#include <iostream>

int main() {
    int width, height, cnt;
    bool filled;
    while (1) {
        filled = false;
        std::cin>>width>>height;
        if (width == 0 && height == 0) break;
        int matriz[height][width];
        for (int i = 0; i < height; ++i) {
            for (int q = 0; q < width; ++q) {
                std::cin>>matriz[i][q];
            }    
        }
        for (int column = 0; column < width; ++column) {
            cnt = 0;
            for (int row = 0; row < height; ++row) {
                if (matriz[row][column] == 1) {
                    ++cnt;
                }
                else {
                    break;
                }
            }
            if (cnt == height) {
                filled = true;
                break;
            }
        }
        (filled) ? std::cout<<"yes\n" : std::cout<<"no\n";
    }
    return 0;
}