#include <iostream>
#include <set>
#include <utility>

int main() {
    int V, E, start, cases;
    std::pair <int, int> edge1, edge2;
    std::cin>>cases;
    for (int i = 0; i < cases; ++i) {
        std::cin>>start;
        std::cin>>V>>E;
        std::set<std::pair<int, int>> graph;
        for (int j = 0; j < E; ++j) {
            std::cin>>edge1.first>>edge1.second;
            edge2.first = edge1.second; edge2.second = edge1.first;
            graph.insert(edge1);
            graph.insert(edge2);
        }
        std::cout<<graph.size()<<"\n";
    }
    return 0;
}