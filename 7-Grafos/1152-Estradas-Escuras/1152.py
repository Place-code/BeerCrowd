class Graph:
    def __init__(self, vertices):
        self.graph = []
        self.sumweight = 0
        self.V = vertices
        
    def add(self, u, v, weight):
        self.graph.append([u, v, weight])
        self.sumweight += weight
        
    def find(self, parent, i):
        if parent[i] == i:
            return i
        return self.find(parent, parent[i])
    
    def unite (self, parent, rank, Xroot, Yroot):
        if rank[Xroot] < rank[Yroot]:
            parent[Xroot] = Yroot
        elif rank[Xroot] > rank[Yroot]:
            parent[Yroot] = Xroot
        else:
            parent[Yroot] = Xroot
            rank[Xroot] += 1
            
    def kruskal(self):
        self.graph = sorted(self.graph, key=lambda item : item[2])
        parent, rank, result = [], [], 0
        for node in range(self.V):
            parent.append(node)
            rank.append(0)
        e, i = 0, 0
        while e < self.V - 1:
            u, v, weight = self.graph[i]
            x = self.find(parent, u)
            y = self.find(parent, v)
            i += 1
            if x != y:
                self.unite(parent, rank, x, y)
                result += weight
                e += 1
        return self.sumweight-result
        
while (True):       
    V, E = input().split()
    V, E = int(V), int(E)
    if V == E == 0:
        break
    roads = Graph(V)
    for i in range (E):
        u, v, weight = input().split()
        roads.add(int(u), int(v), int(weight))
    print (roads.kruskal())