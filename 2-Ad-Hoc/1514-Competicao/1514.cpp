#include <iostream>

int main() {
    int height, width, cnt = 0, result;
    bool check1, check2, check3, check4;
    while (1) {
        std::cin>>height>>width;
        if (width == 0 && height == 0) break;
        check1 = true, check2 = true, check3 = true, check4 = true;
        result = 0;
        int matrix[height][width];
        for (int i = 0; i < height; ++i) {
            cnt = 0;
            for (int j = 0; j < width; ++j) {
                std::cin>>matrix[i][j];
                if (matrix[i][j] == 1) {
                    ++cnt;
                }
            }
            if (cnt == width) {
                check1 = false;
            }
            else if (cnt == 0) {
                check4 = false;
            }
        }
        for (int i = 0; i < width; ++i) {
            cnt = 0;
            for (int j = 0; j < height; ++j) {
                if (matrix[j][i] == 1) {
                    ++cnt;
                }
            }
            if (cnt == height) {
                check3 = false;
            }
            else if (cnt == 0) {
                check2 = false;
            }
        }
        if (check1) ++result; 
        if (check2) ++result; 
        if (check3) ++result; 
        if (check4) ++result;
        std::cout<<result<<"\n";
    }
    return 0;
}