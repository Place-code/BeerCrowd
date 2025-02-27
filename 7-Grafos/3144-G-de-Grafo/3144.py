class Graph:
    def __init__(self, V):
        self.V = V
        self.graph = []
    
    def add(self, edge):
        self.graph.append(edge)
    
    def find(self, parent, i):
        if parent[i] == i:
            return i
        return self.find(parent, parent[i])

    def unite(self, parent, rank, root_x, root_y):
        if rank[root_x] < rank[root_y]:
            parent[root_x] = root_y
        elif rank[root_x] > rank[root_y]:
            parent[root_y] = root_x
        else:
            parent[root_y] = root_x
            rank[root_x] += 1

    def kruskal(self):
        self.graph = sorted(self.graph, key=lambda item : item[2])
        result, parent, rank = 0, [], []
        for node in range(self.V):
            parent.append(node)
            rank.append(0)
        e, i = 0, 0
        while e < self.V - 1:
            u, v, weight = self.graph[i]
            i += 1
            x, y = self.find(parent, u), self.find(parent, v)
            if x != y:
                result += weight
                self.unite(parent, rank, x, y)
                e += 1
        return result

V, E = input().split()
input()
g = Graph(int(V))
for i in range(int(E)):
    u, v, weight = input().split()
    g.add([int(u)-1, int(v)-1, int(weight)])
print(g.kruskal()*2)