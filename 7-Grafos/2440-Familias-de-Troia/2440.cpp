#include <iostream>
#include <vector>

void dfs(std::vector<bool> &visited, const std::vector<std::vector<int>> &graph, int node) {
    visited[node] = true;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) dfs(visited, graph, neighbor);
    }
}

int main() {
    int vertices, edges, u, v, counter = 0;
    std::cin>>vertices>>edges;
    std::vector<std::vector<int>> graph(vertices);
    std::vector<bool> visited(vertices, false);
    for (int i = 0; i < edges; ++i) {
        std::cin>>u>>v;
        --u; --v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for (int i = 0; i < vertices; ++i) {
        if (!visited[i]) {
            ++counter;
            dfs(visited, graph, i);
        }
    }
    std::cout<<counter<<"\n";

    return 0;
}