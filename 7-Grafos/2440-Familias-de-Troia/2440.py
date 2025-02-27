def dfs(graph):
    visited, stack = set(), []
    counter = 0
    for node in graph:
        if node not in visited:
            counter += 1
            stack.append(node)
            while stack:
                v = stack.pop()
                if v not in visited:
                    visited.add(v)
                    stack.extend(reversed(graph[v]))
    return counter

nvertices, nedges = input().split()
nvertices, nedges = int(nvertices), int(nedges)
graph = {}
for i in range(1, nvertices + 1):
    graph.update({i : []})
for i in range (nedges):
    vertex, neighbor = input().split()
    vertex, neighbor = int(vertex), int(neighbor)
    graph[vertex].append(neighbor)
    graph[neighbor].append(vertex)
print(dfs(graph))