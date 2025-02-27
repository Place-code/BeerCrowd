#include <iostream>
#include <vector>
#include <algorithm>

int dfs (const std::vector<std::vector<int>>& graph, std::vector<std::vector<int>>& connected, int V) {
    std::vector<bool> visited(V, false);
    std::vector<int> stack;
    int node, index = -1;
    for (int j = 0; j < V; ++j) {
        if (!visited[j]) {
            ++index;
            stack.push_back(j);
            while (stack.size() > 0) {
                node = stack[stack.size()-1];
                stack.pop_back();
                if (!visited[node]) {
                    connected[index].push_back(node);
                    visited[node] = true;
                    for (int neighbor : graph[node]) {
                        stack.push_back(neighbor);
                    }
                }
            }
        }
    }
    return index;
}

int main() {
    int V, E, cases, index;
    char u[2], v[2];
    std::cin>>cases;
    for (int i = 0; i < cases; ++i) {
        std::cin>>V>>E;
        std::vector<std::vector<int>> graph(V);
        std::vector<std::vector<int>> connected(V);
        for (int j = 0; j < E; ++j) {
            std::cin>>u>>v;
            u[0] -= 97; v[0] -= 97;
            graph[u[0]].push_back(v[0]);
            graph[v[0]].push_back(u[0]);   
        }
        index = dfs(graph, connected, V);
        std::cout<<"Case #"<<i+1<<":\n";
        for (int j = 0; j <= index; ++j) {
            std::sort(connected[j].begin(), connected[j].end());
            for (int el : connected[j]) {
                std::cout<<(char)(el+97)<<",";
            }
            std::cout<<"\n";
        }
        std::cout<<index+1<<" connected components\n\n";
    }
    return 0;
}