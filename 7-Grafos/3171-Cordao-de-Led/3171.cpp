#include <iostream>
#include <vector>

void dfs (std::vector<int>& visited, std::vector<std::vector<int>> graph, int node) {
    visited.push_back(node);
    for (int neighbor : graph[node]) {
        if (std::count(visited.begin(), visited.end(), neighbor) == 0) dfs(visited, graph, neighbor);
    }
}

int main() {
    int vertices, edges, u, v;
    std::cin>>vertices>>edges;
    std::vector<int> visited;
    std::vector<std::vector<int>> graph(vertices);
    for (int i = 0; i < edges; ++i) {
        std::cin>>u>>v;
        graph[u-1].push_back(v-1);
        graph[v-1].push_back(u-1);
    }
    dfs(visited, graph, 0);
    visited.size() == vertices ? std::cout<<"COMPLETO\n" : std::cout<<"INCOMPLETO\n";
    return 0;
}