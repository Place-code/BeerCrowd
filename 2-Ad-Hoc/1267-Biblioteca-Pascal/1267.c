#include <stdio.h>
#include <stdbool.h>

int main() {
    int width, height, cnt;
    while (1) {
        bool filled = false;
        scanf ("%d %d", &width, &height);
        if (width == 0 && height == 0) break;
        int matrix[height][width];
        for (int i = 0; i < height; ++i) {
            for (int q = 0; q < width; ++q) {
                scanf("%d", &matrix[i][q]);
            }
        }
        for (int column = 0; column < width; ++column) {
            cnt = 0;
            for (int row = 0; row < height; ++row) {
                if (matrix[row][column] == 1) {
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
        (filled) ? printf ("yes\n") : printf ("no\n");   
    }
    return 0;
}
