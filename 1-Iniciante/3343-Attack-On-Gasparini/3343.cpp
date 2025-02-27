#include <iostream>
#include <string>

int main() {
    int n, x, hit, len = 1;
    std::string Sattacks;
    std::cin>>n>>x>>Sattacks;
    int damage[3], attacks[n], walls[n], indexes[] = {0, 0, 0};
    walls[0] = x;
    for (int i = 0; i < n; ++i) {
        if (Sattacks[i] == 'P') {
            attacks[i] = 0;
        }
        else if (Sattacks[i] == 'M') {
            attacks[i] = 1;
        }
        else {
            attacks[i] = 2;
        }
    }
    std::cin>>damage[0]>>damage[1]>>damage[2];
    for (int i = 0; i < n; ++i) {
        hit = damage[attacks[i]];
        while (walls[indexes[attacks[i]]] < hit) {
            ++indexes[attacks[i]];
            if (indexes[attacks[i]] == len) {
                walls[len] = x;
                ++len;
            }
        }
        walls[indexes[attacks[i]]] -= hit;
    }
    std::cout<<len<<"\n";
    return 0;
}