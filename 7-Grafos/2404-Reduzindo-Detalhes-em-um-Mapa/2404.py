class Graph:
    def __init__(self, V):
        self.V = V
        self.graph = []

    def add(self, u, v, weight):
        self.graph.append([u, v, weight])

    def find (self, parent, i):
        if parent[i] == i:
            return i
        return self.find(parent, parent[i])

    def unite (self, parent, rank, x, y):
        root_x = self.find(parent, x)
        root_y = self.find(parent, y)
        if rank[root_x] < rank[root_y]:
            parent[root_x] = root_y
        elif rank[root_x] >= rank[root_y]:
            parent[root_y] = root_x
        else:
            parent[root_y] = root_x
            rank[root_x] += 1

    def kruskal(self):
        result = 0
        self.graph = sorted(self.graph, key=lambda item : item[2])
        parent = []
        rank = []
        for node in range(self.V):
            parent.append(node)
            rank.append(0)
        edges, index = 0, 0
        while edges < self.V - 1:
            u, v, weight = self.graph[index]
            index += 1
            x, y = self.find(parent, u), self.find(parent, v)
            if x != y:
                result += weight
                self.unite(parent, rank, x, y)
                edges += 1
        return result

V, E = input().split()
V, E = int(V), int(E)
graph = Graph(V)
for i in range (E):
    u, v, weight = input().split()
    graph.add(int(u)-1, int(v)-1, int(weight))
print(graph.kruskal())